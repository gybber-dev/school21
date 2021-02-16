#include "../ft_cub.h"

/*
** move |= 1 << N // sets N-th bit in move to 1.
*/

int				key_hook_up(int keycode, t_set *set)
{
	DEBUG printf("[%d] key up\n", keycode);
	if (keycode == W || keycode == UP)
		set->player.move &= ~(1 << W_BIT);
	if (keycode == S || keycode == DOWN)
		set->player.move &= ~(1 << S_BIT);
	if (keycode == A )
		set->player.move &= ~(1 << A_BIT);
	if (keycode == D)
		set->player.move &= ~(1 << D_BIT);
	if (keycode == LEFT)
		set->player.move &= ~(1 << LEFT_BIT);
	if (keycode == RIGHT)
		set->player.move &= ~(1 << RIGHT_BIT);
	if (keycode == C)
		set->player.move &= ~(1 << C_BIT);
	move_to(set);

	mlx_destroy_image(set->win.mlx, set->win.img1.img);
	set->win.img1.img = mlx_new_image(set->win.mlx, set->win.img1.res.x, set->win.img1.res.y);
	set->win.img1.addr = mlx_get_data_addr(set->win.img1.img, &set->win.img1.bpp,
										   &set->win.img1.len, &set->win.img1.endian);
	draw_map(set);
	set_player(set);
	mlx_put_image_to_window(set->win.mlx, set->win.win, set->win.img1.img, 0, 0);
	return (1);
}

/*
** move &= ~(1 << N) // sets N-th bit in move to 0.
*/

int				key_hook_press(int keycode, t_set *set)
{
	DEBUG printf("[%d] key press\n", keycode);
	if (keycode == W || keycode == UP)
		set->player.move |= 1 << W_BIT;
	if (keycode == S || keycode == DOWN)
		set->player.move |= 1 << S_BIT;
	if (keycode == A )
		set->player.move |= 1 << A_BIT;
	if (keycode == D)
		set->player.move |= 1 << D_BIT;
	if (keycode == LEFT)
		set->player.move |= 1 << LEFT_BIT;
	if (keycode == RIGHT)
		set->player.move |= 1 << RIGHT_BIT;
	if (keycode == C)
		set->player.move |= 1 << C_BIT;
	move_to(set);
	mlx_destroy_image(set->win.mlx, set->win.img1.img);
	set->win.img1.img = mlx_new_image(set->win.mlx, set->win.img1.res.x, set->win.img1.res.y);
	set->win.img1.addr = mlx_get_data_addr(set->win.img1.img, &set->win.img1.bpp,
										   &set->win.img1.len, &set->win.img1.endian);
	draw_map(set);
	set_player(set);
	mlx_put_image_to_window(set->win.mlx, set->win.win, set->win.img1.img, 0, 0);
	return (1);
}

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
	DEBUG printf("KEY MONITOR:\nW\tA\tS\tD\tL\tR\tC\tSP\n%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
				 (set->player.move >> W_BIT) & 1, (set->player.move >> A_BIT) & 1,
				 (set->player.move >> S_BIT) & 1, (set->player.move >> D_BIT) & 1,
				 (set->player.move >> LEFT_BIT) & 1, (set->player.move >> RIGHT_BIT) & 1,
				 (set->player.move >> C_BIT) & 1, (set->player.move >> SPACE_BIT) & 1);
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
	set->player.hor = ((set->player.move >> C_BIT) & 1) ? HOR_SIT : HOR;
//	set->player.hor = (((set->player.move >> SPACE_BIT) & 1) &&
//			!((set->player.move >> C_BIT))) ? HOR_JUMP : HOR;
	printf("to map[%d][%d]\n", (int)to.y, (int)to.x);

	if (set->map.c_map[(int)to.y][(int)to.x] == '0')
	{
		set->player.pos.y = to.y;
		set->player.pos.x = to.x;
	}
	DEBUG printf("end: {%f; %f}\n", set->player.dir.x, set->player.dir.y);
	DEBUG printf("Player is to '%c'\n\t[%f, %f]\n", set->map.c_map[(int)to.y][(int)to.x], set->player.pos.y, set->player.pos.x);
}