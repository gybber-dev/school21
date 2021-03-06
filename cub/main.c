#include "ft_cub.h"
#include <string.h>

int					finish_programm(t_set *set)
{
	DEBUG printf("You exit the game. See you...\n");
	auto_clear(set);
	exit(EXIT_SUCCESS);
}

void				auto_clear(t_set *set)
{

}

static void				init_set(t_set *set)
{
	set->tmp = NULL;
	set->map.c_map = NULL;
	set->map.isparsed = 0;
	set->win.mlx = NULL;
	set->win.win = NULL;
	set->skin.fl_col = -1;
	set->skin.ce_col = -1;
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
	set->os = (!ft_strncmp(OS, "MAC", 3)) ? 2 : 1;
}

int			main(int argc, char **argv)
{
	t_set 	set;

	char *s = malloc(24);

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
