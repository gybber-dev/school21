const { HeroType } = require('./model/hero');
const { AbilityType } = require('./model/abilites');
const { State } = require('./model/state');
const { Map } = require('./model/map');
const { Parameters } = require('./model/parameters');
const { Teams } = require('./model/teams');
const dist = require('node-gzip');

let game_map = null;
let game_params = null;
let game_teams = null;

let FLAG = 0;


function Aim(id){
    this.id = id;
    this.total_squads = 0;
    this.need_squads = 0;
    this.link = null;
}

let CoreObj = {
    aims: {},
    counter: 0,
    total_army: 0,
  }
const Bot = (game, game_teams, game_params, game_map) => {
  const MIN_COUNT_FOR_ATTACK = 10;
  const WORM_NYAM = 5;
  
  /**
   * Возвращает! количество крипов на карте идущих к цели id
   * @param {*} id 
   * @param {*} squads 
   */
  function count_squads_on_map_for(id, squads) {
    console.log("COUNT AIM\n" + squads.length);
    let result = 0;
    try{
      if (squads.length)
      {
        squads.forEach(squad => {
          if (squad.ToId == id)
          {
            console.log(`\tsquad id [${squad.Id}] to [${squad.ToId}]`);
            result += squad.CreepsCount;
          }
        });
      }
    }catch(e)
    {
      console.log("ERROR");
      console.log(e);
    }
    console.log(`\ttotal squads to [${id}] is [${result}]`);
    return result;
  }
  function chooseNeutralTower (my_buildings, neutral_buildings)
  {
    try{
      console.log("NEUTRAL_BUILDS:\n" + CoreObj.counter);
      
      // attack_1x1(my_buildings[0], neutral_buildings[0]);
      console.log(`my_building[${my_buildings.length}]\nneutral_buildings[${neutral_buildings.length}]`);
      // Рассчитать количество войск в моей башне
      // my_buildings.forEach(my_building => {
      //   neutral_buildings.forEach(neutral_building => {
      //     const dist = get_distance(my_building.id, neutral_building.id, game_map);
      //     console.log(`${my_building.id}\t>\t${neutral_building.id}\t\t${dist}`);
      //   });
      // });
      for (let i = 0; i < my_buildings.length; i++) {
        const my_building = my_buildings[i];
        if (my_building.creeps_count <= MIN_COUNT_FOR_ATTACK)
          continue ;
        let dist;
        var min_id = neutral_buildings[0].id;
        var min_dist = 500;
        let min_index = 0;
        for (let j = 0; j < neutral_buildings.length; j++) {
          const neutral_building = neutral_buildings[j];
          if (my_building.creeps_count > neutral_building.creeps_count)
          {
            dist = get_distance(my_building.id, neutral_building.id, game_map);
            console.log(`${my_building.id}: dist[${dist}] min[${min_dist}]`);
            if (dist < min_dist)
            {
              min_dist = dist;
              min_id = neutral_building.id;
              min_index = j;
              console.log(`\tmin is ${dist} on ${min_id}`);
            }
          }
        }



        const ticks = min_dist / game_params.creep.speed;
        let enemy_creeps = 0;
        console.log("ANALISE TOWER: " + min_dist + " id " + min_id);
        if (neutral_buildings[min_index].creeps_count >= neutral_buildings[min_index].level.player_max_count)
          // если текущее количество крипов больше чем положено по уровню
          enemy_creeps = neutral_buildings[min_id].creeps_count;
        else {
          // если меньше - будет прирост
          const grow_creeps = ticks / neutral_buildings[min_index].level.creep_creation_time;
          enemy_creeps = neutral_buildings[min_index].creeps_count + grow_creeps;
          if (enemy_creeps >= neutral_buildings[min_index].level.player_max_count)
            enemy_creeps = neutral_buildings[min_index].level.player_max_count;
        }
        console.log(`ENEMY CREEPS [${enemy_creeps}] on [${min_id}] in {${ticks} ticks} vs my[${my_building.creeps_count}]`);
        // определяем количество крипов с учетом бонуса защиты
        const enemy_defence = enemy_creeps * (1 + neutral_buildings[min_index].DefenseBonus);       
        // если получается в моей башне крипов больше + WORM_NYAM на червя - идем на врага всей толпой
        console.log(`ENEMY DEFENCE [${enemy_defence}] on [${min_id}] in {${ticks} ticks} vs my[${my_building.creeps_count}]`);
        if (enemy_defence + WORM_NYAM < my_building.creeps_count)
        {
          console.log(`from ${my_building.id}[${my_building.creeps_count}] to ${min_id} dist is ${min_dist}`);
          // if new Aim:
          if (!CoreObj.aims[min_id])
          {
            CoreObj.aims[min_id] = new Aim(min_id);
            CoreObj.aims[min_id].id = min_id;
            CoreObj.aims[min_id].obj = min_id;
          }
          process.send(game_teams.my_her.move(my_building.id, min_id, 1));
        }
      }
    }catch(e)
    {
      console.log("ERROR");
      console.log(e);
    }
  }

/**
 * Выбирается ближайшая башня, к которой можно подтянуть наибольшее количество войск
 * @param {*} my_buildings 
 * @param {*} state 
 */
  function choose_next_tower(my_buildings, neutral_buildings, enemy_buildings, forges_buildings)
  {
    function isIterable(obj) {
      // checks for null and undefined
      if (obj == null) {
        return false;
      }
      return typeof obj[Symbol.iterator] === 'function';
    }
    try{
      console.log("NEXT AIM");
      
      let towers;
      if (isIterable(neutral_buildings))  towers = [...neutral_buildings];
      if (isIterable(enemy_buildings))    towers = [...towers, ...enemy_buildings];
      // if (isIterable(forges_buildings))   towers = [...towers, ...forges_buildings];
      let val = 0;
      let tower_id;
      let tower_link;
      towers.forEach(tower => {
        let val_i = 0;
        for (let i = 0; i < my_buildings.length; i++) {
          const my_building = my_buildings[i];
          val_i += my_building.creeps_count/get_distance(my_building.id, tower.id, game_map);
        }
        if ((val_i > val) && (CoreObj.total_army > tower.creeps_count) && tower.id)
        {
          console.log(`\tval is updated[${val_i}]`);
          val = val_i;
          tower_id = tower.id;
          tower_link = tower;
        }
      });
      if (tower_id){
        console.log(`\tval is [${val}] on tower[${tower_id}]`);
        CoreObj.aims[tower_id] = new Aim(tower_id);
        CoreObj.aims[tower_id].id = tower_id;
        CoreObj.aims[tower_id].link = tower_link;
      }
    }catch(e)
    {
      console.log("ERROR in choose");
      console.log(e);
    }
  }

  /**
   * Удаляет захваченные башни из списка целей
   * Обновляет значения total_squads и need_squads
   * Подсчитывает количество total_army
   * @param {*} aims 
   * @param {*} state 
   */
  function update_aims(aims, state)
  {
    console.log("UPDATE AIMS")
    try{
      if (Object.keys(aims))
      {
        const my_buildings = state.my_buildings();
        my_buildings.forEach(my_building => {
          if (aims[my_building.id])
          {
            console.log(`\taim[${my_building.id}] is our!`)
            delete aims[my_building.id];
          }
          CoreObj.total_army += my_building.creeps_count;
        });
        for (aim in aims)
        {
          aims[aim].need_squads = aims[aim].link.creeps_count;
          aims[aim].total_squads = count_squads_on_map_for(aim, state.state.squadStates);
        }
      }
    }catch(e){
      console.log("ERROR in upd");
      console.log(CoreObj);
      console.log(e);
    }
    return ;
  }

  /**
   * Отправляем все доступные войска в к башне id
   */
  function sent_squads_to(id, my_buildings)
  {
    console.log("SEND ARMY TO " + id)
    try{
      my_buildings.forEach(my_building => {
        if (my_building.creeps_count > MIN_COUNT_FOR_ATTACK)
        {
          console.log(`\tarmy was sent to [${id}] from`);
          console.log(my_building);
          process.send(game_teams.my_her.move(my_building.id, id, 1));
        }
      });
    }catch(e){
      console.log("ERROR in sent");
      console.log(e);
    }
  }

  try {
    /* Получение состояния игры */
    if (game && game_teams && game_params) {
      const state = new State(game, game_teams, game_params);
      const my_buildings = state.my_buildings();
      const my_squads = state.my_squads();
      
      
      // if (CoreObj.counter == 30)
      // {
      //   console.log("======STATE===========");
      //   console.log(state.state.squadStates);
      //   console.log(CoreObj);
      //   return ;
      // }
      // getState(game, game_teams, game_params, game_map);

      // сортируем по остаточному пути
      my_squads.sort((a, b) => {
        if (a.way.left > b.way.left) {
          return 1;
        }
        if (a.way.left < b.way.left) {
          return -1;
        }
        return 0;
      });

      const enemy_buildings = state.enemy_buildings();
      const enemy_squads = state.enemy_squads();
      const neutral_buildings = state.neutral_buildings();
      const forges_buildings = state.forges_buildings();
      /* Играем за воина */
      if (game_teams.my_her.hero_type === HeroType.Warrior) {
        // проверяем доступность абилки Крик
        if (state.ability_ready(AbilityType[3]))
        {
          if (enemy_buildings.length > 0)
            process.send(game_teams.my_her.growl(chooseTowerForAbility(enemy_buildings)));
        }


        // обновить активные цели:
        update_aims(CoreObj.aims, state);
        // есть ли активные цели?
        if (Object.keys(CoreObj.aims).length)
        {
          console.log(`Есть активные цели [${Object.keys(CoreObj.aims).length}]:\n\t${Object.keys(CoreObj.aims)}`)
          // Достаточно ли войск для каждой цели?
          let is_norm = true;
          for (aim in CoreObj.aims)
          {
            if (CoreObj.aims[aim].total_squads > CoreObj.aims[aim].need_squads)
            {
              // is_norm
            }else{
              // выделить еще
              sent_squads_to(aim, my_buildings);
              is_norm = false;
            }
          }
          if (is_norm)
          {
            choose_next_tower(my_buildings, neutral_buildings, enemy_buildings, forges_buildings);
          }
        }else{
          choose_next_tower(my_buildings, neutral_buildings, enemy_buildings, forges_buildings);
        }

        // проверяем доступность абилки Берсерк
        if (state.ability_ready(AbilityType[2])) {
          // для эффективности повышаем площадь, применяем на 5 отрядах
          if (my_squads.length > 5) {
            // сколько тиков первому отряду осталось до башни
            const left_to_aim = my_squads[0].way.left / my_squads[0].speed;
            // Если первый отряд находится в зоне инициализации абилки
            const berserk_parameters = game_params.get_ability_parameters(AbilityType[2]);
            if (berserk_parameters.cast_time + 50 > left_to_aim) {
              location = game_map.get_squad_center_position(my_squads[2]);
              process.send(game_teams.my_her.berserk(location));
            }
          }
        }
      }

      // Применение абилки ускорение
      if (my_squads.length > 4) {
        if (state.ability_ready(AbilityType[0])) {
          location = game_map.get_squad_center_position(my_squads[2]);
          process.send(game_teams.my_her.speed_up(location));
        }
      }
    }
  }
  catch (e) {
    console.log('error', e);
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


function get_distance(id1, id2, game_map)
{
  let dist = 0;
  // определяем расстояние между башнями
  dist = game_map.towers_distance(id1, id2);
  return dist;
}




function chooseTowerForAbility(enemy_buildings)
{
  let id = 0;
  let max_count = 0;

  try{
    console.log("CHOOSE FROM: " + enemy_buildings.length);
    for (let i = 0; i < enemy_buildings.length; i++) {
      if (enemy_buildings[i].creeps_count > max_count)
      {
        max_count = enemy_buildings[i].creeps_count;
        id = enemy_buildings[i].id;
      }
    }
  }catch(e){
  }
  return id;
}