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
	float		old_plane_x;
	int			rot;

	DEBUG printf("start: {%f; %f}\n", set->player.dir.x, set->player.dir.y);
	to.x = set->player.pos.x;
	to.y = set->player.pos.y;
	old_plane_x = set->player.plane.x;
	if ((set->player.move >> LEFT_BIT) & 1 || (set->player.move >> RIGHT_BIT) & 1)
	{
		rot = ((set->player.move >> RIGHT_BIT) & 1 )? 1 : -1;
		set->player.angle += rot * ANGLE_STEP;
		set->player.dir.x = v_len(set->player.dir) * cos(set->player.angle);
		set->player.dir.y = v_len(set->player.dir) * sin(set->player.angle);
		set->player.plane.x = set->player.plane.x * cos(rot * ANGLE_STEP) -
							  set->player.plane.y * sin(rot * ANGLE_STEP);
		set->player.plane.y = old_plane_x * sin(rot * ANGLE_STEP) +
							  set->player.plane.y * cos(rot * ANGLE_STEP);
//		set->player.plane.x = vector_len(set->player.plane) * cos(set->player.angle);
//		set->player.plane.y = vector_len(set->player.plane) * sin(set->player.angle);
	}
	if ((set->player.move >> W_BIT) & 1)
		update_pos(&to, set->player.angle);
	if ((set->player.move >> S_BIT) & 1)
		update_pos(&to, set->player.angle + M_PI);
	if ((set->player.move >> A_BIT) & 1)
		update_pos(&to, set->player.angle - M_PI_2);
	if ((set->player.move >> D_BIT) & 1)
		update_pos(&to, set->player.angle + M_PI_2);



	printf("to map[%d][%d]\n", (int)to.y, (int)to.x);
	if (set->map.c_map[(int)to.y][(int)to.x] != '1')
	{
		set->player.pos.y = to.y;
		set->player.pos.x = to.x;
	}
	DEBUG printf("end: {%f; %f}\n", set->player.dir.x, set->player.dir.y);
	DEBUG printf("Player is to '%c'\n\t[%f, %f] a=(%f)\n", set->map.c_map[(int)to.y][(int)to.x], set->player.pos.y, set->player.pos.x, set->player.angle);
}