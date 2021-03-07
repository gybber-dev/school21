#include "../ft_cub.h"

void			my_mlx_pixel_put(t_set *set, int x, int y, int color)
{
	char		*dst;

	if (y < set->win.img1.res.y && x < set->win.img1.res.x && x >= 0 && y >= 0)
	{
		dst = set->win.img1.addr + (y * set->win.img1.len + x * (set->win.img1.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

static void		init_textures(t_set *set)
{
	if (!(set->win.skins[1].img = mlx_xpm_file_to_image(set->win.mlx,
		set->skin.no_ski, &set->win.skins[1].res.x, &set->win.skins[1].res.y)))
		ft_error(set, 1021);
	if (!(set->win.skins[3].img = mlx_xpm_file_to_image(set->win.mlx,
		set->skin.so_ski, &set->win.skins[3].res.x, &set->win.skins[3].res.y)))
		ft_error(set, 1021);
	if (!(set->win.skins[0].img = mlx_xpm_file_to_image(set->win.mlx,
		set->skin.ea_ski, &set->win.skins[0].res.x, &set->win.skins[0].res.y)))
		ft_error(set, 1021);
	if (!(set->win.skins[2].img = mlx_xpm_file_to_image(set->win.mlx,
		set->skin.we_ski, &set->win.skins[2].res.x, &set->win.skins[2].res.y)))
		ft_error(set, 1021);
	if (!(set->win.skins[4].img = mlx_xpm_file_to_image(set->win.mlx,
		set->skin.sprite_ski, &set->win.skins[4].res.x, &set->win.skins[4].res.y)))
		ft_error(set, 1021);
	ft_free(&(set->skin.no_ski));
	ft_free(&(set->skin.so_ski));
	ft_free(&(set->skin.we_ski));
	ft_free(&(set->skin.ea_ski));
	ft_free(&(set->skin.sprite_ski));
	DEBUG printf("pct '%s' was read [%dx%d]\n", set->skin.sprite_ski, set->win.skins[4].res.x, set->win.skins[4].res.y);
}

static void		init_player_pos(t_set *set)
{
	char		**p;
	int			i;

	DEBUG printf("Find player\n");
	p = set->map.c_map;
	set->player.pos.y = 0;
	while(*p != NULL && i >= 0)
	{
		i = 0;
		while ((*p)[i] != 0)
		{
			if ((*p)[i] == 'W' || (*p)[i] == 'N' || (*p)[i] == 'S' || (*p)[i] == 'E')
			{
				if ((*p)[i] == 'W')
					if ((set->player.plane.y = -PLANE_W))
						set->player.dir.x = -1;
				if ((*p)[i] == 'N')
					if ((set->player.plane.x = PLANE_W))
						set->player.dir.y = -1;
				if ((*p)[i] == 'S')
					if ((set->player.plane.x = -PLANE_W))
						set->player.dir.y = 1;
				if ((*p)[i] == 'E')
					if ((set->player.plane.y = PLANE_W))
						set->player.dir.x = 1;
				set->player.pos.x = i + 0.3;
				set->player.pos.y += 0.3;
				(*p)[i] = '0';
				return ;
			}
			i++;
		}
		p++;
		set->player.pos.y += 1;
	}
}

static void		check_display_resolution(t_set *set, t_pix *res)
{
	t_pix		display;

	if (set->os == 2)
	{
		display.x = 2560;
		display.y = 1440;
	}
	if (set->os == 1)
		mlx_get_screen_size(set->win.mlx, &display.x, &display.y);
	if (display.x < res->x)
		res->x = display.x;
	if (display.x < res->y)
		res->y = display.y;
}

void			run_game(t_set *set)
{
	set->win.mlx = mlx_init();
	check_display_resolution(set, &set->win.img1.res);
	set->win.win = mlx_new_window(set->win.mlx, set->win.img1.res.x, set->win.img1.res.y, "cub3D");
	set->win.img1.img = mlx_new_image(set->win.mlx, set->win.img1.res.x, set->win.img1.res.y);
	set->win.img1.addr = mlx_get_data_addr(set->win.img1.img, &set->win.img1.bpp,
							&set->win.img1.len, &set->win.img1.endian);
	if (set->player.pos.x == -1)
	{
		init_textures(set);
		init_player_pos(set);
	}
	display_img(set);
	mlx_hook(set->win.win, 2, 1L<<0, key_hook_press, set);
	if (set->os == 1)
		mlx_hook(set->win.win, 33, 1L<<0, finish_program, set);
	if (set->os == 2)
		mlx_hook(set->win.win, 17, 1L<<0, finish_program, set);
	mlx_loop_hook(set->win.mlx, display_img, set);
	mlx_hook(set->win.win, 3, 1L<<1, key_hook_up, set);
	mlx_loop(set->win.mlx);
}