#include "../ft_cub.h"



/*
** counts the ray length and (optionally) put pixel in a
** cross of the ray and grid
*/

static void			count_ray_len(t_set *set, t_fpix *dist, t_pix *map, t_fpix *ray_dir)
{
	t_fpix			cross;

//	DEBUG printf("Player is on\n\t[%f, %f]\nsin(%f) = %f\ncos(%f) = %f\n", set->player.pos.y, set->player.pos.x, set->player.angle, sin(set->player.angle), set->player.angle, cos(set->player.angle));
	cross.x = (ray_dir->x < 0) ?
			map->x + set->player.step.x + 1 : map->x + set->player.step.x;
	cross.y = (ray_dir->y < 0) ?
			map->y + set->player.step.y + 1 : map->y + set->player.step.y;
	dist->x = (ray_dir->x == 0) ? dist->x + 1 :
			fabs((cross.x - set->player.pos.x) / (ray_dir->x / v_len(*ray_dir)));
	dist->y = (ray_dir->y == 0) ? dist->y + 1 :
			fabs((cross.y - set->player.pos.y) / (ray_dir->y / v_len(*ray_dir)));
	if (dist->x < dist->y)
	{
		cross.y = set->player.pos.y + dist->x * ray_dir->y / v_len(*ray_dir);
		map->x += set->player.step.x;
	}
	else
	{
		cross.x = set->player.pos.x + dist->y * ray_dir->x / v_len(*ray_dir);
		map->y += set->player.step.y;
	}
	my_mlx_pixel_put(set, cross.x * SCALE, cross.y * SCALE, 0xFF0000);

}

void				draw_line(t_set *set, t_fpix dist, int x)
{
	int				len;
	int				y = 0;

	len = (int)((double)30 / v_len(dist));
	DEBUG printf("len: %d\n", len);
	while(y < len)
	{
		my_mlx_pixel_put(set, x, 50 + len, 0xFF0000);
		len--;
	}
}


void				drop_rays(t_set *set)
{
	int				x;
	t_fpix			dist;
	t_pix			map;
	double			cameraX;
	t_fpix			ray_dir;

	my_mlx_pixel_put(set, (int)(set->player.pos.x * SCALE), (int)(set->player.pos.y * SCALE), 0x00FF00);
	x = 0;
	while (x < set->win.res1)
	{
		map.x = (int)set->player.pos.x;
		map.y = (int)set->player.pos.y;
		cameraX = 2 * x / (double)set->win.res1 - 1;
		ray_dir.x = set->player.dir.x + cameraX * set->player.plane.x;
		ray_dir.y = set->player.dir.y + cameraX * set->player.plane.y;
		ft_bzero(&dist, sizeof(t_fpix));
		set->player.step.x = (ray_dir.x < 0) ? -1 : 1;
		set->player.step.y = (ray_dir.y < 0) ? -1 : 1;
		while (set->map.c_map[map.y][map.x] != '1')
		{
			count_ray_len(set, &dist, &map, &ray_dir);
			draw_line(set, dist, x);
		}
		x++;
	}
}

void				set_player(t_set *set)
{
	drop_rays(set);
}
