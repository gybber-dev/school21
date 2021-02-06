#include "../ft_cub.h"

static int			is_floor(t_set *set)
{
	int				x;
	int				y;

	x = set->player.to.x / SCALE;
	y = set->player.to.y / SCALE;
	DEBUG printf("I want to jump to cell [%d, %d] = %d\n", x, y, set->map.c_map[y][x]);
	if (set->map.c_map[y][x] == '1' || set->map.c_map[y][x] == '2')
		return (0);
	DEBUG printf("\tdone\n");
	return (1);
}

//and
//Не отрисовывается каждый поворот луча
//Оставить только текущую позинию вместо to/from


void				set_player(t_set *set)
{
	t_fpix			ray;

	ray.x = (set->player.from.x != -1) ? set->player.from.x : set->player.to.x;
	ray.y = (set->player.from.y != -1) ? set->player.from.y : set->player.to.y;
	DEBUG printf("Player SET from [%d; %d] to [%d; %d]\n",
				 set->player.from.x, set->player.from.y, set->player.to.x, set->player.to.y);
	// final position is defined and it is not a start position
	if (set->player.to.x != -1 &&
		(set->player.from.x != set->player.to.x ||
		 set->player.from.y != set->player.to.y) && is_floor(set))
	{
		set->player.from.x = set->player.to.x;
		set->player.from.y = set->player.to.y;
	}
	else
	{
		set->player.to.x = set->player.from.x;
		set->player.to.y = set->player.from.y;
	}
	my_mlx_pixel_put(set, ray.x, ray.y, 0xFF0000);
	int flag = 0;
	while (set->map.c_map[(int)ray.y / SCALE][(int)ray.x / SCALE] != '1')
	{
		flag = 1;
		ray.x += cos(set->player.angle) * SCALE / 10;
		ray.y += sin(set->player.angle) * SCALE / 10;
		my_mlx_pixel_put(set, ray.x, ray.y, 0xFFFFFF);
	}
	DEBUG printf("(%d)Player is on\n\t[%d, %d] a=(%f)\n", flag, set->player.to.x, set->player.to.y, set->player.angle);
}