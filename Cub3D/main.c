#include "ft_cub.h"
#include <string.h>
//#include "minilibx_opengl_20191021/mlx.h"


static void				init_set(t_set *set)
{
	set->map.c_map = NULL;
	set->map.ismalloced = 0;
	set->win.mlx = NULL;
	set->win.win = NULL;
}

void		scale_pix(t_set *set, t_pix *pix)
{
	DEBUG printf("SCALE: x: %d, y: %d\n", pix->x, pix->y);

	t_pix	p;

	p.x = SCALE * (pix->x + 1);
	p.y = SCALE * (pix->y + 1);
	while (pix->y < p.y)
	{
//		printf("%d: [", p.y);
		while (pix->x < p.x)
		{
			mlx_pixel_put(set->win.mlx, set->win.win, pix->x++, pix->y, 0xFFFFFF);
//			printf("%d", p.x);
//			p.x++;
		}
		pix->x -= SCALE;
//		printf("]\n");
		p.y++;
	}

}

void		draw_map(t_set *set)
{
	t_pix	pix;
	char		**row;
//	char		*i;


	row = set->map.c_map;



	printf("check\n");
	DEBUG printf("DRAW THE MAP: %s\n", *(set->map.c_map));
	ft_bzero(&pix, sizeof(t_pix));
	set->win.mlx = mlx_init();
	set->win.win = mlx_new_window(set->win.mlx, set->win.res1, set->win.res2, "test");
	while (set->map.c_map[pix.y])
	{
		pix.x = 0;
		while (set->map.c_map[pix.y][pix.x])
		{
			if (set->map.c_map[pix.y][pix.x] == '1')
//				scale_pix(set, &pix);
				mlx_pixel_put(set->win.mlx, set->win.win, pix.x, pix.y, 0xFFFFFF);
		pix.x++;
		}
		pix.y++;
	}
	mlx_loop(set->win.mlx);
}


int			main(int argc, char **argv)
{
	t_set 	set;

	printf("sam: %d\n", errno);
//	printf("sam");
	errno = 0;
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], SAVE_FLAG, ft_strlen(SAVE_FLAG)))
			printf("it's necessary to save in .bmp format\n");
		else
		{
			init_set(&set);
			ft_parser(argv[1], &set);
			draw_map(&set);
		}

	}
	else
		ft_error(22);
//	auto_clear();
	return (0);
}


//!!!!!! Необходимо ввести perror, strerror и exit