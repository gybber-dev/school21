#include "../ft_cub.h"

/*
** counts the ray length and (optionally) put pixel in a
** cross of the ray and grid
*/

static double		count_ray_len(t_set *set, t_fpix *ray_dir, t_fpix *cross)
{
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

void 				open_image(t_set *set)
{
	DEBUG printf("pct '%s' was read [%dx%d]\n", set->skin.no_ski,
			  set->win.no.res.x, set->win.no.res.y);
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

	k = set->player.hor / HOR;
	h = (int)((double)set->win.img1.res.y / dist * k);

	int scale = h / set->win.no.res.y;

	y0 = set->win.img1.res.y / set->player.hor - h / 2;
	y0 = y0 <= 0 ? 1 : y0;
	y1 = set->win.img1.res.y / set->player.hor + h / 2;
	y1 = y1 >= set->win.img1.res.y ? set->win.img1.res.y - 1 : y1;
	open_image(set);
	int x_i = (int)(64 * (cross->x - (int)(cross->x)));
	int y_i = y0 / scale;
	while(y0 < y1)
	{
		my_mlx_pixel_put(set, x, y0, get_color(set->win.no.img, x_i, y_i));
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
	while (x < set->win.img1.res.x)
	{
		cameraX = 2 * x / (double)set->win.img1.res.x - 1;
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
