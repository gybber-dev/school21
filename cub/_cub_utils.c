#include "ft_cub.h"

/*
** finds crossing dot of two NONPARALLEL vectors.
** It takes coordinates of two vectors, and of two dots
** lying on a line of the vectors.
** (from: https://habr.com/ru/post/523440/)
*/

t_fpix			count_rays_cross(t_fpix a, t_fpix b, t_fpix dot_a, t_fpix dot_b)
{
	t_fpix		dot_c;
	double		q;
	double		n;

	ft_bzero(&dot_c, sizeof(t_fpix));
	if (a.y != 0)
	{
		q = - a.x / a.y;
		n = ((dot_b.x - dot_a.x) + q * (dot_b.y - dot_a.y)) /
			(b.x + b.y * q);
	}
	else if (b.y != 0)
		n = (dot_b.y - dot_a.y) / b.y;
	else
		return (dot_a);
	dot_c.x = dot_b.x - n * b.x;
	dot_c.y = dot_b.y - n * b.y;
	return (dot_c);
}
