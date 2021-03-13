/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:44:24 by yeschall          #+#    #+#             */
/*   Updated: 2021/03/10 16:44:26 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub.h"

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
		set->skin.spr_ski, &set->win.skins[4].res.x, &set->win.skins[4].res.y)))
		ft_error(set, 1021);
	write_addr(&set->win.skins[0]);
	write_addr(&set->win.skins[1]);
	write_addr(&set->win.skins[2]);
	write_addr(&set->win.skins[3]);
	write_addr(&set->win.skins[4]);
	ft_free(&(set->skin.no_ski));
	ft_free(&(set->skin.so_ski));
	ft_free(&(set->skin.we_ski));
	ft_free(&(set->skin.ea_ski));
	ft_free(&(set->skin.spr_ski));
}

static void		init_player_pos(t_set *set)
{
	if (set->map.player_dir == 'W')
	{
		set->player.plane.y = -PLANE_W;
		set->player.dir.x = -1;
	}
	if (set->map.player_dir == 'N')
	{
		set->player.plane.x = PLANE_W;
		set->player.dir.y = -1;
	}
	if (set->map.player_dir == 'S')
	{
		set->player.plane.x = -PLANE_W;
		set->player.dir.y = 1;
	}
	if (set->map.player_dir == 'E')
	{
		set->player.plane.y = PLANE_W;
		set->player.dir.x = 1;
	}
	set->player.pos.x = set->map.pos.x + 0.3;
	set->player.pos.y = set->map.pos.y + 0.3;
}

static void		check_display_resolution(t_set *set, t_pix *res)
{
	t_pix		display;

	if (set->os == 2)
		mlx_get_screen_size(set->win.mlx, &display.x, &display.y);
	if (set->os == 1)
		mlx_get_screen_size(set->win.mlx, &display.x, &display.y);
	if (display.x < res->x)
		res->x = display.x;
	if (display.y < res->y)
		res->y = display.y;
}

static int		display_img(t_set *set)
{
	update_pos(set);
	mlx_destroy_image(set->win.mlx, set->win.img.img);
	set->win.img.img = mlx_new_image(set->win.mlx,
			set->win.img.res.x, set->win.img.res.y);
	set->win.img.addr = mlx_get_data_addr(set->win.img.img,
			&set->win.img.bpp, &set->win.img.len, &set->win.img.endian);
	drop_rays(set);
	if (set->save == 1)
		screen_image(set);
	mlx_put_image_to_window(set->win.mlx, set->win.win,
			set->win.img.img, 0, 0);
	return (0);
}

void			run_game(t_set *set)
{
	set->win.mlx = mlx_init();
	check_display_resolution(set, &set->win.img.res);
	set->win.win = mlx_new_window(set->win.mlx,
			set->win.img.res.x, set->win.img.res.y, "cub3D");
	set->win.img.img = mlx_new_image(set->win.mlx, set->win.img.res.x,
			set->win.img.res.y);
	set->win.img.addr = mlx_get_data_addr(set->win.img.img,
			&set->win.img.bpp, &set->win.img.len, &set->win.img.endian);
	if (set->player.pos.x == -1)
	{
		init_textures(set);
		init_player_pos(set);
	}
	display_img(set);
	mlx_hook(set->win.win, 2, 1L << 0, key_hook_press, set);
	if (set->os == 1)
		mlx_hook(set->win.win, 33, 1L << 0, finish_program, set);
	if (set->os == 2)
		mlx_hook(set->win.win, 17, 1L << 0, finish_program, set);
	mlx_loop_hook(set->win.mlx, display_img, set);
	mlx_hook(set->win.win, 3, 1L << 1, key_hook_up, set);
	mlx_loop(set->win.mlx);
}
