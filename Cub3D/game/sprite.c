/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:12:58 by yeschall          #+#    #+#             */
/*   Updated: 2021/03/10 17:13:00 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub.h"

static void		draw_sprite(t_set *set, t_spr *sp)
{
	t_fpix		wl;
	int			clr;
	int			x;
	int			y;

	sp->start.y = (double)set->win.img.res.y / set->player.hor - sp->h / 2 - 1;
	sp->end.y = (double)set->win.img.res.y / set->player.hor + sp->h / 2;
	x = (int)(sp->start.x - 1);
	while (++x < sp->x_max && x < set->win.img.res.x && x <= sp->end.x)
	{
		wl.x = (sp->h - (sp->x_max - (double)x)) /
					sp->h * (double)set->win.skins[4].res.x;
		y = (int)sp->start.y < 0 ? (int)sp->start.y - 1 : -1;
		while (++y < sp->end.y && y < set->win.img.res.y)
		{
			wl.y = (sp->h - (sp->end.y - (double)y)) /
					sp->h * (double)set->win.skins[4].res.y;
			if ((clr = get_clr(&set->win.skins[4], (int)wl.x, (int)wl.y)))
				my_mlx_pixel_put(set, x, y, clr);
		}
	}
}

void			insert_sort(int n, t_spr **mass)
{
	t_spr		tmp;
	int			location;
	int			i;

	i = 0;
	while (++i < n && n > 1)
	{
		tmp = (*mass)[i];
		location = i - 1;
		while (location >= 0 && (*mass)[location].proj_c.y < tmp.proj_c.y)
		{
			(*mass)[location + 1] = (*mass)[location];
			location = location - 1;
		}
		(*mass)[location + 1] = tmp;
	}
}

void			draw_sprites(t_set *set)
{
	int			i;

	insert_sort(set->sprites, &set->sprs);
	i = -1;
	while (++i < set->sprites)
		if (set->sprs[i].start.x != -1)
			draw_sprite(set, &set->sprs[i]);
}

void			sprite_on(t_set *set, t_ray *ray, t_pix map)
{
	int			i;

	i = -1;
	while (++i < set->sprites)
	{
		if ((int)set->sprs[i].pos.x == map.x &&
				(int)set->sprs[i].pos.y == map.y)
		{
			set->sprs[i].end.x = ray->x;
			if (set->sprs[i].start.x != -1)
			{
				set->sprs[i].end.x = ray->x;
				continue ;
			}
			set->sprs[i].start.x = ray->x;
			set->sprs[i].proj_c = prj_to_vec(set->player.plane,
				set->player.dir, set->player.pos, set->sprs[i].pos);
			if ((fabs(set->sprs[i].proj_c.y)) < ZER)
				set->sprs[i].proj_c.y = set->sprs[i].proj_c.y > 0 ? ZER : -ZER;
			set->sprs[i].proj_c.x = (double)set->win.img.res.x / 2 *
						(1 + set->sprs[i].proj_c.x / set->sprs[i].proj_c.y);
			set->sprs[i].h = (double)set->win.img.res.y / set->sprs[i].proj_c.y;
			set->sprs[i].x_max = set->sprs[i].proj_c.x + set->sprs[i].h / 2;
		}
	}
}

void			sprites_off(t_set *set)
{
	int			i;

	i = -1;
	while (++i < set->sprites)
	{
		set->sprs[i].start.x = -1;
		set->sprs[i].proj_c.y = 1000;
	}
}
