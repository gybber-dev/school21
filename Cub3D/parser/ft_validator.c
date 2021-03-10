/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:16:58 by yeschall          #+#    #+#             */
/*   Updated: 2021/03/10 19:17:01 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub.h"

static void		default_map(char **map)
{
	t_pix		m;

	ft_bzero(&m, sizeof(t_pix));
	while (map[m.y])
	{
		m.x = 0;
		while (map[m.y][m.x])
		{
			if (map[m.y][m.x] == '5')
				map[m.y][m.x] = '0';
			if (map[m.y][m.x] == '7')
				map[m.y][m.x] = '2';
			m.x++;
		}
		m.y++;
	}
}

/*
** Validate parsed data from file:
** 1. If all data are parsed
** 2. If the map is valid
*/

static int		map_validator(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || map->c_map[y] == NULL ||
			map->c_map[y][x] == 0 || map->c_map[y][x] == ' ')
		return (0);
	if (map->c_map[y][x] == '1' || map->c_map[y][x] == '5' ||
			map->c_map[y][x] == '7' || map->c_map[y][x] == 'P')
		return (1);
	if (map->c_map[y][x] == '0')
		map->c_map[y][x] = '5';
	if (map->c_map[y][x] == '2')
		map->c_map[y][x] = '7';
	if (ft_strchr("NEWS", map->c_map[y][x]))
	{
		map->player_counter++;
		map->player_dir = map->c_map[y][x];
		map->pos = v_set(x, y);
		map->c_map[y][x] = '5';
	}
	return (
			map_validator(map, x, y - 1) &&
			map_validator(map, x, y + 1) &&
			map_validator(map, x - 1, y) &&
			map_validator(map, x + 1, y));
}

int				ft_validate_data(t_set *set)
{
	t_pix		m;
	int			res;

	(!set->map.c_map) ? ft_error(set, ERR_FEW_DATA) : 0;
	ft_bzero(&m, sizeof(t_pix));
	res = 1;
	while (set->map.c_map[m.y] != NULL && res)
	{
		m.x = 0;
		while (set->map.c_map[m.y][m.x] != 0)
		{
			if (ft_strchr("NEWS02", set->map.c_map[m.y][m.x]))
				res = map_validator(&set->map, m.x, m.y);
			if (!res)
				break ;
			m.x++;
		}
		m.y++;
	}
	if (set->map.player_counter > 1)
		ft_error(set, ERR_PLAYERS);
	if (!res)
		ft_error(set, ERR_MAP);
	default_map(set->map.c_map);
	return (res);
}
