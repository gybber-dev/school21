#include "../ft_cub.h"

void				set_sprites(t_set *set)
{
	t_pix		m;
	t_spr		spr;
	int			i;

	i = 0;
	ft_bzero(&m, sizeof(t_pix));
	if (!(set->sprs = (t_spr *)malloc(set->sprites * sizeof(t_spr))))
		ft_error(set, errno);
	while (set->map.c_map[m.y] != NULL)
	{
		m.x = 0;
		while (set->map.c_map[m.y][m.x] != 0)
		{
			if (set->map.c_map[m.y][m.x] == '2')
			{
				spr.pos.x = m.x + 0.5;
				spr.pos.y = m.y + 0.5;
//				spr.xlim = v_set(-1, -1);
				spr.dist = -1;
				set->sprs[i] = spr;
				i++;
			}
			m.x++;
		}
		m.y++;
	}

}