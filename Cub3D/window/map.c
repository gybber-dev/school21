#include "../ft_cub.h"


static void		scale_pix(t_set *set, t_pix *pix)
{
	t_pix	p;
	t_pix	end;

	p.x = SCALE * pix->x;
	p.y = SCALE * pix->y;
	end.x = p.x + SCALE - 1;
	end.y = p.y + SCALE - 1;
	while (p.y <= end.y)
	{
		p.x = SCALE * pix->x;
		while (p.x <= end.x)
		{
			my_mlx_pixel_put(set, p.x, p.y, 0xFFFFFF);
			p.x++;
		}
		p.y++;
	}
}

void		draw_map(t_set *set)
{
	t_pix	pix;

	DEBUG printf("DRAW THE MAP: %s\n", *(set->map.c_map));
	ft_bzero(&pix, sizeof(t_pix));
	while (set->map.c_map[pix.y])
	{
		pix.x = 0;
		while (set->map.c_map[pix.y][pix.x])
		{
			if (set->map.c_map[pix.y][pix.x] == '1')
//				my_mlx_pixel_put(set, pix.x, pix.y, 0xFFFFFF);
				scale_pix(set, &pix);
			pix.x++;
		}
		pix.y++;
	}
}