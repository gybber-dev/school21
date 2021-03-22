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


//static void		insert_by_in_order(t_spr **list, t_spr *ns)
//{
//	t_spr		*p;
//	t_spr		*p_next;
//
//	p = *list;
//	if (*list == NULL || ns->proj_c.y >= p->proj_c.y)
//	{
//		ns->next = p;
//		*list = ns;
//		return ;
//	}
//	p_next = p->next;
//	while (p_next)
//	{
//		if (p->proj_c.y > ns->proj_c.y && ns->proj_c.y >= p_next->proj_c.y)
//		{
//			p->next = ns;
//			ns->next = p_next;
//			return ;
//		}
//		p = p_next;
//		p_next = p_next->next;
//	}
//	p->next = ns;
//	ns->next = NULL;
//}
//
//void bubbleSort(int n, t_spr **mass)
//{
//	t_spr		tmp;
//	// Для всех элементов
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = (n - 1); j > i; j--) // для всех элементов после i-ого
//		{
//			if ((*mass)[j - 1].proj_c.y < (*mass)[j].proj_c.y) // если текущий элемент меньше предыдущего
//			{
//				tmp = (*mass)[j - 1]; // меняем их местами
//				(*mass)[j - 1] = (*mass)[j];
//				(*mass)[j] = tmp;
//			}
//		}
//	}
//}
//

void InsertionSort(int n, t_spr **mass)
{

	t_spr newElement;
	int location;
	int i = 0;

	while (++i < n && n > 1)
	{
		newElement = (*mass)[i];
		location = i - 1;
		while(location >= 0 && (*mass)[location].proj_c.y < newElement.proj_c.y)
		{
			(*mass)[location + 1] = (*mass)[location];
			location = location - 1;
		}
		(*mass)[location+1] = newElement;
	}
}


void			draw_sprites0(t_set *set)
{
	while (set->sl)
	{
		draw_sprite(set, set->sl);
		set->sl = set->sl->next;
	}
}

void			draw_sprites(t_set *set)
{
	int			i;

	InsertionSort(set->sprites, &set->sprs);
//	bubbleSort(set->sprites, &set->sprs);
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
//			insert_by_in_order(&set->sl, &set->sprs[i]);
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
		set->sl = NULL;
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
