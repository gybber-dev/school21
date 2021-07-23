const { HeroType } = require('./model/hero');
const { AbilityType } = require('./model/abilites');
const { State } = require('./model/state');
const { Map } = require('./model/map');
const { Parameters } = require('./model/parameters');
const { Teams } = require('./model/teams');

let game_map = null;
let game_params = null;
let game_teams = null;

let CoreObj = {
    enemyType: 0,
    aims: {},
    my_builds: {},
    groups: [],
    counter: 0,
    total_army: 0,
    flag: 0,
    criticalDistance: 0,
    speedRate: 1,
    firstFlag: 0,
    firstEnemyID: 0,
    firstMyID: 0,
    tick: 0
  }

const Bot = (game, game_teams, game_params, game_map) => {
    try {
    /* Получение состояния игры */
    if (game && game_teams && game_params) {
        const state = new State(game, game_teams, game_params);
        const my_buildings = state.my_buildings();
        const my_squads = state.my_squads();
        const enemy_buildings = state.enemy_buildings();
        const enemy_squads = state.enemy_squads();
        const neutral_buildings = state.neutral_buildings();
        const forges_buildings = state.forges_buildings();
       
        CoreObj.tick = state.state["Tick"];
        // init of data:
        if (!CoreObj.flag)
        {
            console.log(`Maps`)
            console.log(game_map)
            console.log(`PARAMS`)
            
            let aa = JSON.parse(game_params.abilities[0].ability_data);
            CoreObj.speedRate = aa.SpeedModifier;
            CoreObj.firstEnemyID = enemy_buildings[0].id;
            CoreObj.firstMyID = my_buildings[0].id;
            CoreObj.flag = 1;
            // рассчитываем критическую дистанцию.
            let aims = game_map.get_nearest_towers(CoreObj.firstMyID, neutral_buildings);
            CoreObj.criticalDistance = game_map.towers_distance(aims[3].id, CoreObj.firstMyID) || 5;
        }
        
        // first logic:
        if (CoreObj.firstFlag != 5)
            firstLogic(my_buildings, neutral_buildings, enemy_buildings, my_squads, state)
        else{
            // MAIN LOGIC:
            console.log("MAIN LOGIC");

            // Сбросить захваченные цели
            update_aims(CoreObj.aims, CoreObj.my_builds, state);

            apply_abilities(state);
            // get aims:
            my_buildings.forEach(my_building => {
                // если враг слишком близко, атаковать его
                if (!check_nearest_enemy(my_building, enemy_buildings))
                {
                    // Если башня не зайдействована
                    if ( ! CoreObj.my_builds[my_building.id] )
                        single_attack(my_building, enemy_buildings, neutral_buildings)
                }
                
            });
            
            

            // групповая атака
            group_attack(my_buildings, enemy_buildings, neutral_buildings);
            ids = upgrade_towers(my_buildings);
            if (ids.length)
            {
                for (let i = 0; i < ids.length; i++) {
                    const tower_id = ids[i];
                    if (CoreObj.my_builds[tower_id])
                        delete CoreObj.my_builds[tower_id];
                }
            }
        }
        // оценить отправленные цели
        console.log(CoreObj);

    }
  }
  catch (e) {
    console.log(e);
  } finally {
    process.send('end');
  }
};

process.on('message', async (game) => {
  if (game.initial) {
    game_map = new Map(game.data);  // карта игрового мира
    game_params = new Parameters(game.data);  // параметры игры
    game_teams = new Teams(game.data);  // моя команда
  } else
    await Bot(game.data, game_teams, game_params, game_map);
});



function count_per_dist(aim, startPos)
{
    try{

        // определяем расстояние между башнями
        const distance = game_map.towers_distance(startPos.id, aim.id);
        let rate = 1;
        if (CoreObj.firstFlag < 5)
            rate = CoreObj.speedRate;
        // определяем сколько тиков идти до нее со стандартной скоростью
        const ticks = distance / (game_params.creep.speed * rate);
        // определяем прирост башни в соответствии с ее уровнем
        let enemy_creeps = 0;
        if (aim.creeps_count >= aim.level.player_max_count)
        // если текущее количество крипов больше чем положено по уровню
        enemy_creeps = aim.creeps_count;
        else {
            // если меньше - будет прирост
            const grow_creeps = ticks / aim.level.creep_creation_time;
            enemy_creeps = aim.creeps_count + grow_creeps;
            if (enemy_creeps >= aim.level.player_max_count)
                enemy_creeps = aim.level.player_max_count;
        }
        // определяем количество крипов с учетом бонуса защиты
        const enemy_defence = enemy_creeps * (1 + aim.DefenseBonus);
        // если получается в моей башне крипов больше + 10 на червя - идем на врага всей толпой
        
        return enemy_defence + 5;
    } catch (e) {
        console.log('error', e);
        return 10000
    }
}


