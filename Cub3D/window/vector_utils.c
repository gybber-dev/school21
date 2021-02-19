#include "../ft_cub.h"

double		v_len(t_fpix v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2)));
}

void		v_set(t_fpix *v, double val)
{
	v->x = val;
	v->y = val;
}

void		v_scale(t_fpix *v, double k)
{
	v->x *= k;
	v->y *= k;
}

void		v_sum(t_fpix *src, t_fpix dst)
{
	src->x += dst.x;
	src->y += dst.y;
}

double		v_mult(t_fpix v1, t_fpix v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}