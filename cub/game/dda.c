/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:00:36 by yeschall          #+#    #+#             */
/*   Updated: 2021/03/10 17:00:39 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub.h"

/*
** It seems the height of objects should be larger when
** player sits, and smaller when player jumps
** k is a variable that contains the range of scale when
** player sits/jumps
*/

static void			draw_strip(t_set *set, t_ray *ray)
{
	t_pix			strip;
	t_pix			wall;
	int				y;

	strip.x = (int)((double)set->win.img.res.y / set->player.hor - ray->h / 2);
	strip.y = (int)((double)set->win.img.res.y / set->player.hor + ray->h / 2);
	wall.x = (ray->side % 2) ?
		(int)((set->win.skins[ray->side].res.x - 1) * fmod(ray->cross.x, 1.0)) :
		(int)((set->win.skins[ray->side].res.x - 1) *
		(1 - fmod(ray->cross.y, 1.0)));
	y = -1;
	while (++y < set->win.img.res.y)
	{
		if (y <= strip.x)
			my_mlx_pixel_put(set, ray->x, (int)y, set->skin.ce_col);
		else if (y > strip.x && y < strip.y)
		{
			wall.y = (int)((y - (double)strip.x) *
					(double)set->win.skins[ray->side].res.y / ray->h);
			my_mlx_pixel_put(set, ray->x, (int)y,
					get_clr(&set->win.skins[ray->side], wall.x, wall.y));
		}
		else if (y >= strip.y)
			my_mlx_pixel_put(set, ray->x, (int)y, set->skin.fl_col);
	}
}

static void			count_ray_len0(t_fpix *d, t_ray *r, t_set *set, t_pix map)
{
	r->cross.x = (r->dir.x < 0) ?
		map.x + set->player.step.x + 1 : map.x + set->player.step.x;
	r->cross.y = (r->dir.y < 0) ?
		map.y + set->player.step.y + 1 : map.y + set->player.step.y;
	d->x = (r->dir.x == 0) ? d->x + 1 :
		fabs((r->cross.x - set->player.pos.x) / (r->dir.x / v_len(r->dir)));
	d->y = (r->dir.y == 0) ? d->y + 1 :
		fabs((r->cross.y - set->player.pos.y) / (r->dir.y / v_len(r->dir)));
}

/*
** counts the ray length and (optionally) put pixel in a
** cross of the ray and grid. Counts side of wall:
** 0 - EA, 1 - NO, 2, - WE, 3 - SO
*/

static void			count_ray_len(t_set *set, t_ray *r)
{
	t_fpix			dist;
	t_pix			map;

	set->player.step.x = (r->dir.x < 0) ? -1 : 1;
	set->player.step.y = (r->dir.y < 0) ? -1 : 1;
	map.x = (int)set->player.pos.x;
	map.y = (int)set->player.pos.y;
	while (set->map.c_map[map.y][map.x] != '1')
	{
		count_ray_len0(&dist, r, set, map);
		if (dist.x < dist.y)
		{
			r->cross.y = set->player.pos.y + dist.x * r->dir.y / v_len(r->dir);
			map.x += set->player.step.x;
			r->side = (r->dir.x < 0) ? 2 : 0;
		}
		else
		{
			r->cross.x = set->player.pos.x + dist.y * r->dir.x / v_len(r->dir);
			map.y += set->player.step.y;
			r->side = (r->dir.y < 0) ? 1 : 3;
		}
		r->dist = dist.x < dist.y ? dist.x : dist.y;
		(set->map.c_map[map.y][map.x] == '2') ? sprite_on(set, r, map) : 0;
	}
}

void				drop_rays(t_set *set)
{
	t_ray			ray;
	double			cam;

	ray.x = 0;
	sprites_off(set);
	while (ray.x < set->win.img.res.x)
	{
		cam = 2 * ray.x / (double)set->win.img.res.x - 1;
		ray.dir.x = set->player.dir.x + cam * set->player.plane.x;
		ray.dir.y = set->player.dir.y + cam * set->player.plane.y;
		count_ray_len(set, &ray);
		ray.perp = ray.dist / v_len(set->player.dir) / v_len(ray.dir) *
			(ray.dir.x * set->player.dir.x + ray.dir.y * set->player.dir.y);
		if (ray.perp < ZER)
			ray.perp = ZER;
		ray.h = (double)set->win.img.res.y / ray.perp;
		draw_strip(set, &ray);
		ray.x++;
	}
	draw_sprites(set);
}
