/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:19:46 by yeschall          #+#    #+#             */
/*   Updated: 2021/03/10 21:19:47 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

/*
** Returns project of dot to m-n coordinate system with a center in d0
**				   -1
** dot_mn = [ m n ]	* [ dot ] =
**
**				n.y		-n.x		 dot.x
** 1 / det * [	-m.y	m.x		] * [dot.y]
*/

t_fpix			prj_to_vec(t_fpix m, t_fpix n, t_fpix d0, t_fpix dot)
{
	t_fpix		proj;
	t_fpix		sub_dot;
	double		det;

	sub_dot = v_sub(dot, d0);
	det = m.x * n.y - m.y * n.x;
	proj.x = 1 / det * (n.y * sub_dot.x - n.x * sub_dot.y);
	proj.y = 1 / det * (-m.y * sub_dot.x + m.x * sub_dot.y);
	return (proj);
}

double			v_len(t_fpix v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2)));
}

double			v_dist(t_fpix d1, t_fpix d2)
{
	t_fpix		vector;

	vector.x = d2.x - d1.x;
	vector.y = d2.y - d1.y;
	return (v_len(vector));
}

t_fpix			v_set(double val_x, double val_y)
{
	t_fpix		res;

	res.x = val_x;
	res.y = val_y;
	return (res);
}

t_fpix			v_sub(t_fpix v1, t_fpix v2)
{
	t_fpix		res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	return (res);
}
