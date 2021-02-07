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


void				set_player(t_set *set)
{
	t_fpix			ray;

	ray.x = (set->player.pos.x != -1) ? set->player.pos.x : 1;
	ray.y = (set->player.pos.y != -1) ? set->player.pos.y : 1;
	DEBUG printf("Player SET pos [%f; %f]\n",
				 set->player.pos.x, set->player.pos.y);
	my_mlx_pixel_put(set, ray.x * SCALE , ray.y * SCALE , 0xFF0000);
	while (set->map.c_map[(int)ray.y][(int)ray.x] != '1')
	{
		ray.x += cos(set->player.angle) * STEP;
		ray.y += sin(set->player.angle) * STEP;
		my_mlx_pixel_put(set, ray.x * SCALE, ray.y * SCALE, 0xFFFFFF);
	}
	DEBUG printf("Player is on\n\t[%f, %f] a=(%f)\n", set->player.pos.y, set->player.pos.x, set->player.angle);
}