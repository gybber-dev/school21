/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:38:10 by yeschall          #+#    #+#             */
/*   Updated: 2021/03/10 16:38:14 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub.h"

/*
** move |= 1 << N // sets N-th bit in move to 1.
*/

int				key_hook_up(int keycode, t_set *set)
{
	if (keycode == W || keycode == UP)
		set->player.move &= ~(1 << W_BIT);
	if (keycode == S || keycode == DOWN)
		set->player.move &= ~(1 << S_BIT);
	if (keycode == A)
		set->player.move &= ~(1 << A_BIT);
	if (keycode == D)
		set->player.move &= ~(1 << D_BIT);
	if (keycode == LEFT)
		set->player.move &= ~(1 << LEFT_BIT);
	if (keycode == RIGHT)
		set->player.move &= ~(1 << RIGHT_BIT);
	if (keycode == C)
		set->player.move &= ~(1 << C_BIT);
	return (1);
}

/*
** move &= ~(1 << N) // sets N-th bit in move to 0.
*/

int				key_hook_press(int keycode, t_set *set)
{
	if (keycode == ESC)
		finish_program(set);
	if (keycode == W || keycode == UP)
		set->player.move |= 1 << W_BIT;
	if (keycode == S || keycode == DOWN)
		set->player.move |= 1 << S_BIT;
	if (keycode == A)
		set->player.move |= 1 << A_BIT;
	if (keycode == D)
		set->player.move |= 1 << D_BIT;
	if (keycode == LEFT)
		set->player.move |= 1 << LEFT_BIT;
	if (keycode == RIGHT)
		set->player.move |= 1 << RIGHT_BIT;
	if (keycode == C)
		set->player.move |= 1 << C_BIT;
	return (1);
}

static void		move_to(t_fpix *to, t_set *set, int ver, int hor)
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

/*
** rot is direction of rotation.
** If rot == 1 is to the right
** if rot == -1 rotation is to the left
*/

static void		rotate(t_fpix *vec, double angle, int rot)
{
	double		old_x;

	if (rot == 1 || rot == -1)
	{
		old_x = vec->x;
		vec->x = vec->x * cos(rot * angle) -
					vec->y * sin(rot * angle);
		vec->y = old_x * sin(rot * angle) +
					vec->y * cos(rot * angle);
	}
}

void			update_pos(t_set *set)
{
	t_fpix		to;

	to = v_set(set->player.pos.x, set->player.pos.y);
	if ((set->player.move >> RIGHT_BIT) & 1)
	{
		rotate(&set->player.dir, ANGLE_STEP, 1);
		rotate(&set->player.plane, ANGLE_STEP, 1);
	}
	if ((set->player.move >> LEFT_BIT) & 1)
	{
		rotate(&set->player.dir, ANGLE_STEP, -1);
		rotate(&set->player.plane, ANGLE_STEP, -1);
	}
	if ((set->player.move >> W_BIT) & 1)
		move_to(&to, set, 1, 0);
	if ((set->player.move >> S_BIT) & 1)
		move_to(&to, set, -1, 0);
	if ((set->player.move >> A_BIT) & 1)
		move_to(&to, set, 0, -1);
	if ((set->player.move >> D_BIT) & 1)
		move_to(&to, set, 0, 1);
	set->player.hor = ((set->player.move >> C_BIT) & 1) ? HOR_SIT : HOR;
	if (set->map.c_map[(int)to.y][(int)to.x] == '0')
		set->player.pos = v_set(to.x, to.y);
}
