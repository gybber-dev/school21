#include "../ft_cub.h"

/*
** Validate parsed data from file:
 * 1. If all data are parsed
 * 2. If the map is valid
 * 3. If map.ismalloced < 0 (means that map was splitted;
 * 4. If paths are correct
*/

static int	map_validator(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || map->c_map[y] == NULL ||
			map->c_map[y][x] == 0)
		return (0);
	if (map->c_map[y][x] == '0')
		map->c_map[y][x] = '6';
	return (
			map_validator(map, x, y - 1) &&
			map_validator(map, x, y + 1) &&
			map_validator(map, x - 1, y + 1) &&
			map_validator(map, x - 1, y - 1));
}

int			ft_validate_data(t_set *set)
{
	t_pix	m;
	int		res;

	if (!set->map.c_map || set->skin.ce_col == -1 || set->skin.fl_col == -1 ||
			!set->win.img1.res.x || !set->win.img1.res.y || !set->skin.ea_ski ||
			!set->skin.we_ski || !set->skin.so_ski || !set->skin.no_ski)
		ft_error(set, ERR_FEW_DATA);
	ft_bzero(&m, sizeof(t_pix));
	res = 1;
	while (set->map.c_map[m.y] != NULL)
	{
		while (set->map.c_map[m.y][m.x] != 0)
		{
			if (set->map.c_map == '0')
				res = map_validator(&set->map, m.x, m.y);
			m.x++;
		}
		m.y++;
	}
	m.y = 0;
	while(set->map.c_map[m.y] != NULL)
	{
		DEBUG printf("[%s]", set->map.c_map[m.y]);
		m.y++;
	}
	return (set->skin.ce_col);
}