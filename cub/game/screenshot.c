/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:20:31 by yeschall          #+#    #+#             */
/*   Updated: 2021/03/10 16:20:35 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub.h"

static void			init_bmp_header(t_set *set, int fd)
{
	int				val;

	write(fd, "BM", 2);
	val = 14 + 40 + set->win.img.res.x * set->win.img.res.y *
	set->win.img.bpp / 8;
	write(fd, &val, 4);
	val = 0;
	write(fd, &val, 4);
	val = 14 + 40;
	write(fd, &val, 4);
	val = 40;
	write(fd, &val, 4);
	write(fd, &set->win.img.res.x, 4);
	write(fd, &set->win.img.res.y, 4);
	val = 1;
	write(fd, &val, 2);
	write(fd, &set->win.img.bpp, 2);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 24);
}

void				screen_image(t_set *set)
{
	char			*file_name;
	int				fd;
	int				i;

	file_name = "screen.bmp";
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
		ft_error(set, errno);
	init_bmp_header(set, fd);
	i = set->win.img.res.y;
	while (i-- > 0)
	{
		write(fd, (set->win.img.addr + i * set->win.img.len),
			(set->win.img.res.x * set->win.img.bpp / 8));
	}
	close(fd);
	exit(0);
}
