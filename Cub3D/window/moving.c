#include "../ft_cub.h"

static void		update_pos(t_fpix *to, float angle)
{
	to->y += sin(angle) * STEP;
	to->x += cos(angle) * STEP;
}

void		move_to(t_set *set)
{
	DEBUG printf("KEY MONITOR:\nW\tA\tS\tD\tL\tR\n%d\t%d\t%d\t%d\t%d\t%d\n",
				 (set->player.move >> W_BIT) & 1, (set->player.move >> A_BIT) & 1,
				 (set->player.move >> S_BIT) & 1, (set->player.move >> D_BIT) & 1,
				 (set->player.move >> LEFT_BIT) & 1, (set->player.move >> RIGHT_BIT) & 1);

	t_fpix		to;
	ft_bzero(&to, sizeof(t_fpix));
	to.y = set->player.pos.y;
	to.x = set->player.pos.x;
	if ((set->player.move >> LEFT_BIT) & 1)
		set->player.angle -= ANGLE_STEP;
	if ((set->player.move >> RIGHT_BIT) & 1)
		set->player.angle += ANGLE_STEP;
	if ((set->player.move >> W_BIT) & 1)
		update_pos(&to, set->player.angle);
	if ((set->player.move >> S_BIT) & 1)
		update_pos(&to, set->player.angle + M_PI);
	if ((set->player.move >> A_BIT) & 1)
		update_pos(&to, set->player.angle - M_PI_2);
	if ((set->player.move >> D_BIT) & 1)
		update_pos(&to, set->player.angle + M_PI_2);
	if (set->map.c_map[(int)to.y][(int)to.x] != '1')
	{
		set->player.pos.y = to.y;
		set->player.pos.x = to.x;
	}
	DEBUG printf("Player is to '%c'\n\t[%f, %f] a=(%f)\n", set->map.c_map[(int)to.y][(int)to.x], set->player.pos.y, set->player.pos.x, set->player.angle);
}