function check_nearest_enemy(my_building, enemy_buildings)
{
    try{
        if (!my_building || !enemy_buildings)
            return false;
        let sorted_enemy_buildings = game_map.get_nearest_towers(my_building.id, enemy_buildings);
        
        // attack nearest critical enemy:
        let dist = game_map.towers_distance(sorted_enemy_buildings[0], my_building.id);
        
        if (dist && dist < CoreObj.criticalDistance)
        {
            console.log(`Critical enemy: ${sorted_enemy_buildings[0].id} for ${my_building.id} (dist: ${dist})`);
            let count = count_per_dist(sorted_enemy_buildings[0], my_building);
            console.log(`count_per_dist ${count}`);
            sent_army_to_aim(my_building, sorted_enemy_buildings[0], count);
            CoreObj.my_builds[my_building.id] = new MyBuild(my_building.id);
            CoreObj.my_builds[my_building.id].id = my_building.id;
            CoreObj.my_builds[my_building.id].reason = "critical";
            return true;
        }
        return false;
    }catch (e) {
        console.log(e);
        return false;
    }
}




function single_attack(my_building, enemy_buildings, neutral_buildings)
{
    try{
        let towers, builds;
        if (isIterable(neutral_buildings))  builds = [...neutral_buildings];
        if (isIterable(enemy_buildings))    builds = [...builds, ...enemy_buildings];
        towers = game_map.get_nearest_towers(my_building.id, builds);
        // check first 3 towers:
        for (var i = 0; i < towers.length && i < 3; i++)
        {
            let count = count_per_dist(towers[i], my_building);
            console.log(`compare: ${my_building.creeps_count} >= ${count}`);
            if (my_building.creeps_count >= count)
            {
                // ПОСТАВИТЬ НА УЧЕТ!!!!!!
                CoreObj.my_builds[my_building.id] = new MyBuild(my_building.id);
                CoreObj.my_builds[my_building.id].id = my_building.id;
                CoreObj.my_builds[my_building.id].reason = "attack";
                CoreObj.aims[towers[i].id] = new Aim(towers[i].id);
                CoreObj.aims[towers[i].id].id = towers[i].id;
                CoreObj.aims[towers[i].id].need_squads = count;
                CoreObj.aims[towers[i].id].from.push(my_building.id);
                sent_army_to_aim(my_building, towers[i], count)
                break ;
            }
        }
    }catch (e) {
        console.log(e);
    }
}


// групповая атака
function group_attack(my_buildings, enemy_buildings, neutral_buildings)
{
    try{
        random_attack(my_buildings, enemy_buildings, neutral_buildings)
    }catch (e) {
        console.log(e);
    }
}


function group_towers(tower)
{
    try{
        CoreObj.groups.forEach(group => {

        });
        return [];
    }catch (e) {
        console.log(e);
    }
}



function random_attack(my_buildings, enemy_buildings, neutral_buildings)
{
    try{
        var towers, builds, my_building;
        if (isIterable(neutral_buildings))  builds = [...neutral_buildings];
        if (isIterable(enemy_buildings))    builds = [...builds, ...enemy_buildings];
        towers = game_map.get_nearest_towers(my_buildings[0].id, builds);
        var min_dist = game_map.towers_distance(towers[0].id, my_buildings[0].id) || 4;
        var max_count = 0;
        var my_count = 0;

        for (var i = 0; i < my_buildings.length; i++)
        {
            my_building = my_buildings[i];
            console.log(my_buildings.length)
            // максимальное необходимое количество крипов для захвата
            let count = count_per_dist(towers[0], my_building);
            let dist = game_map.towers_distance(towers[0].id, my_building.id);
            if (dist < min_dist * 1.5)
            {
                max_count = (max_count < count) ? count : max_count;
                my_count += my_building.creeps_count;
                console.log(`adds ${my_building.creeps_count} to ${my_count}`)
                console.log(`my ${my_count} > ${max_count} max?`)
                // если отряд вышел, то добавляем его в my_builds
                if (sent_army_to_aim(my_building, towers[0], 50))
                {
                    console.log("check" + my_building);
                    if (!CoreObj.my_builds[my_building.id])
                    {
                        CoreObj.my_builds[my_building.id] = new MyBuild(my_building.id);
                        CoreObj.my_builds[my_building.id].id = my_building.id;
                        CoreObj.my_builds[my_building.id].reason = "attack";
                    }
                    if (!CoreObj.aims[towers[0].id])
                    {
                        CoreObj.aims[towers[0].id] = new Aim(towers[i].id);
                        CoreObj.aims[towers[0].id].id = towers[i].id;
                        CoreObj.aims[towers[0].id].need_squads = count;
                        CoreObj.aims[towers[0].id].from.push(my_building.id);
                    }else{
                        CoreObj.aims[towers[0].id].from.push(my_building.id)
                    }
                }
            }
            if (my_count > max_count)
                break ;

        }
        

    }catch (e) {
        console.log(e);
    }
}

