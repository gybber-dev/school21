#include "../ft_cub.h"

static void			find_map_cell(t_set *set, t_pix *map)
{

}


// ======================================================
// \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/



void 		find_next_ray(t_set *set, t_fpix *ray_dir)
{
	t_pix			map;
	t_fpix			dist;
	t_fpix			delta;
	t_fpix			ray;

	ft_bzero(&dist, sizeof(t_fpix));
	ft_bzero(&ray, sizeof(t_fpix));
	ft_bzero(&delta, sizeof(t_fpix));
	map.x = (int)set->player.pos.x;
	map.y = (int)set->player.pos.y;

	float r = sqrt(pow(ray_dir->x, 2) + pow(ray_dir->y, 2));

	if (ray_dir->y == 0)
		delta.x = 0;
	else
		delta.x = ray_dir->x == 0 ? 1 : fabs(r/ray_dir->x);
	if (ray_dir->x == 0)
		delta.y = 0;
	else
		delta.y = ray_dir->y == 0 ? 1 : fabs(r/ray_dir->y);

	if (ray_dir->x < 0)
		dist.x = (set->player.pos.x - map.x) * delta.x;
	else
		dist.x = (map.x + 1 - set->player.pos.x) * delta.x;
	if (ray_dir->y < 0)
		dist.y = (set->player.pos.y - map.y) * delta.y;
	else
		dist.y = (map.y + 1 - set->player.pos.y) * delta.y;
	set->player.step.x = (ray_dir->x < 0) ? -1 : 1;
	set->player.step.y = (ray_dir->y < 0) ? -1 : 1;
	my_mlx_pixel_put(set, set->player.pos.x * SCALE , set->player.pos.y * SCALE , 0x00FF00);
	printf("ray_dir: {%f, %f}\n", ray_dir->x, ray_dir->y);
	while (set->map.c_map[map.y][map.x] != '1')
	{
		printf("distY: %f, distX: %f\t", dist.y, dist.x);
		if (dist.x < dist.y)
		{
			ray.x = set->player.pos.x + dist.x;
			ray.y = set->player.pos.y + dist.x * ray_dir->y / ray_dir->x;
			dist.x += delta.x;
			map.x += set->player.step.x;
		}
		else
		{
			ray.y = set->player.pos.y + dist.y;
			ray.x = set->player.pos.x + dist.y* ray_dir->x / ray_dir->y;
			dist.y += delta.y;
			map.y += set->player.step.y;
		}
		printf("ray: [%f, %f]\n", ray.y, ray.x);
		my_mlx_pixel_put(set, (int)(ray.x * SCALE), (int)(ray.y * SCALE), 0xFF0000);
//		find_map_cell(set, &map);
	}
	printf("hit to cell [%d, %d]\n", map.y, map.x);
}

void				set_player2(t_set *set)
{
	int				x;
	double			cameraX;
	t_fpix			ray_dir;

//	x = 0;
	x = set->win.res1 / 2;
	while (x < set->win.res1)
	{
		cameraX = 2 * x / (double)set->win.res1 - 1;
		ray_dir.x = set->player.direction.x + cameraX * set->player.plane.x;
		ray_dir.y = set->player.direction.y + cameraX * set->player.plane.y;
		find_next_ray(set, &ray_dir);
		x++;
		break ;
	}
}

// /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\
// ===============================================

static void			find_next_ray0(t_set *set, t_fpix *ray0, t_fpix *ray1, t_pix *map)
{
	t_fpix			delta;
	t_fpix			dist;

	DEBUG printf("Player is on\n\t[%f, %f]\nsin(%f) = %f\ncos(%f) = %f\n", set->player.pos.y, set->player.pos.x, set->player.angle, sin(set->player.angle), set->player.angle, cos(set->player.angle));
	ft_bzero(&dist, sizeof(t_fpix));
	if (set->player.direction.x < 0)
		ray1->x = map->x + set->player.step.x + 1;
	else
		ray1->x = map->x + set->player.step.x;
	if (set->player.direction.y < 0)
		ray1->y = map->y + set->player.step.y + 1;
	else
		ray1->y = map->y + set->player.step.y;

//	printf("tick0\n");
	if (cos(set->player.angle) == 0)
		delta.x = 1;
	else
		delta.x = fabs((ray1->x - ray0->x) / cos(set->player.angle)); // 1/direction.x
	if (sin(set->player.angle) == 0)
		delta.y = 1;
	else
		delta.y = fabs((ray1->y - ray0->y) / sin(set->player.angle)); // 1/direction.y
	printf("deltaX: %f\tdeltaY: %f\n", delta.x, delta.y);
	if (delta.x < delta.y)
	{
		dist.x += delta.x;
		ray1->y = ray0->y + delta.x * sin(set->player.angle);
		map->x += set->player.step.x;
		printf("hit to cell [%d, %d]\t(%c)\n", map->y, map->x, set->map.c_map[map->y][map->x]);
	}
	else
	{
		dist.y += delta.y;
		ray1->x = ray0->x + delta.y * cos(set->player.angle);
		map->y += set->player.step.y;
		printf("hit to cell [%d, %d]\t(%c)\n", map->y, map->x, set->map.c_map[map->y][map->x]);
	}

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
	my_mlx_pixel_put(set, (int)(set->player.pos.x * SCALE), (int)(set->player.pos.y * SCALE), 0x00FF00);
	while (set->map.c_map[map.y][map.x] != '1')
	{
		find_next_ray0(set, &ray0, &ray1, &map);
		my_mlx_pixel_put(set, ray1.x * SCALE, ray1.y * SCALE, 0xFF0000);
//		find_map_cell(set, &map);
	}
	DEBUG printf("hit to cell [%d, %d]\n", map.y, map.x);
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
		printf("tick3\n");
	}
	sector.x += M_PI / 3 / (RAYS_NUM - 1);
//	}
	DEBUG printf("Player is on\n\t[%f, %f] a=(%f)\n", set->player.pos.y, set->player.pos.x, set->player.angle);
}