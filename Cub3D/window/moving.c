#include "../ft_cub.h"

static void		update_pos(t_fpix *to, t_set *set, int ver, int hor)
{

	if (ver)
	{
		to->x += ver * set->player.dir.x * STEP;
		to->y += ver * set->player.dir.y * STEP;
	}
	if (hor)
	{
		to->x += -STEP * hor * set->player.dir.y;
		to->y += +STEP * hor * set->player.dir.x;
	}
}

void		move_to(t_set *set)
{
	DEBUG printf("KEY MONITOR:\nW\tA\tS\tD\tL\tR\n%d\t%d\t%d\t%d\t%d\t%d\n",
				 (set->player.move >> W_BIT) & 1, (set->player.move >> A_BIT) & 1,
				 (set->player.move >> S_BIT) & 1, (set->player.move >> D_BIT) & 1,
				 (set->player.move >> LEFT_BIT) & 1, (set->player.move >> RIGHT_BIT) & 1);
	t_fpix		to;
	float		old_x;
	int			rot;

	DEBUG printf("start: {%f; %f}\n", set->player.dir.x, set->player.dir.y);
	to.x = set->player.pos.x;
	to.y = set->player.pos.y;
	if ((set->player.move >> LEFT_BIT) & 1 || (set->player.move >> RIGHT_BIT) & 1)
	{
		rot = ((set->player.move >> RIGHT_BIT) & 1 )? 1 : -1;
		old_x = set->player.dir.x;
		set->player.dir.x = set->player.dir.x * cos(rot * ANGLE_STEP) -
							set->player.dir.y * sin(rot * ANGLE_STEP);
		set->player.dir.y = old_x * sin(rot * ANGLE_STEP) +
							set->player.dir.y * cos(rot * ANGLE_STEP);
		old_x = set->player.plane.x;
		set->player.plane.x = set->player.plane.x * cos(rot * ANGLE_STEP) -
							  set->player.plane.y * sin(rot * ANGLE_STEP);
		set->player.plane.y = old_x * sin(rot * ANGLE_STEP) +
							  set->player.plane.y * cos(rot * ANGLE_STEP);
	}
	if ((set->player.move >> W_BIT) & 1)
		update_pos(&to, set, 1, 0);
	if ((set->player.move >> S_BIT) & 1)
		update_pos(&to, set, -1, 0);
	if ((set->player.move >> A_BIT) & 1)
		update_pos(&to, set, 0, -1);
	if ((set->player.move >> D_BIT) & 1)
		update_pos(&to, set, 0,  1);

	printf("to map[%d][%d]\n", (int)to.y, (int)to.x);
	if (set->map.c_map[(int)to.y][(int)to.x] != '1') add checking for cross by grid
	{
		set->player.pos.y = to.y;
		set->player.pos.x = to.x;
	}
	DEBUG printf("end: {%f; %f}\n", set->player.dir.x, set->player.dir.y);
	DEBUG printf("Player is to '%c'\n\t[%f, %f]\n", set->map.c_map[(int)to.y][(int)to.x], set->player.pos.y, set->player.pos.x);
}