#include "../ft_cub.h"

static void		update_pos(t_fpix *to, float angle)
{
	to->y += sin(angle) * STEP;
	to->x += cos(angle) * STEP;
}

void		move_to(t_set *set)
{
	DEBUG printf("KEY MONITOR:\nW\tA\tS\tD\tL\tR\n%d\t%d\t%d\t%d\t%d\t%d\n",
			  set->player.w, set->player.a, set->player.s, set->player.d, set->player.left,
			  set->player.right);
	t_fpix		to;

	ft_bzero(&to, sizeof(t_fpix));
	to.y = set->player.pos.y;
	to.x = set->player.pos.x;
	if (set->player.left)
		set->player.angle -= ANGLE_STEP;
	if (set->player.right)
		set->player.angle += ANGLE_STEP;
	if (set->player.w)
		update_pos(&to, set->player.angle);
	if (set->player.s)
		update_pos(&to, set->player.angle + M_PI);
	if (set->player.a)
		update_pos(&to, set->player.angle - M_PI_2);
	if (set->player.d)
		update_pos(&to, set->player.angle + M_PI_2);
	if (set->map.c_map[(int)to.y][(int)to.x] != '1')
	{
		set->player.pos.y = to.y;
		set->player.pos.x = to.x;
	}
	DEBUG printf("Player is to '%c'\n\t[%f, %f] a=(%f)\n", set->map.c_map[(int)to.y][(int)to.x], set->player.pos.y, set->player.pos.x, set->player.angle);
}