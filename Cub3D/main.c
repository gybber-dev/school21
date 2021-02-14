#include "ft_cub.h"
#include <string.h>
//#include "minilibx_opengl_20191021/mlx.h"

static void				init_set(t_set *set)
{
	set->map.c_map = NULL;
	set->map.ismalloced = 0;
	set->win.mlx = NULL;
	set->win.win = NULL;
	set->win.img1.res1 = 0;
	set->win.img1.res2 = 0;
	set->skin.fl_col = 0;
	set->skin.ce_col = 0;
	set->skin.no_ski = NULL;
	set->skin.so_ski = NULL;
	set->skin.we_ski = NULL;
	set->skin.ea_ski = NULL;
	set->skin.sprite_ski = NULL;
	set->player.pos.x = -1;
	set->player.pos.y = -1;
//	set->player.angle = -1;
	set->player.move = 0;
	ft_bzero(&set->player.dir, sizeof(t_fpix));
	ft_bzero(&set->player.plane, sizeof(t_fpix));
}

int			main(int argc, char **argv)
{
	t_set 	set;

	printf("errno: %d\n", errno);
	DEBUG printf("OS detected: '%s'\n", OS);
	errno = 0;
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], SAVE_FLAG, ft_strlen(SAVE_FLAG)))
			printf("it's necessary to save in .bmp format\n");
		else
		{
			init_set(&set);
			ft_parser(argv[1], &set);
			run_game(&set);
		}

	}
	else
		ft_error(22);
//	auto_clear();
	return (0);
}
