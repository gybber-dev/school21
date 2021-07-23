from model.hero import *
from model.map import Map
from model.parameters import Parameters
from model.state import State
from model.abilites import AbilityType
from model.teams import Teams
import json
import random
import time

import logging
import sys

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
eprint("hello")

logging.basicConfig(filename='example.log', encoding='utf-8', level=logging.DEBUG)
logging.debug('This message should go to the log file')

game = json.loads(input())
game_map = Map(game)  # карта игрового мира
game_params = Parameters(game)  # параметры игры
game_teams = Teams(game)  # моя команда
while True:
    try:
        """ Получение состояния игры """
        state = State(input(), game_teams, game_params)
        my_buildings = state.my_buildings()
        my_squads = state.my_squads()
        # сортируем по остаточному пути
        my_squads.sort(key=lambda c: c.way.left, reverse=False)
		
        enemy_buildings = state.enemy_buildings()
        enemy_squads = state.enemy_squads()

        neutral_buildings = state.neutral_buildings()

        forges_buildings = state.forges_buildings()
        """ Играем за мага """
        if game_teams.my_her.hero_type == HeroType.Mag:
            # проверяем доступность абилки Обмен башнями
            if state.ability_ready(AbilityType.Build_exchange):
                # если враг применил абилку обмен башнями
                build_exchange = state.enemy_active_abilities(AbilityType.Build_exchange)
                if len(build_exchange) > 0:
                    print(game_teams.my_her.exchange(enemy_buildings[0].id, my_buildings[0].id))
                else:
                    if my_buildings[0].creeps_count < 10:
                        print(game_teams.my_her.exchange(enemy_buildings[0].id, my_buildings[0].id))

            # проверяем доступность абилки Чума
            if state.ability_ready(AbilityType.Plague):
                # для эффективности применяем ближе к башне
                if len(my_squads) > 1:
                    # сколько тиков первому отряду осталось до башни
                    left_to_aim = my_squads[0].way.left / my_squads[0].speed
                    # если первый отряд находится в зоне инициализации абилки
                    plague_parameters = game_params.get_ability_parameters(AbilityType.Plague)
                    if plague_parameters.cast_time + 30 > left_to_aim:
                        print(game_teams.my_her.plague(enemy_buildings[0].id))

            # атакуем башню противника
            for my_building in my_buildings:
                if my_building.creeps_count > my_building.level.player_max_count:
                    print(game_teams.my_her.move(my_building.id, enemy_buildings[0].id, 1))

       
            # # Upgrade башни
            # if my_buildings[0].level.id < len(game_params.tower_levels) - 1:
            #     # Если хватает стоимости на upgrade
            #     update_coast = game_params.get_tower_level(my_buildings[0].level.id + 1).update_coast
            #     if update_coast < my_buildings[0].creeps_count:
            #         print(game_teams.my_her.upgrade_tower(my_buildings[0].id))
            #         my_buildings[0].creeps_count -= update_coast

            # # Атакуем башню противника
            # # определяем расстояние между башнями
            # distance = game_map.towers_distance(my_buildings[0].id, enemy_buildings[0].id)
            # # определяем сколько тиков идти до нее со стандартной скоростью
            # ticks = distance / game_params.creep.speed
            # # определяем прирост башни в соответствии с ее уровнем
            # enemy_creeps = 0
            # if enemy_buildings[0].creeps_count >= enemy_buildings[0].level.player_max_count:
            #     # если текущее количество крипов больше чем положено по уровню
            #     enemy_creeps = enemy_buildings[0].creeps_count
            # else:
            #     # если меньше - будет прирост
            #     grow_creeps = ticks / enemy_buildings[0].level.creep_creation_time
            #     enemy_creeps = enemy_buildings[0].creeps_count + grow_creeps
            #     if enemy_creeps >= enemy_buildings[0].level.player_max_count:
            #         enemy_creeps = enemy_buildings[0].level.player_max_count
            # # определяем количество крипов с учетом бонуса защиты
            # enemy_defence = enemy_creeps * (1 + enemy_buildings[0].DefenseBonus)
            # # если получается в моей башне крипов больше + 10 на червя - идем на врага всей толпой
            # if enemy_defence + 10 < my_buildings[0].creeps_count:
            #     print(game_teams.my_her.move(my_buildings[0].id, enemy_buildings[0].id, 1))
         
			# Применение абилки ускорение
			# if len(my_squads) > 4:
			# 	if state.ability_ready(AbilityType.Speed_up):
			# 		location = game_map.get_squad_center_position(my_squads[2])
			# 		print(game_teams.my_her.speed_up(location))

    except Exception as e:
        print(str(e))
    finally:
        """ Требуется для получения нового состояния игры  """
        print("end")
