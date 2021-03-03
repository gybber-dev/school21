#include "ft_cub.h"
#include <string.h>
//#include "minilibx_opengl_20191021/mlx.h"

static void				init_set(t_set *set)
{
	set->map.c_map = NULL;
	set->map.ismalloced = 0;
	set->win.mlx = NULL;
	set->win.win = NULL;
	set->skin.fl_col = 0;
	set->skin.ce_col = 0;
	set->skin.no_ski = NULL;
	set->skin.so_ski = NULL;
	set->skin.we_ski = NULL;
	set->skin.ea_ski = NULL;
	set->sl = NULL;
	set->skin.sprite_ski = NULL;
	set->player.pos.x = -1;
	set->player.pos.y = -1;
	set->player.hor = 2;
	set->player.move = 0;
	ft_bzero(&set->win.img1.res, sizeof(t_fpix));
	ft_bzero(&set->player.dir, sizeof(t_fpix));
	ft_bzero(&set->player.plane, sizeof(t_fpix));
}

int			main(int argc, char **argv)
{
	t_set 	set;

	printf("errno: %d\n", errno);
	DEBUG printf("OS detected: '%s'\n", OS);
	set.save = 0;
	if (argc == 2 || (argc == 3 && !ft_strncmp(argv[2], SAVE, ft_strlen(SAVE))))
	{
		if (argc == 3)
			set.save = 1;
		init_set(&set);
		ft_parser(argv[1], &set);
		run_game(&set);
	}
	else
		ft_error(&set, 22);
	return (0);
}
