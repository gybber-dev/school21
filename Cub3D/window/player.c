#include "../ft_cub.h"


int			get_color(t_img *img, int x, int y)
{

	int			res;
	char		*dst;

	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->endian);
	dst = img->addr + y * img->len + x * (img->bpp / 8);
	res =  (*(int*)dst);
	return (res);
}


/*
** finds crossing dot of two NONPARALLEL vectors.
** It takes coordinates of two vectors, and of two dots
** lying on a line of the vectors.
** (from: https://habr.com/ru/post/523440/)
*/

t_fpix			count_rays_cross(t_fpix a, t_fpix b, t_fpix dot_a, t_fpix dot_b)
{
	t_fpix		dot_c;
	double		q;
	double		n;

	ft_bzero(&dot_c, sizeof(t_fpix));
	if (a.y != 0)
	{
		q = - a.x / a.y;
		n = ((dot_b.x - dot_a.x) + q * (dot_b.y - dot_a.y)) /
				(b.x + b.y * q);
	}
	else if (b.y != 0)
		n = (dot_b.y - dot_a.y) / b.y;
	else
		ft_error(PARALLEL_VECTORS_NOT_CROSS);
	dot_c.x = dot_b.x - n * b.x;
	dot_c.y = dot_b.y - n * b.y;
	return (dot_c);
}


/*
** Returns project of dot to m-n coordinate system with a center in d0
**				   -1
** dot_mn = [ m n ]	* [ dot ] =
**
**				n.y		-n.x		 dot.x
** 1 / det * [	-m.y	m.x		] * [dot.y]
*/

t_fpix			prj_to_vec(t_fpix m, t_fpix n, t_fpix d0, t_fpix dot)
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


int				put_sprite_pix(t_sprite *sprite, t_set *set, t_ray *ray, int y)
{
	int 		color;

	if (y > sprite->strip.x && y < sprite->strip.y)
	{
		sprite->wall.y = (int)(((double)y - (double)sprite->strip.x) * (double)set->win.skins[4].res.y / (double)sprite->h);
		color = get_color(&set->win.skins[4], sprite->wall.x, sprite->wall.y);
		if (color)
		{
			my_mlx_pixel_put(set, ray->x, y, color);
			return (1);
		}
	}
	return (0);
}

void				draw_sprite(t_set *set, t_spr *sprite)
{
	double			h;
	double			proj_ray;
//	t_pix			height;
	t_fpix			wall;
	int				color;

	h = sprite->height;
	sprite->end.y = (double)set->win.img1.res.y / set->player.hor + h / 2;
	if (sprite->pos.y == 2.5)
		sprite->pos.y = 2.5;
//	proj_ray = sqrt(pow(sprite->dist, 2) - pow(sprite->perp, 2));
//	sprite->start.x = (double)set->win.img1.res.x / 2 - h / 2 - proj_ray;
	sprite->start.x--;
	while (++sprite->start.x <= sprite->end.x)
	{
		if (sprite->start.x < sprite->xlim.x || sprite->start.x > sprite->xlim.y)
			continue ;
		wall.x = (h - (sprite->end.x - sprite->start.x)) /
				h * (double)set->win.skins[4].res.x;
		sprite->start.y = (double)set->win.img1.res.y / set->player.hor - h / 2;
		while(sprite->start.y > 0 && sprite->start.y < sprite->end.y &&
				sprite->end.y < set->win.img1.res.y)
		{
			wall.y = (h - (sprite->end.y - sprite->start.y)) /
				h * (double)set->win.skins[4].res.y;
			color = get_color(&set->win.skins[4], (int)wall.x, (int)wall.y);
			if (color)
				my_mlx_pixel_put(set, (int)sprite->start.x, (int)sprite->start.y, color);
			sprite->start.y += 1;
		}
//		sprite->start.x += 1;
	}
}

void				draw_sprites(t_set *set)
{
	t_sl			*p;

	// clear list
	p = set->sl;
	while (set->sl)
	{
		draw_sprite(set, &(set->sl->sprite));
		p = set->sl;
		set->sl = set->sl->next;
		free(p);
	}
}


/*
** returns 1 if sprite pixel was drawn and 0 if
** it was nothing to draw.
*/

int				draw_sprite0(t_set *set, t_ray *ray, int y)
{
	t_sprite	*p;
	int			res;

	res = 0;
	if (!ray->slist)
		return (res);
	p = ray->slist;
	while(p)
	{
		res = put_sprite_pix(p, set, ray, y);
		p = p->next;
	}
	while (y == set->win.img1.res.y && ray->slist)
	{
		p = ray->slist;
		ray->slist = ray->slist->next;
		free(p);
	}
	return (res);
}


void			insert_by_in_order(t_sl **list, t_sl *ns)
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
		if (p->sprite.perp < ns->sprite.perp && ns->sprite.perp <= p_next->sprite.perp)
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


void			add_sprite1(t_set *set, t_ray *ray, t_pix map)
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
	ns->sprite.dist = v_dist(set->player.pos, ns->sprite.pos);
	ns->sprite.perp = fabs(ns->sprite.proj_c.y);
	ns->sprite.height = (double)set->win.img1.res.y / ns->sprite.perp;
