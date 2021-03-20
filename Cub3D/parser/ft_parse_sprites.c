#include "../ft_cub.h"

void				ft_parse_sprites(t_set *set)
{
	t_pix		m;

	ft_bzero(&m, sizeof(t_pix));
	while (set->map.c_map[m.y] != NULL)
	{
		m.x = 0;
		while (set->map.c_map[m.y][m.x] != 0)
		{
			m.x++;
		}
		m.y++;
	}
}