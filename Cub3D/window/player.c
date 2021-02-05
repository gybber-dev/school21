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

void				set_player(t_set *set)
{
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

	my_mlx_pixel_put(set, set->player.to.x, set->player.to.y, 0xFFFFFF);

	DEBUG printf("Player is on\n\t[%d, %d]\n", set->player.to.x, set->player.to.y);
}