//	ns->sprite.height = (double)set->win.skins[4].res.y / ns->sprite.perp;
	ns->sprite.start.x = (double)set->win.img1.res.x / 2 * (1 + ns->sprite.proj_c.x / ns->sprite.proj_c.y)
			- ns->sprite.height / 2;
	ns->sprite.end.x = (double)set->win.img1.res.x / 2 * (1 + ns->sprite.proj_c.x / ns->sprite.proj_c.y)
			+ ns->sprite.height / 2;
	insert_by_in_order(&set->sl, ns);
//	p = set->sl;
//	while(p && (ns->sprite.perp < p->sprite.perp))
//		p = p->next;
//	ns->next = p->next;
//	p->next = ns;
//	set->sl = ns;
}


void			add_sprite(t_set *set, t_ray *ray, t_pix map)
{
	t_sprite	*p;
	t_sprite	*ns;
	t_fpix		spr_plane;
	t_fpix		cross;
	t_fpix		pos;

	spr_plane.x = -set->player.dir.y;
	spr_plane.y = set->player.dir.x;
	pos.x = map.x + 0.5;
	pos.y = map.y + 0.5;
	cross = count_rays_cross(ray->dir, spr_plane, set->player.pos, pos);
	if ((int)cross.x == (int)pos.x && (int)cross.y == (int)pos.y)
	{
		ns = (t_sprite *)malloc(sizeof(t_sprite));
		if (ns == NULL)
			ft_error(errno);
		ns->next = NULL;
		ns->pos.x = pos.x;
		ns->pos.y = pos.y;
		ns->side = ray->side;
		// distention between player position and a center of the sprite
		ns->dist = sqrt(pow(set->player.pos.x - cross.x, 2) + pow(set->player.pos.y - cross.y, 2));

		ns->h = (double) set->win.img1.res.y / ns->dist;
		ns->strip.x = (int) ((double) set->win.img1.res.y / set->player.hor - ns->h / 2);
		ns->strip.y = (int) ((double) set->win.img1.res.y / set->player.hor + ns->h / 2);
		ns->wall.x = (ns->side % 2) ?
				 (int) ((set->win.skins[4].res.y - 1) * fmod(cross.x, 1.0)) :
				 (int) ((set->win.skins[4].res.y - 1) * (1 - fmod(cross.y, 1.0)));
		// add to the front:
//		if (ray->slist != NULL)
//			printf("not empty\n");
		p = ray->slist;
		ns->next = p;
		ray->slist = ns;
	}
}

/*
** It seems the height of objects should be larger when
** player sits, and smaller when player jumps
** k is a variable that contains the range of scale when
** player sits/jumps
*/

void				draw_strip(t_set *set, t_ray *ray)
{
	double			h;
	t_pix			strip;
	t_pix			wall;
	double			k;
	int				y;

	h = (double)set->win.img1.res.y / ray->perp;
	strip.x = (int)((double)set->win.img1.res.y / set->player.hor - h / 2);
	strip.y = (int)((double)set->win.img1.res.y / set->player.hor + h / 2);
	wall.x = (ray->side % 2) ?
		(int)((set->win.skins[ray->side].res.y - 1) * fmod(ray->cross.x, 1.0)) :
		(int)((set->win.skins[ray->side].res.y - 1) * (1 - fmod(ray->cross.y, 1.0)));
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
		ray->cross.x = (ray->dir.x < 0) ?
				   map.x + set->player.step.x + 1 : map.x + set->player.step.x;
		ray->cross.y = (ray->dir.y < 0) ?
				   map.y + set->player.step.y + 1 : map.y + set->player.step.y;
		dist.x = (ray->dir.x == 0) ? dist.x + 1 :
				 fabs((ray->cross.x - set->player.pos.x) / (ray->dir.x / v_len(ray->dir)));
		dist.y = (ray->dir.y == 0) ? dist.y + 1 :
				 fabs((ray->cross.y - set->player.pos.y) / (ray->dir.y / v_len(ray->dir)));
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
		{
			add_sprite1(set, ray, map);
//			add_sprite(set, ray, map);
		}
		my_mlx_pixel_put(set, (int)(ray->cross.x * SCALE), (int)(ray->cross.y) * SCALE, 0xFF0000);
	}
//	ray->dist = dist.x < dist.y ? dist.x : dist.y;
}


void				 drop_rays(t_set *set)
{
	t_ray			ray;
	double			cam;

	ray.x = 0;
	while (ray.x < set->win.img1.res.x)
	{
		ray.slist = NULL;
		cam = 2 * ray.x / (double)set->win.img1.res.x - 1;
		ray.dir.x = set->player.dir.x + cam * set->player.plane.x;
		ray.dir.y = set->player.dir.y + cam * set->player.plane.y;
		count_ray_len(set, &ray);
		ray.perp = ray.dist * v_mult(ray.dir, set->player.dir)/v_len(set->player.dir) / v_len(ray.dir);
		draw_strip(set, &ray);
		ray.x++;
	}
	printf("hello\n");
	draw_sprites(set);
}

int				display_img(t_set *set)
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
