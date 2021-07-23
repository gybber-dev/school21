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

function Aim(id){
    this.id = id;
    this.total_squads = 0;
    this.need_squads = 0;
    this.link = null;
}

function Under_attack(id, count){
  this.id = id;
  this.count = count;
  this.critical = false;
}

let CoreObj = {
    aims: {},
    counter: 0,
    total_army: 0,
    under_attack: {},
  }
const Bot = (game, game_teams, game_params, game_map) => {
  const MIN_COUNT_FOR_ATTACK = 8;
  const WORM_NYAM = 5;
  
  /**
   * Возвращает! количество крипов на карте идущих к цели id
   * @param {*} id 
   * @param {*} squads 
   */
  function count_squads_on_map_for(id, squads) {
    // console.log("COUNT AIM\n" + squads.length);
    let result = 0;
    try{
      if (squads.length)
      {
        squads.forEach(squad => {
          if (squad.ToId == id)
          {
            // console.log(`\tsquad id [${squad.Id}] to [${squad.ToId}]`);
            result += squad.CreepsCount;
          }
        });
      }
    }catch(e)
    {
      // console.log("ERROR");
      // console.log(e);
    }
    // console.log(`\ttotal squads to [${id}] is [${result}]`);
    return result;
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
      // console.log("NEXT AIM");
      
      let towers;
      if (isIterable(neutral_buildings))  towers = [...neutral_buildings];
      if (isIterable(enemy_buildings))    towers = [...towers, ...enemy_buildings];
      // Только в конце!?
      if (!towers.length)
        if (isIterable(forges_buildings))   towers = [...towers, ...forges_buildings];
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
          // console.log(`\tval is updated[${val_i}]`);
          val = val_i;
          tower_id = tower.id;
          tower_link = tower;
        }
      });
      if (tower_id){
        // console.log(`\tval is [${val}] on tower[${tower_id}]`);
        CoreObj.aims[tower_id] = new Aim(tower_id);
        CoreObj.aims[tower_id].id = tower_id;
        CoreObj.aims[tower_id].link = tower_link;
      }
    }catch(e)
    {
      // console.log("ERROR in choose");
      // console.log(e);
    }
  }

  // Upgrade башни
  function upgrade_towers(my_buildings, game_params)
  {
    // console.log("UPDATE TOWERS");
    try{
      if (CoreObj.counter <= 300)
      {
        // console.log("\tNO");
        return ;
      }
      // console.log("\tOK");
      my_buildings.forEach(my_building=>{
        // Добавить условие:

        if (my_building.level.id < game_params.tower_levels.length - 1) {
          // Если хватает стоимости на upgrade и на нее не нападают:
          const update_coast = game_params.get_tower_level(my_building.level.id + 1).update_coast;
          if (update_coast < my_building.creeps_count && !CoreObj.under_attack[my_building.id]) {
            process.send(game_teams.my_her.upgrade_tower(my_building.id));
            my_building.creeps_count -= update_coast;
          }
        }
      });
    }catch(e){
    //   console.log("ERROR in upgrade");
    //   console.log(e);
    }
  }
  /**
   * Удаляет захваченные башни из списка целей
   * Обновляет значения total_squads и need_squads
   * Подсчитывает количество total_army
   * Сброс если целей больше 2
   * @param {*} aims 
   * @param {*} state 
   */
  function update_aims(aims, state)
  {
    // console.log("UPDATE AIMS " + Object.keys(aims).length)
    try{
      if (Object.keys(aims))
      {
        if (Object.keys(aims).length > 2)
        {
          aims = {};
          return ;
        }
        const my_buildings = state.my_buildings();
        my_buildings.forEach(my_building => {
          if (aims[my_building.id])
          {
            // console.log(`\taim[${my_building.id}] is our!`)
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
      // console.log("ERROR in upd");
      // console.log(CoreObj);
      // console.log(e);
    }
    return ;
  }

  /**
   * Оценивает количество врагов, идущих к моей башне. Если башен мало, забить, нужно развиваться
   */
  function analyze_enemy(enemy_squads, my_buildings){
    // console.log("ANALYZE ENEMY " + enemy_squads.length);
    // Если башен мало, забить, нужно развиваться
    if (my_buildings.length <= 3)
      return ;
    let under_attack = false;
    let counter = 0;
    try {
      if (enemy_squads.length)
      {
        my_buildings.forEach(my_building =>{
          enemy_squads.forEach(enemy_squad => {
            if (enemy_squad.to_id == my_building.id)
            {
              // console.log(`\ttower [${my_building.id}] is under attack!!!!!`);
              under_attack = true;
              counter += enemy_squad.creeps_count;
            }
          });
        if (under_attack && (my_building.creeps_count < counter)){
          CoreObj.under_attack[my_building.id] = new Under_attack();
          CoreObj.under_attack[my_building.id].id = my_building.id;
          CoreObj.under_attack[my_building.id].counter = my_building.id;
          CoreObj.under_attack[my_building.id].critical = true;
        }
        if (!under_attack && CoreObj.under_attack[my_building.id])
        {
          // console.log("\tALARM OFF");
          delete CoreObj.under_attack[my_building.id];
        }
        under_attack = false;
        counter = 0;
        });
      }
    }catch(e){
      // console.log("ERROR in analyze enemy");
      // console.log(e);
    }
  }


  /**
   * Отправляем все доступные войска в к башне id
   */
  function sent_squads_to(id, my_buildings)
  {
    // console.log("SEND ARMY TO " + id)
    try{
      my_buildings.forEach(my_building => {
        if (my_building.creeps_count > MIN_COUNT_FOR_ATTACK)
        {
          if (CoreObj.under_attack[my_building.id])
          {
            // console.log(`\tFreeze! You're under attack!`);
          }else{
            // console.log(`\tarmy was sent to [${id}] from`);
            // console.log(my_building);
            process.send(game_teams.my_her.move(my_building.id, id, 1));
          }
        }
      });
    }catch(e){
      // console.log("ERROR in sent");
      // console.log(e);
    }
  }

  try {
    /* Получение состояния игры */
    if (game && game_teams && game_params) {
      const state = new State(game, game_teams, game_params);
      const my_buildings = state.my_buildings();
      const my_squads = state.my_squads();
      CoreObj.counter++;
      
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

        // на меня напали?
        analyze_enemy(enemy_squads, my_buildings);

        // обновить активные цели:
        update_aims(CoreObj.aims, state);
        // есть ли активные цели?
        if (Object.keys(CoreObj.aims).length)
        {
          // console.log(`Есть активные цели [${Object.keys(CoreObj.aims).length}]:\n\t${Object.keys(CoreObj.aims)}`)
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
      // Активировать "застоявшиеся" башни
      try{
        // console.log("FORCE ACTIVE");
        my_buildings.forEach(my_building => {
          if (my_building.creeps_count > MIN_COUNT_FOR_ATTACK && !CoreObj.under_attack[my_building.id])
          {
            // console.log("\tOK");
            let to_attack = true;
            // for (tower in CoreObj.under_attack)
            // {
            //   if (tower.critical)
            //   {
            //     process.send(game_teams.my_her.move(my_building.id, tower.id, 1));
            //     to_attack = false;
            //     break ;
            //   }
            // }
            if (to_attack)
            {
              // добавить новую цель
              choose_next_tower(my_buildings, neutral_buildings, enemy_buildings, forges_buildings);
            }
          }
        });
      }catch(e)
      {
        // console.log("ERROR in force");
        // console.log(e);
      }

      // Upgrade башни
      upgrade_towers(my_buildings, game_params)
    }
  }
  catch (e) {
    // console.log('error', e);
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
    // console.log("CHOOSE FROM: " + enemy_buildings.length);
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