#include "../ft_cub.h"

//void    ft_init_images(t_data *img)
//{
//	if (!(img->images[0].img = mlx_xpm_file_to_image(img->mlx,
//													 img->textures.north, &img->images[0].texturewidth, &img->images[0].textureheight)))
//		ft_error(img, "Some troubles with xpm file");
//	free(img->textures.north);
//	if (!(img->images[1].img = mlx_xpm_file_to_image(img->mlx,
//													 img->textures.south, &img->images[1].texturewidth, &img->images[1].textureheight)))
//		ft_error(img, "Some troubles with xpm file");
//	free(img->textures.south);
//	if (!(img->images[2].img = mlx_xpm_file_to_image(img->mlx,
//													 img->textures.west, &img->images[2].texturewidth, &img->images[2].textureheight)))
//		ft_error(img, "Some troubles with xpm file");
//	free(img->textures.west);
//	if (!(img->images[3].img = mlx_xpm_file_to_image(img->mlx,
//													 img->textures.east, &img->images[3].texturewidth, &img->images[3].textureheight)))
//		ft_error(img, "Some troubles with xpm file");
//	free(img->textures.east);
//	if (!(img->sprite.img = mlx_xpm_file_to_image(img->mlx,
//												  img->textures.sprite, &img->sprite.texturewidth, extures.south&img->sprite.textureheight)))
//		ft_error(img, "Some troubles with xpm file");
//	ft_init_images_continue(img);
//}



void			my_mlx_pixel_put(t_set *set, int x, int y, int color)
{
	char		*dst;

	dst = set->win.img1.addr + (y * set->win.img1.len + x * (set->win.img1.bpp / 8));
	*(unsigned int *) dst = color;
}

static void		init_textures(t_set *set)
{
	if (!(set->win.no.img = mlx_xpm_file_to_image(set->win.mlx,
		set->skin.no_ski, &set->win.no.res.x, &set->win.no.res.y)))
		ft_error(1021);
	if (!(set->win.so.img = mlx_xpm_file_to_image(set->win.mlx,
		set->skin.so_ski, &set->win.so.res.x, &set->win.so.res.y)))
		ft_error(1021);
	if (!(set->win.ea.img = mlx_xpm_file_to_image(set->win.mlx,
		set->skin.ea_ski, &set->win.ea.res.x, &set->win.ea.res.y)))
		ft_error(1021);
	if (!(set->win.we.img = mlx_xpm_file_to_image(set->win.mlx,
		set->skin.we_ski, &set->win.we.res.x, &set->win.we.res.y)))
		ft_error(1021);
	ft_free(&(set->skin.no_ski));
	ft_free(&(set->skin.so_ski));
	ft_free(&(set->skin.we_ski));
	ft_free(&(set->skin.ea_ski));
	set->win.we.addr = mlx_get_data_addr(set->win.we.img,
		&set->win.we.bpp, &set->win.we.len, &set->win.we.endian);
	set->win.no.addr = mlx_get_data_addr(set->win.no.img,
		&set->win.no.bpp, &set->win.no.len, &set->win.no.endian);
	set->win.so.addr = mlx_get_data_addr(set->win.so.img,
		&set->win.so.bpp, &set->win.so.len, &set->win.so.endian);
	set->win.ea.addr = mlx_get_data_addr(set->win.ea.img,
		&set->win.ea.bpp, &set->win.ea.len, &set->win.ea.endian);
	DEBUG printf("pct '%s' was read [%dx%d]\n", set->skin.no_ski, set->win.no.res.x, set->win.no.res.y);
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
					if ((set->player.plane.y = 0.66))
						set->player.dir.x = -1;
				if ((*p)[i] == 'N')
					if ((set->player.plane.x = 0.66))
						set->player.dir.y = -1;
				if ((*p)[i] == 'S')
					if ((set->player.plane.x = 0.66))
						set->player.dir.y = 1;
				if ((*p)[i] == 'E')
					if ((set->player.plane.y = 0.66))
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

void			run_game(t_set *set)
{
	set->win.mlx = mlx_init();
	set->win.win = mlx_new_window(set->win.mlx, set->win.img1.res.x, set->win.img1.res.y, "test");
	set->win.img1.img = mlx_new_image(set->win.mlx, set->win.img1.res.x, set->win.img1.res.y);
	set->win.img1.addr = mlx_get_data_addr(set->win.img1.img, &set->win.img1.bpp,
							&set->win.img1.len, &set->win.img1.endian);
	draw_map(set);
	if (set->player.pos.x == -1)
	{
		init_textures(set);
		init_player_pos(set);
	}
	mlx_put_image_to_window(set->win.mlx, set->win.win, set->win.img1.img, 0, 0);
	mlx_hook(set->win.win, 2, 1L<<0, key_hook_press, set);
	mlx_hook(set->win.win, 3, 1L<<1, key_hook_up, set);


	set_player(set);
	mlx_put_image_to_window(set->win.mlx, set->win.win, set->win.img1.img, 0, 0);
	mlx_loop(set->win.mlx);
}