function apply_abilities(state)
{
    try{
        const my_buildings = state.my_buildings();
        const my_squads = state.my_squads();
        const enemy_buildings = state.enemy_buildings();

        // Применение абилки ускорение
        if (my_squads.length > 3) {
            if (state.ability_ready(AbilityType[0])) {
                location = game_map.get_squad_center_position(my_squads[2]);
                process.send(game_teams.my_her.speed_up(location));
            }
        }

        // Чума
        if (state.ability_ready(AbilityType[5])) {
            let max_count = 0;
            let id = enemy_buildings[0].id;
            enemy_buildings.forEach(enemy_building => {
                if (enemy_building.creeps_count > max_count && !CoreObj.aims[enemy_building.id])
                {
                    max_count = enemy_building.creeps_count;
                    id = enemy_building.id;
                }
            });
            console.log(`plague to enem(${max_count})`);
            process.send(game_teams.my_her.plague(id));
        }

        // Обмен
        if (state.ability_ready(AbilityType[6])) {
            let max_count = 0;
            let min_count = 100;
            let enemy_id = enemy_buildings[0].id;
            let my_id = my_buildings[0].id;
            enemy_buildings.forEach(enemy_building => {
                if (enemy_building.creeps_count > max_count && !CoreObj.aims[enemy_building.id])
                {
                    max_count = enemy_building.creeps_count;
                    enemy_id = enemy_building.id;
                }
            });
            my_buildings.forEach(my_building => {
                if (my_building.creeps_count < min_count)
                {
                    min_count = my_building.creeps_count;
                    my_id = my_building.id;
                }
            });
            console.log(`change my(${min_count}) to enem(${max_count})`);
            process.send(game_teams.my_her.exchange(enemy_id, my_id));
        }
        

    }catch (e) {
        console.log(e);
    }
}



function upgrade_towers(my_buildings)
{
    try{
        var ids = []
        my_buildings.forEach(my_building => {
            // Upgrade башни
            if (my_buildings[0].level.id < game_params.tower_levels.length - 1) {
                // Если хватает стоимости на upgrade
                const update_coast = game_params.get_tower_level(my_buildings[0].level.id + 1).update_coast;
                if (update_coast < my_buildings[0].creeps_count) {
                    process.send(game_teams.my_her.upgrade_tower(my_buildings[0].id));
                    my_buildings[0].creeps_count -= update_coast;
                    ids.push(my_building.id);
                }
            }
        });
        return ids;
    }catch (e) {
        console.log(e);
        return ids;
    }
}
function sample()
{
    try{
        if (my_squads.length > 4) {
            if (state.ability_ready(AbilityType[0])) {
                location = game_map.get_squad_center_position(my_squads[3]);
                process.send(game_teams.my_her.speed_up(location));
            }
        }
    }catch (e) {
        console.log(e);
    }
}

