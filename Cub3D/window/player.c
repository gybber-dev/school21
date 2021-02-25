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
	t_fpix		c;
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



//	spr_plane is perp to set.player.dir



//	h = (double)set->win.img1.res.y / ray->perp;
//	my_mlx_pixel_put(set, ray->x, (int)y, get_color(&set->win.skins[ray->side], wall.x, wall.y));
	return (0);

}

/*
** returns 1 if sprite pixel was drawn and 0 if
** it was nothing to draw.
*/

int				draw_sprite(t_set *set, t_ray *ray, int y)
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
//		printf("%f\n", y);
		if (!draw_sprite(set, ray, (int)y))
		{
			if (y < strip.x)
				my_mlx_pixel_put(set, ray->x, (int)y, set->skin.ce_col);
			else if (y > strip.x && y < strip.y)
			{
				wall.y = (int)((y - (double)strip.x) * (double)set->win.skins[ray->side].res.y / (double)h);
				my_mlx_pixel_put(set, ray->x, (int)y, get_color(&set->win.skins[ray->side], wall.x, wall.y));
			}
			else if (y > strip.y)
				my_mlx_pixel_put(set, ray->x, (int)y, set->skin.fl_col);
		}
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
		if (set->map.c_map[map.y][map.x] == '2')
		{
//			if (ray->slist != NULL)
//				printf("not empty\n");
			add_sprite(set, ray, map);
		}
		my_mlx_pixel_put(set, (int)(ray->cross.x * SCALE), (int)(ray->cross.y) * SCALE, 0xFF0000);
	}
	ray->dist = dist.x < dist.y ? dist.x : dist.y;
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
//		if (sprite.num)
//			printf("hello\n");
		draw_strip(set, &ray);
		ray.x++;
	}

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
