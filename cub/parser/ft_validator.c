#include "../ft_cub.h"

/*
** Validate parsed data from file:
 * 1. If all data are parsed
 * 2. If the map is valid
 * 3. If map.ismalloced < 0 (means that map was splitted;
 * 4. If paths are correct
*/

int			ft_validate_data(t_set *set)
{
	t_pix	m;

	if (!set->map.c_map || set->skin.ce_col == -1 || set->skin.fl_col == -1 ||
			!set->win.img1.res.x || !set->win.img1.res.y || !set->skin.ea_ski ||
			!set->skin.we_ski || !set->skin.so_ski || !set->skin.no_ski)
		ft_error(set, ERR_FEW_DATA);
	ft_bzero(&m, sizeof(t_pix));
	while (set->map.c_map[m.y] != NULL)
	{
		while (set->map.c_map[m.y][m.x] != 0)
		{
			if (set->map.c_map == )
			m.x++;
		}
		m.y++;
	}
	return (set->skin.ce_col);
}