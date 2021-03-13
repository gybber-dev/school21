/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:12:53 by yeschall          #+#    #+#             */
/*   Updated: 2021/03/10 21:12:56 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void			my_mlx_pixel_put(t_set *set, int x, int y, int color)
{
	char		*dst;

	if (y < set->win.img.res.y && x < set->win.img.res.x && x >= 0 && y >= 0)
	{
		dst = set->win.img.addr + (y * set->win.img.len +
				x * (set->win.img.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void			write_addr(t_img *img)
{
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->endian);
}

int				get_clr(t_img *img, int x, int y)
{
	int			res;
	char		*dst;

	dst = img->addr + y * img->len + x * (img->bpp / 8);
	res = (*(int*)dst);
	return (res);
}
