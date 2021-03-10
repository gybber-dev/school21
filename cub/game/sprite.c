#include "../ft_cub.h"


/*
** Returns project of dot to m-n coordinate system with a center in d0
**				   -1
** dot_mn = [ m n ]	* [ dot ] =
**
**				n.y		-n.x		 dot.x
** 1 / det * [	-m.y	m.x		] * [dot.y]
*/

static t_fpix			prj_to_vec(t_fpix m, t_fpix n, t_fpix d0, t_fpix dot)
{
	t_fpix		proj;
	t_fpix		sub_dot;
	double		det;

	sub_dot = v_sub(dot, d0);
	det = m.x * n.y - m.y * n.x;
	proj.x = 1 / det * (n.y * sub_dot.x - n.x * sub_dot.y);
	proj.y = 1/ det * (-m.y * sub_dot.x + m.x * sub_dot.y);
	return (proj);
}

static void				draw_sprite(t_set *set, t_spr *sprite)
{
	double			h;
	t_fpix			wall;
	int				color;

	printf("player pos: %.4f; %.4f\n", set->player.pos.x, set->player.pos.y);
	h = sprite->height;
	sprite->end.y = (double)set->win.img1.res.y / set->player.hor + h / 2;
	if (sprite->pos.y == 2.5)
		sprite->pos.y = 2.5;
	sprite->start.y = (double)set->win.img1.res.y / set->player.hor - h / 2 - 1;
	sprite->start.x < 0 ? sprite->start.x = 0 : 0;
	sprite->start.y < 0 ? sprite->start.y = 0 : 0;
	while (++sprite->start.x <= sprite->end.x)
	{
		if (sprite->start.x < sprite->xlim.x || sprite->start.x > sprite->xlim.y + 1)
			continue ;
		wall.x = (h - (sprite->end.x - sprite->start.x)) /
				 h * (double)set->win.skins[4].res.x;
		sprite->start.y = (double)set->win.img1.res.y / set->player.hor - h / 2 - 1;
		sprite->start.y < 0 ? sprite->start.y = 0 : 0;
		while(++sprite->start.y >= 0 && sprite->start.y < sprite->end.y &&
			  sprite->start.y < set->win.img1.res.y)
		{
			wall.y = (h - (sprite->end.y - sprite->start.y)) /
					 h * (double)set->win.skins[4].res.y;
			color = get_color(&set->win.skins[4], (int)wall.x, (int)wall.y);
			if (color)
				my_mlx_pixel_put(set, (int)sprite->start.x, (int)sprite->start.y, color);
		}
	}
}


static void			insert_by_in_order(t_sl **list, t_sl *ns)
{
	t_sl		*p;
	t_sl		*p_next;

	if (*list == NULL)
	{
		ns->next = NULL;
		*list = ns;
		return ;
	}
	p = *list;
	if (ns->sprite.perp >= p->sprite.perp)
	{
		ns->next = p;
		*list = ns;
		return ;
	}
	p_next = p->next;
	while(p_next)
	{
		if (p->sprite.perp > ns->sprite.perp && ns->sprite.perp >= p_next->sprite.perp)
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

void				draw_sprites(t_set *set)
{
	t_sl			*p;

	while (set->sl)
	{
		draw_sprite(set, &(set->sl->sprite));
		p = set->sl;
		set->sl = set->sl->next;
		free(p);
	}
}

void			add_sprite(t_set *set, t_ray *ray, t_pix map)
{
	t_sl		*p;
	t_sl		*ns;

	p = set->sl;
	// if sprite is in struct update finish point of draw by X-axe
	while(p)
	{
		if ((int)p->sprite.pos.x == map.x && (int)p->sprite.pos.y == map.y)
		{
			p->sprite.xlim.y = ray->x;
			return ;
		}
		p = p->next;
	}
	// if sprite was not found add it:
	ns = (t_sl *)malloc(sizeof(t_sl));
	ns->sprite.pos = v_set(map.x + 0.5, map.y + 0.5);
	ns->sprite.xlim = v_set(ray->x, ray->x);
	ns->sprite.proj_c = prj_to_vec(set->player.plane, set->player.dir,
								   set->player.pos, ns->sprite.pos);
	if (fabs(ns->sprite.proj_c.y) < ZERO_VAL)
		ns->sprite.proj_c.y = ZERO_VAL;
	ns->sprite.dist = v_dist(set->player.pos, ns->sprite.pos);
	ns->sprite.perp = fabs(ns->sprite.proj_c.y);
	ns->sprite.height = (double)set->win.img1.res.y / ns->sprite.perp;
	ns->sprite.start.x = (double)set->win.img1.res.x / 2 * (1 + ns->sprite.proj_c.x / ns->sprite.proj_c.y)
						 - ns->sprite.height / 2;
	ns->sprite.end.x = (double)set->win.img1.res.x / 2 * (1 + ns->sprite.proj_c.x / ns->sprite.proj_c.y)
					   + ns->sprite.height / 2;
	insert_by_in_order(&set->sl, ns);
}