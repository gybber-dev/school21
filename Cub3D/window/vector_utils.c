#include "../ft_cub.h"

double		v_len(t_fpix v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2)));
}

double		v_dist(t_fpix d1, t_fpix d2)
{
	t_fpix	vector;

	vector.x = d2.x - d1.x;
	vector.y = d2.y - d1.y;
	return (v_len(vector));
}



t_fpix		v_set(double val_x, double val_y)
{
	t_fpix	res;

	res.x = val_x;
	res.y = val_y;
	return (res);
}

void		v_scale(t_fpix *v, double k)
{
	v->x *= k;
	v->y *= k;
}

t_fpix		v_sub(t_fpix v1, t_fpix v2)
{
	t_fpix	res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	return (res);
}

t_fpix		v_sum_num(t_fpix src, double x, double y)
{
	t_fpix	res;

	res.x = src.x + x;
	res.y = src.y + y;
	return (res);
}

double		v_mult(t_fpix v1, t_fpix v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

t_fpix		v_mult_num(t_fpix vec, double x, double y)
{
	t_fpix	res;

	res.x = vec.x * x;
	res.y = vec.y * y;
	return (res);
}