function firstLogic(my, neutral, enemy, my_squads, state)
{
    try{
        var my_tower = get_tower_by_id(my, CoreObj.firstMyID) || 
                        get_tower_by_id(my, CoreObj.firstEnemyID);
        console.log(my_tower);
        // STEP 0 - 1
        if (CoreObj.firstFlag == 0 && my_tower)
        {
            console.log("s0-1");
            let aims = game_map.get_nearest_towers(my_tower.id, neutral)
            // let count = count_per_dist(aims[0], my_tower);
            process.send(game_teams.my_her.move(my_tower.id, aims[0].id, 0.6));
            process.send(game_teams.my_her.move(my_tower.id, enemy[0].id, 0.4));
            CoreObj.firstFlag = 1;
        }
        

        // ALWAYS
        // Применение абилки ускорение
        if (my_squads.length > 4) {
            if (state.ability_ready(AbilityType[0])) {
                location = game_map.get_squad_center_position(my_squads[3]);
                process.send(game_teams.my_her.speed_up(location));
            }
        }
        if (CoreObj.firstFlag == 3 || CoreObj.tick >= 200)
            CoreObj.firstFlag = 5;


        // STEP 1 - 2
        if (CoreObj.firstFlag == 1 && my_tower.creeps_count < 3){
            console.log("s1-2");
            if (state.ability_ready(AbilityType[6]))
            {
                process.send(game_teams.my_her.exchange(CoreObj.firstEnemyID, CoreObj.firstMyID));
                CoreObj.firstFlag = 2;
            }
        }
        // STEP 2 - 3
        // my base build became the enemy's
        isChanged = get_tower_by_id(enemy, CoreObj.firstMyID);
        if (CoreObj.firstFlag == 2 && isChanged)
        {
            console.log("is chuma is available? " + state.ability_ready(AbilityType[5]))
            // проверяем доступность абилки Чума
            if (state.ability_ready(AbilityType[5])) {
                process.send(game_teams.my_her.plague(isChanged.id));
            }
            CoreObj.firstFlag = 3;
        }
    }catch (e) {
        console.log(e)
    }
}



function sent_army_to_aim(start_pos, end_pos, my_count)
{
    try{
        if (start_pos && end_pos && start_pos.creeps_count > 6)
        {
            let count = my_count || (end_pos.creeps_count + 5)
            if (start_pos.creeps_count * 0.25 > count)
                process.send(game_teams.my_her.move(start_pos.id, end_pos.id, 0.25));
            else if (start_pos.creeps_count * 0.5 > count)
                process.send(game_teams.my_her.move(start_pos.id, end_pos.id, 0.5));
            else if (start_pos.creeps_count * 0.75 > count)
                process.send(game_teams.my_her.move(start_pos.id, end_pos.id, 0.75));
            else 
                process.send(game_teams.my_her.move(start_pos.id, end_pos.id, 1));
            return true;
        }
        return false;
    }catch (e) {
        console.log(e)
    }
}

function get_tower_by_id(towers, id)
{
    try{
        for (var i = 0; i < towers.length; i++)
        {
            if (towers[i].id == id)
                return towers[i];
        }    
        return undefined;
    }catch (e) {
        console.log(e);
        console.log("errr");
    }
}

function isIterable(obj) {
    // checks for null and undefined
    if (obj == null) {
      return false;
    }
    return typeof obj[Symbol.iterator] === 'function';
  }


function Aim(id){
    this.id = id;
    this.total_squads = 0;
    this.need_squads = 0;
    this.link = null;
    this.from = [];
}
function MyBuild(id){
    this.id = id;
    this.reason = 0;
}


/**
   * Удаляет захваченные башни из списка целей
   * Обновляет значения total_squads и need_squads
   * Подсчитывает количество total_army
   * @param {*} aims 
   * @param {*} state 
   */
 function update_aims(aims, my_builds, state)
 {
    console.log("UPDATE AIMS")
    try{
        const my_buildings = state.my_buildings();
        const enemy_buildings = state.enemy_buildings();
        if (Object.keys(aims))
        {
            my_buildings.forEach(my_building => {
                if (aims[my_building.id])
                {
                    console.log(`\taim[${my_building.id}] is our!`)
                    // оставляем только те id, которых нет в aims
                    for (tower_id in aims[my_building.id].from)
                    {
                        if (my_building[tower_id] !== undefined)
                            if (my_builds[aims[my_building.id].from].reason == 'attack')
                                delete my_builds[tower_id];
                    }
                    delete aims[my_building.id];
                }
                // CoreObj.total_army += my_building.creeps_count;
            });
        }
        // удалить потерянные башни
        if (Object.keys(my_builds))
        {
            enemy_buildings.forEach(enemy_building => {
                if (my_builds[enemy_building.id])
                {
                    delete my_builds[enemy_building.id];
                }
            });

        }

        // удалить зависшие башни
        if (Object.keys(my_builds))
        {
            my_buildings.forEach(my_building => {
                if (my_builds[my_building.id] && my_building.creeps_count >= 10)
                {
                    delete my_builds[enemy_building.id];
                }
            });

        }
    }catch(e){
        console.log("ERROR in upd");
        console.log(CoreObj);
        console.log(e);
    }
   return ;
 }