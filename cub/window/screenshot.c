#include "../ft_cub.h"

static void			init_bmp_header(t_set *set, int fd)
{
	int				val;

	write(fd, "BM", 2);
	val = 14 + 40 + set->win.img1.res.x * set->win.img1.res.y *
	set->win.img1.bpp / 8;
	write(fd, &val, 4);
	val = 0;
	write(fd, &val, 4);
	val = 14 + 40;
	write(fd, &val, 4);
	val = 40;
	write(fd, &val, 4);
	write(fd, &set->win.img1.res.x, 4);
	write(fd, &set->win.img1.res.y, 4);
	val = 1;
	write(fd, &val, 2);
	write(fd, &set->win.img1.bpp, 2);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 24);
}

void				screen_image(t_set *set)
{
	DEBUG printf("SCREEN MAKER was run[%d]\n", set->save);

	char			*file_name;
	int				fd;
	int				i;

	file_name = "screen.bmp";
	fd = open (file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0) {
		ft_error(set, errno);
	}
	init_bmp_header(set, fd);
	i = -1;
	while (++i < set->win.img1.res.y)
	{
		write(fd, (set->win.img1.addr + i * set->win.img1.len),
			  (set->win.img1.res.x * set->win.img1.bpp / 8));
	}
	close(fd);
	exit(0);
}