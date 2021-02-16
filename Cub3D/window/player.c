#include "../ft_cub.h"

/*
** counts the ray length and (optionally) put pixel in a
** cross of the ray and grid
*/

static double		count_ray_len(t_set *set, t_fpix *ray_dir, t_fpix *cross)
{
//	t_fpix			cross;
	t_fpix			dist;
	t_pix			map;

	set->player.step.x = (ray_dir->x < 0) ? -1 : 1;
	set->player.step.y = (ray_dir->y < 0) ? -1 : 1;
	map.x = (int)set->player.pos.x;
	map.y = (int)set->player.pos.y;
	while (set->map.c_map[map.y][map.x] != '1')
	{
		cross->x = (ray_dir->x < 0) ?
				map.x + set->player.step.x + 1 : map.x + set->player.step.x;
		cross->y = (ray_dir->y < 0) ?
				map.y + set->player.step.y + 1 : map.y + set->player.step.y;
		dist.x = (ray_dir->x == 0) ? dist.x + 1 :
				fabs((cross->x - set->player.pos.x) / (ray_dir->x / v_len(*ray_dir)));
		dist.y = (ray_dir->y == 0) ? dist.y + 1 :
				fabs((cross->y - set->player.pos.y) / (ray_dir->y / v_len(*ray_dir)));
		if (dist.x < dist.y)
		{
			cross->y = set->player.pos.y + dist.x * ray_dir->y / v_len(*ray_dir);
			map.x += set->player.step.x;
		}
		else
		{
			cross->x = set->player.pos.x + dist.y * ray_dir->x / v_len(*ray_dir);
			map.y += set->player.step.y;
		}
		my_mlx_pixel_put(set, cross->x * SCALE, cross->y * SCALE, 0xFF0000);
	}
	return (dist.x < dist.y ? dist.x : dist.y);
}

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


void 				open_image(t_set *set)
{
	void			*pct;
	t_pix			size;

	ft_bzero(&size, sizeof(t_pix));
	pct = mlx_xpm_file_to_image(set->win.mlx, set->skin.no_ski, &size.x, &size.y);
//	mlx_png_file_to_image()
	DEBUG printf("pct '%s' was read [%dx%d]\n", set->skin.no_ski, size.x, size.y);
}

unsigned int	get_color(t_img *img, int x, int y)
{
	char		*dst;

	dst = img->addr + (y * img->len + x * (img->bpp / 8));
	return (*(unsigned int*)dst);
}

/*
** It seems the height of objects should be larger when
** player sits, and smaller when player jumps
** k is a variable that contains the range of scale when
** player sits/jumps
*/

void				draw_line(t_set *set, double dist, int x, t_fpix *cross)
{
	int				h;
	int				y0;
	int				y1;
	double			k;

	t_img			pct;
	t_pix			size;

	ft_bzero(&size, sizeof(t_pix));
	pct.img = mlx_xpm_file_to_image(set->win.mlx, set->skin.no_ski, &size.x, &size.y);
	pct.addr = mlx_get_data_addr(pct.img, &pct.bpp, &pct.len,
									  &pct.endian);

	k = set->player.hor / HOR;
	h = (int)((double)set->win.img1.res2 / dist * k);

	int scale = h / size.y;

	y0 = set->win.img1.res2 / set->player.hor - h / 2;
	y0 = y0 <= 0 ? 1 : y0;
	y1 = set->win.img1.res2 / set->player.hor + h / 2;
	y1 = y1 >= set->win.img1.res2 ? set->win.img1.res2 - 1 : y1;
//	open_image(set);
	int x_i = (int)(64 * (cross->x - (int)(cross->x)));
	int y_i = y0 / scale;
	while(y0 < y1)
	{
		my_mlx_pixel_put(set, x, y0, get_color(&pct, x_i, y_i));
		y0++;
	}
}


void				drop_rays(t_set *set)
{
	int				x;
	double			dist;

	double			cameraX;
	t_fpix			ray_dir;
	double			perpDist;
	t_fpix			cross;

	my_mlx_pixel_put(set, (int)(set->player.pos.x * SCALE), (int)(set->player.pos.y * SCALE), 0x00FF00);
	x = 0;
//	open_image(set);
	while (x < set->win.img1.res1)
	{
		cameraX = 2 * x / (double)set->win.img1.res1 - 1;
		ray_dir.x = set->player.dir.x + cameraX * set->player.plane.x;
		ray_dir.y = set->player.dir.y + cameraX * set->player.plane.y;
		dist = count_ray_len(set, &ray_dir, &cross);
		perpDist = dist * v_mult(ray_dir, set->player.dir)/v_len(set->player.dir) / v_len(ray_dir);
		draw_line(set, perpDist, x, &cross);
		x++;
	}

}

void				set_player(t_set *set)
{
	drop_rays(set);
}
