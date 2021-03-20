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

/*
** Returns project of dot to m-n coordinate system with a center in d0
**				   -1
** dot_mn = [ m n ]	* [ dot ] =
**
**				n.y		-n.x		 dot.x
** 1 / det * [	-m.y	m.x		] * [dot.y]
*/

static void		draw_sprite(t_set *set, t_spr *sp)
{
	t_fpix		wl;
	int			clr;

	sp->end.y = (double)set->win.img.res.y / set->player.hor + sp->h / 2;
	sp->start.y = (double)set->win.img.res.y / set->player.hor - sp->h / 2 - 1;
	sp->start.x < 0 ? sp->start.x = 0 : 0;
	sp->start.y < 0 ? sp->start.y = 0 : 0;
	while (++sp->start.x <= sp->end.x && sp->start.x < set->win.img.res.x)
	{
		if (sp->start.x < sp->xlim.x || sp->start.x > sp->xlim.y + 1)
			continue ;
		wl.x = (sp->h - (sp->end.x - sp->start.x)) /
					sp->h * (double)set->win.skins[4].res.x;
		sp->start.y = (double)set->win.img.res.y / set->player.hor -
					sp->h / 2 - 1;
		sp->start.y < 0 ? sp->start.y = 0 : 0;
		while (++sp->start.y >= 0 && sp->start.y < sp->end.y &&
					sp->start.y < set->win.img.res.y)
		{
			wl.y = (sp->h - (sp->end.y - sp->start.y)) /
					sp->h * (double)set->win.skins[4].res.y;
			if ((clr = get_clr(&set->win.skins[4], (int)wl.x, (int)wl.y)))
				my_mlx_pixel_put(set, (int)sp->start.x, (int)sp->start.y, clr);
		}
	}
}

static void		insert_by_in_order(t_sl **list, t_sl *ns)
{
	t_sl		*p;
	t_sl		*p_next;

	p = *list;
	if (*list == NULL || ns->spr.perp >= p->spr.perp)
	{
		ns->next = p;
		*list = ns;
		return ;
	}
	p_next = p->next;
	while (p_next)
	{
		if (p->spr.perp > ns->spr.perp && ns->spr.perp >= p_next->spr.perp)
		{
			p->next = ns;
			ns->next = p_next;
			return ;
		}
		p = p_next;
		p_next = p_next->next;
	}
	p->next = ns;
	ns->next = NULL;
}

void			draw_sprites(t_set *set)
{
	t_sl		*p;

	while (set->sl)
	{
		draw_sprite(set, &(set->sl->spr));
		p = set->sl;
		set->sl = set->sl->next;
		free(p);
	}
}

static t_sl		*find_sprite(t_sl *list, t_pix map)
{
	t_sl		*p;

	p = list;
	while (p)
	{
		if ((int)p->spr.pos.x == map.x && (int)p->spr.pos.y == map.y)
		{
			return (p);
		}
		p = p->next;
	}
	return (NULL);
}

void			add_sprite(t_set *set, t_ray *ray, t_pix map)
{
	t_sl		*p;
	t_sl		*ns;

	if ((p = find_sprite(set->sl, map)))
		p->spr.xlim.y = ray->x;
	ns = (t_sl *)malloc(sizeof(t_sl));
	ns->spr.pos = v_set(map.x + 0.5, map.y + 0.5);
	ns->spr.xlim = v_set(ray->x, ray->x);
	ns->spr.proj_c = prj_to_vec(set->player.plane, set->player.dir,
					set->player.pos, ns->spr.pos);
	if (fabs(ns->spr.proj_c.y) < ZERO_VAL)
		ns->spr.proj_c.y = ZERO_VAL;
	ns->spr.dist = v_dist(set->player.pos, ns->spr.pos);
	ns->spr.perp = fabs(ns->spr.proj_c.y);
	ns->spr.h = (double)set->win.img.res.y / ns->spr.perp;
	ns->spr.start.x = (double)set->win.img.res.x / 2 *
			(1 + ns->spr.proj_c.x / ns->spr.proj_c.y) - ns->spr.h / 2;
	ns->spr.end.x = (double)set->win.img.res.x / 2 *
			(1 + ns->spr.proj_c.x / ns->spr.proj_c.y) + ns->spr.h / 2;
	insert_by_in_order(&set->sl, ns);
}
