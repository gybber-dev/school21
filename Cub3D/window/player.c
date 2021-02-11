#include "../ft_cub.h"

//static int			is_floor(t_set *set)
//{
//	int				x;
//	int				y;
//
//	x = set->player.to.x / SCALE;
//	y = set->player.to.y / SCALE;
//	DEBUG printf("I want to jump to cell [%d, %d] = %d\n", x, y, set->map.c_map[y][x]);
//	if (set->map.c_map[y][x] == '1' || set->map.c_map[y][x] == '2')
//		return (0);
//	DEBUG printf("\tdone\n");
//	return (1);
//}

//and
//Не отрисовывается каждый поворот луча
//Оставить только текущую позинию вместо to/from

static void			find_map_cell(t_set *set, t_pix *map)
{

}

static void			find_next_ray(t_set *set, t_fpix *ray0, t_fpix *ray1, t_pix *map)
{
	t_fpix			delta;
	t_fpix			dist;

	DEBUG printf("Player is on\n\t[%f, %f] a=(%f)\n", set->player.pos.y, set->player.pos.x, set->player.angle);
	ft_bzero(&dist, sizeof(t_fpix));
	ray1->x = (set->player.direction.x < 0) ? ray0->x - 1 : ray0->x + 1;
	ray1->y = (set->player.direction.y < 0) ? ray0->y - 1 : ray0->y + 1;


	delta.x = fabs(ray1->x - ray0->x) / cos(set->player.angle); // 1/direction.x
	delta.y = fabs(ray1->y - ray0->y) / sin(set->player.angle); // 1/direction.y

	if (delta.x < delta.y)
	{
		dist.x += delta.x;
		ray1->y = ray0->y + delta.x * sin(set->player.angle);
		map->x += set->player.step.x;
	}
	else
	{
		dist.y += delta.y;
		ray1->x = ray0->x + delta.y * cos(set->player.angle);
		map->y += set->player.step.y;
	}

}

static t_fpix		find_next_ray_pix0(t_set *set, t_fpix *ray1)
{
	int				hit;
	t_fpix			dist;
	float			distX;
	float			distY;
	float			deltaX;
	float			deltaY;

	t_pix			map;
	map.x = (int)set->player.pos.x;
	map.y = (int)set->player.pos.y;
//	deltaX = 1 / rayX
//	deltaX = !(set->player.direction.y) ? 0 :



	// init:
	deltaX = 0;
	deltaY = 0;
	distX = 0;
	distY = 0;
	int stepX = (set->player.direction.x > 0) ? 1 : -1;
	int stepY = (set->player.direction.y > 0) ? 1 : -1;
//	if (set->player.direction.x < 0)
//	{
//
//	}
//	else
//	{
//		distX = (set->player.pos.x - map.x + 1) * deltaX;
//	}
	if (distX < distY)
	{
		distX += deltaX;
	}
	else
	{
		distY += deltaY;
	}

//	hit = 0;
//	while (hit == 0)
//	{
//		if (distX < distY)
//		{
//			distX += deltaX;
//			map.x += stepX;
//		}
//		else
//		{
//			distY += deltaY;
//			map.y += stepY;
//		}
//		if (set->map.c_map[map.y][map.x] == '1')
//			hit = 1;
//	}
	dist.x = distX;
	dist.y = distY;
	return (dist);
}

void				set_player(t_set *set)
{
	t_fpix			ray0;
	t_fpix			ray1;
	t_pix			map;

	ft_bzero(&ray0, sizeof(t_fpix));
	ft_bzero(&ray1, sizeof(t_fpix));
	ray0.x = set->player.pos.x;
	ray0.y = set->player.pos.y;
	map.x = (int)set->player.pos.x;
	map.y = (int)set->player.pos.y;

	if (set->player.direction.x < 0)
	{
		set->player.step.x = -1;
	}
	else
	{
		set->player.step.x = 1;
	}
	if (set->player.direction.y < 0)
	{
		set->player.step.y = -1;
	}
	else
	{
		set->player.step.y = 1;
	}

	while (set->map.c_map[map.y][map.x] != '1')
	{
		find_next_ray(set, &ray0, &ray1, &map);
		my_mlx_pixel_put(set, ray1.x * SCALE, ray1.y * SCALE, 0xFFFFFF);
//		find_map_cell(set, &map);
	}
}


void				set_player0(t_set *set)
{
	t_fpix			ray0;
	t_fpix			ray1;
	t_fpix			sector;


//	sector.x = - M_PI / 6;
//	sector.y = M_PI / 6;
	sector.x = 0;
	sector.y = 0;
	ray0.x = (set->player.pos.x != -1) ? set->player.pos.x : 1;
	ray0.y = (set->player.pos.y != -1) ? set->player.pos.y : 1;
	DEBUG printf("Player SET pos [%f; %f]\n",
				 set->player.pos.x, set->player.pos.y);
	my_mlx_pixel_put(set, ray0.x * SCALE , ray0.y * SCALE , 0xFF0000);
//	while(sector.x <= sector.y)
//	{
////		printf("tick [%.2f > %.2f]\n", sector.x, sector.y);
//		ray.x = set->player.pos.x;
//		ray.y = set->player.pos.y;
	while (set->map.c_map[(int)ray0.y][(int)ray0.x] != '1')
	{
		ray0.x += cos(set->player.angle + sector.x) * STEP;
		ray0.y += sin(set->player.angle + sector.x) * STEP;
		my_mlx_pixel_put(set, ray0.x * SCALE, ray0.y * SCALE, 0xFFFFFF);
	}
	sector.x += M_PI / 3 / (RAYS_NUM - 1);
//	}
	DEBUG printf("Player is on\n\t[%f, %f] a=(%f)\n", set->player.pos.y, set->player.pos.x, set->player.angle);
}