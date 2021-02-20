#include "../ft_cub.h"

unsigned int	get_color(t_img *img, int x, int y)
{
//	return (0x00858585);
	char		*dst;
	img->addr = mlx_get_data_addr(img, &img->bpp, &img->len, &img->endian);
	dst = img->addr + (y * img->len + x * (img->bpp / 8));
	return (*(unsigned int*)dst);
}

/*
** It seems the height of objects should be larger when
** player sits, and smaller when player jumps
** k is a variable that contains the range of scale when
** player sits/jumps
*/

void				draw_strip(t_set *set, double dist, int x, t_fpix *cross, int side)
{
	double			h;
	t_pix			strip;
	t_pix			wall;
	double			k;
	double			y;

	k = set->player.hor / HOR;
	h = (double)set->win.img1.res.y / dist * k;

	strip.x = (int)((double)set->win.img1.res.y / set->player.hor - h / 2);
	strip.y = set->win.img1.res.y / set->player.hor + h / 2;
	y = strip.x;
	if (side % 2) // != 0
		wall.x = (int)((set->win.skins[side].res.y - 1) * fmod(cross->x, 1.0));
	else
		wall.x = (int)((set->win.skins[side].res.y - 1) * (1 - fmod(cross->y, 1.0)));
	while(y < strip.y)
	{
		if (y > 0 && y < set->win.img1.res.y)
		{
			wall.y = (int)((y - (double)strip.x) * (double)set->win.skins[side].res.y / (double)h);
			my_mlx_pixel_put(set, x, (int)y, get_color(set->win.skins[side].img, wall.x, wall.y));
		}
		y++;
	}
}

/*
** counts the ray length and (optionally) put pixel in a
** cross of the ray and grid. Counts side of wall:
** 0 - EA, 1 - NO, 2, - WE, 3 - SO
*/

static double		count_ray_len(t_set *set, t_fpix *ray_dir, t_fpix *cross, int *side)
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
			*side = (ray_dir->x < 0) ? 2 : 0;
		}
		else
		{
			cross->x = set->player.pos.x + dist.y * ray_dir->x / v_len(*ray_dir);
			map.y += set->player.step.y;
			*side = (ray_dir->y < 0) ? 1 : 3;
		}
		my_mlx_pixel_put(set, cross->x * SCALE, cross->y * SCALE, 0xFF0000);
	}
	return (dist.x < dist.y ? dist.x : dist.y);
}


void				drop_rays(t_set *set)
{
	int				x;
	double			dist;

	double			cameraX;
	t_fpix			ray_dir;
	double			perpDist;
	t_fpix			cross;
	int				side;

	my_mlx_pixel_put(set, (int)(set->player.pos.x * SCALE), (int)(set->player.pos.y * SCALE), 0x00FF00);
	x = 0;
//	open_image(set);
	while (x < set->win.img1.res.x)
	{
		cameraX = 2 * x / (double)set->win.img1.res.x - 1;
		ray_dir.x = set->player.dir.x + cameraX * set->player.plane.x;
		ray_dir.y = set->player.dir.y + cameraX * set->player.plane.y;
		dist = count_ray_len(set, &ray_dir, &cross, &side);
		perpDist = dist * v_mult(ray_dir, set->player.dir)/v_len(set->player.dir) / v_len(ray_dir);
		draw_strip(set, perpDist, x, &cross, side);
		x++;
	}

}

int				set_player(t_set *set)
{
	update_pos(set);
	mlx_destroy_image(set->win.mlx, set->win.img1.img);
	set->win.img1.img = mlx_new_image(set->win.mlx, set->win.img1.res.x, set->win.img1.res.y);
	set->win.img1.addr = mlx_get_data_addr(set->win.img1.img, &set->win.img1.bpp,
										   &set->win.img1.len, &set->win.img1.endian);
	draw_map(set);
	drop_rays(set);
	mlx_put_image_to_window(set->win.mlx, set->win.win, set->win.img1.img, 0, 0);
	return (0);
}
