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
	double 		x_min;

	sp->start.y = (double)set->win.img.res.y / set->player.hor - sp->h / 2 - 1;
	sp->end.y = (double)set->win.img.res.y / set->player.hor + sp->h / 2;
	x_min = sp->proj_c.x - sp->h / 2;
	x = (int)(sp->start.x - 1);
	while (++x < sp->x_max && x < set->win.img.res.x && x <= sp->end.x)
	{
		wl.x = (sp->h - (sp->x_max - (double)x))  /
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

//	while (++sp->start.x <= sp->end.x && sp->start.x < set->win.img.res.x)
//	{
//		if (sp->start.x < sp->xlim.x || sp->start.x > sp->xlim.y + 1)
//			continue ;
//		wl.x = (sp->h - (sp->end.x - sp->start.x)) /
//					sp->h * (double)set->win.skins[4].res.x;
//		sp->start.y = (double)set->win.img.res.y / set->player.hor -
//					sp->h / 2 - 1;
//		sp->start.y < 0 ? sp->start.y = 0 : 0;
//		while (++sp->start.y >= 0 && sp->start.y < sp->end.y &&
//					sp->start.y < set->win.img.res.y)
//		{
//			wl.y = (sp->h - (sp->end.y - sp->start.y)) /
//					sp->h * (double)set->win.skins[4].res.y;
//			if ((clr = get_clr(&set->win.skins[4], (int)wl.x, (int)wl.y)))
//				my_mlx_pixel_put(set, (int)sp->start.x, (int)sp->start.y, clr);
//		}
//	}
}

void			sort(t_set *set, int n)
{
	int			i;
	int			j;
	t_spr		p;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n - i)
		{
			if (set->sprs[j].proj_c.y < set->sprs[j + 1].proj_c.y)
			{
				p = set->sprs[j];
				set->sprs[j] = set->sprs[j + 1];
				set->sprs[j + 1] = p;
			}
		}
	}
}




void			draw_sprites(t_set *set)
{
	int			i;


	sort(set, set->sprites);
	i = -1;
	while (++i < set->sprites)
		if (set->sprs[i].start.x != -1)
			draw_sprite(set, &set->sprs[i]);
}

//static t_sl		*find_sprite(t_sl *list, t_pix map)
//{
//	t_sl		*p;
//
//	p = list;
//	while (p)
//	{
//		if ((int)p->spr.pos.x == map.x && (int)p->spr.pos.y == map.y)
//		{
//			return (p);
//		}
//		p = p->next;
//	}
//	return (NULL);
//}

void			sprite_on(t_set *set, t_ray *ray, t_pix map)
{
	int 		i;

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
			if ((fabs(set->sprs[i].proj_c.y)) < Z_VAL)
				set->sprs[i].proj_c.y = set->sprs[i].proj_c.y > 0 ? Z_VAL : -Z_VAL;
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

//void			add_sprite(t_set *set, t_ray *ray, t_pix map)
//{
//	t_sl		*p;
//	t_sl		*ns;
//
//	if ((p = find_sprite(set->sl, map)))
//		p->spr.xlim.y = ray->x;
//	ns = (t_sl *)malloc(sizeof(t_sl));
//	ns->spr.xlim = v_set(ray->x, ray->x);
//	ns->spr.proj_c = prj_to_vec(set->player.plane, set->player.dir,
//					set->player.pos, ns->spr.pos);
//	if (fabs(ns->spr.proj_c.y) < ZERO_VAL)
//		ns->spr.proj_c.y = ZERO_VAL;
//	ns->spr.dist = v_dist(set->player.pos, ns->spr.pos);
//	ns->spr.perp = fabs(ns->spr.proj_c.y);
//	ns->spr.h = (double)set->win.img.res.y / ns->spr.perp;
//	ns->spr.start.x = (double)set->win.img.res.x / 2 *
//			(1 + ns->spr.proj_c.x / ns->spr.proj_c.y) - ns->spr.h / 2;
//	ns->spr.end.x = (double)set->win.img.res.x / 2 *
//			(1 + ns->spr.proj_c.x / ns->spr.proj_c.y) + ns->spr.h / 2;
//	insert_by_in_order(&set->sl, ns);
//}
