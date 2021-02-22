#include "../ft_cub.h"

void			reset_sprite(t_sprite *sprite)
{
	sprite->num = 0;


}

//void			draw_sprite(t_set *set, t_sprite *sprite)
//{
//
//}



int			get_color(t_img *img, int x, int y)
{

	int			res;
	char		*dst;
	char		*addr;

	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->endian);
	dst = img->addr + y * img->len + x * (img->bpp / 8);
	res =  (*(int*)dst);
	return (res);

//	int			res;
//	char		*dst;
//	set->win.skins[side].addr = mlx_get_data_addr(set->win.skins[side].img,
//												  &set->win.skins[side].bpp, &set->win.skins[side].len,
//												  &set->win.skins[side].endian);
//	dst = set->win.skins[side].addr + y * set->win.skins[side].len +
//		  x * (set->win.skins[side].bpp / 8);
	res =  (*(int*)dst);
}

/*
** It seems the height of objects should be larger when
** player sits, and smaller when player jumps
** k is a variable that contains the range of scale when
** player sits/jumps
*/

void				draw_strip(t_set *set, double dist, int x, t_fpix *cross, int side, t_sprite *sprite)
{
	double			h;
	t_pix			strip;
	t_pix			wall;
	double			k;
	double			y;
	int				col;

	k = set->player.hor / HOR;
	h = (double)set->win.img1.res.y / dist * k;

	strip.x = (int)((double)set->win.img1.res.y / set->player.hor - h / 2);
	strip.y = (int)((double)set->win.img1.res.y / set->player.hor + h / 2);
	if (side % 2) // != 0
		wall.x = (int)((set->win.skins[side].res.y - 1) * fmod(cross->x, 1.0));
	else
		wall.x = (int)((set->win.skins[side].res.y - 1) * (1 - fmod(cross->y, 1.0)));
	y = 0;
	while(y < set->win.img1.res.y)
	{
		if (y < strip.x)
			my_mlx_pixel_put(set, x, (int)y, set->skin.ce_col);
		else if (y > strip.x && y < strip.y)
		{
			wall.y = (int)((y - (double)strip.x) * (double)set->win.skins[side].res.y / (double)h);
			col = get_color(&set->win.skins[side], wall.x, wall.y);
			if (col == 0)
				printf("col: %d\n", col);
			my_mlx_pixel_put(set, x, (int)y, col);
		}
		else if (y > strip.y)
			my_mlx_pixel_put(set, x, (int)y, set->skin.fl_col);
		else if (sprite->num)
			sprite->num++;
//			printf("%d\n", sprite->num);
//			draw_sprite(set, sprite);
		y++;
	}
}

/*
** counts the ray length and (optionally) put pixel in a
** cross of the ray and grid. Counts side of wall:
** 0 - EA, 1 - NO, 2, - WE, 3 - SO
*/

static double		count_ray_len(t_set *set, t_fpix *ray_dir, t_fpix *cross, int *side, t_sprite *sprite)
{
	t_fpix			dist;
	t_pix			map;

	set->player.step.x = (ray_dir->x < 0) ? -1 : 1;
	set->player.step.y = (ray_dir->y < 0) ? -1 : 1;
	map.x = (int)set->player.pos.x;
	map.y = (int)set->player.pos.y;
	while (set->map.c_map[map.y][map.x] != '1')
	{
		cross->x = (ray_dir->x < 0) ?
				   map.x + set->player.step.x + 1 : map.x + set->player.step.x;
		cross->y = (ray_dir->y < 0) ?
				   map.y + set->player.step.y + 1 : map.y + set->player.step.y;
		dist.x = (ray_dir->x == 0) ? dist.x + 1 :
				 fabs((cross->x - set->player.pos.x) / (ray_dir->x / v_len(*ray_dir)));
		dist.y = (ray_dir->y == 0) ? dist.y + 1 :
				 fabs((cross->y - set->player.pos.y) / (ray_dir->y / v_len(*ray_dir)));
		if (dist.x < dist.y)
		{
			cross->y = set->player.pos.y + dist.x * ray_dir->y / v_len(*ray_dir);
			map.x += set->player.step.x;
			*side = (ray_dir->x < 0) ? 2 : 0;
		}
		else
		{
			cross->x = set->player.pos.x + dist.y * ray_dir->x / v_len(*ray_dir);
			map.y += set->player.step.y;
			*side = (ray_dir->y < 0) ? 1 : 3;
		}
		if (set->map.c_map[map.y][map.x] == '2')
		{
			sprite->num++;
		}
		my_mlx_pixel_put(set, (int)(cross->x * SCALE), (int)(cross->y) * SCALE, 0xFF0000);
	}
	return (dist.x < dist.y ? dist.x : dist.y);
}


void				drop_rays(t_set *set)
{
	int				x;
	double			dist;
	t_sprite		sprite;

	double			cameraX;
	t_fpix			ray_dir;
	double			perp_dist;
	t_fpix			cross;
	int				side;

	x = 0;
	reset_sprite(&sprite);
	while (x < set->win.img1.res.x)
	{
		cameraX = 2 * x / (double)set->win.img1.res.x - 1;
		ray_dir.x = set->player.dir.x + cameraX * set->player.plane.x;
		ray_dir.y = set->player.dir.y + cameraX * set->player.plane.y;
		dist = count_ray_len(set, &ray_dir, &cross, &side, &sprite);
		perp_dist = dist * v_mult(ray_dir, set->player.dir)/v_len(set->player.dir) / v_len(ray_dir);
//		if (sprite.num)
//			printf("hello\n");
		draw_strip(set, perp_dist, x, &cross, side, &sprite);
		reset_sprite(&sprite);
		x++;
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
