#include "../ft_cub.h"

/*
** It seems the height of objects should be larger when
** player sits, and smaller when player jumps
** k is a variable that contains the range of scale when
** player sits/jumps
*/

static void			draw_strip(t_set *set, t_ray *ray)
{
	double			h;
	t_pix			strip;
	t_pix			wall;
	int				y;

	if (ray->perp <= 0.00001)
		h = 300 * set->win.img1.res.y;
	else
		h = (double)set->win.img1.res.y / ray->perp;
	strip.x = (int)((double)set->win.img1.res.y / set->player.hor - h / 2);
	strip.y = (int)((double)set->win.img1.res.y / set->player.hor + h / 2);
	wall.x = (ray->side % 2) ?
		(int)((set->win.skins[ray->side].res.x - 1) * fmod(ray->cross.x, 1.0)) :
		(int)((set->win.skins[ray->side].res.x - 1) * (1 - fmod(ray->cross.y, 1.0)));
	y = -1;
	while(++y < set->win.img1.res.y)
	{
		if (y <= strip.x)
			my_mlx_pixel_put(set, ray->x, (int)y, set->skin.ce_col);
		else if (y > strip.x && y < strip.y)
		{
			wall.y = (int)((y - (double)strip.x) * (double)set->win.skins[ray->side].res.y / (double)h);
			my_mlx_pixel_put(set, ray->x, (int)y, get_color(&set->win.skins[ray->side], wall.x, wall.y));
		}
		else if (y >= strip.y)
			my_mlx_pixel_put(set, ray->x, (int)y, set->skin.fl_col);
	}
}

static void			count_ray_len0(t_fpix *dist, t_ray *ray, t_set *set, t_pix map)
{
	ray->cross.x = (ray->dir.x < 0) ?
			map.x + set->player.step.x + 1 : map.x + set->player.step.x;
	ray->cross.y = (ray->dir.y < 0) ?
			map.y + set->player.step.y + 1 : map.y + set->player.step.y;
	dist->x = (ray->dir.x == 0) ? dist->x + 1 :
			fabs((ray->cross.x - set->player.pos.x) / (ray->dir.x / v_len(ray->dir)));
	dist->y = (ray->dir.y == 0) ? dist->y + 1 :
			fabs((ray->cross.y - set->player.pos.y) / (ray->dir.y / v_len(ray->dir)));
}


/*
** counts the ray length and (optionally) put pixel in a
** cross of the ray and grid. Counts side of wall:
** 0 - EA, 1 - NO, 2, - WE, 3 - SO
*/

static void			count_ray_len(t_set *set, t_ray *ray)
{
	t_fpix			dist;
	t_pix			map;

	set->player.step.x = (ray->dir.x < 0) ? -1 : 1;
	set->player.step.y = (ray->dir.y < 0) ? -1 : 1;
	map.x = (int)set->player.pos.x;
	map.y = (int)set->player.pos.y;
	while (set->map.c_map[map.y][map.x] != '1')
	{
		count_ray_len0(&dist, ray, set, map);
		if (dist.x < dist.y)
		{
			ray->cross.y = set->player.pos.y + dist.x * ray->dir.y / v_len(ray->dir);
			map.x += set->player.step.x;
			ray->side = (ray->dir.x < 0) ? 2 : 0;
		}
		else
		{
			ray->cross.x = set->player.pos.x + dist.y * ray->dir.x / v_len(ray->dir);
			map.y += set->player.step.y;
			ray->side = (ray->dir.y < 0) ? 1 : 3;
		}
		ray->dist = dist.x < dist.y ? dist.x : dist.y;
		if (set->map.c_map[map.y][map.x] == '2')
			add_sprite(set, ray, map);
	}
}

void				 drop_rays(t_set *set)
{
	t_ray			ray;
	double			cam;

	ray.x = 0;
	while (ray.x < set->win.img1.res.x)
	{
		cam = 2 * ray.x / (double)set->win.img1.res.x - 1;
		ray.dir.x = set->player.dir.x + cam * set->player.plane.x;
		ray.dir.y = set->player.dir.y + cam * set->player.plane.y;
		count_ray_len(set, &ray);
		ray.perp = ray.dist * v_mult(ray.dir, set->player.dir)/v_len(set->player.dir) / v_len(ray.dir);
		draw_strip(set, &ray);
		ray.x++;
	}
	draw_sprites(set);
}
