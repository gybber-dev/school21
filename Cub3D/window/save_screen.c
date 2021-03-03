#include "../ft_cub.h"

void		save_screen(t_set *set)
{
	int		fd;
	DEBUG printf("save screen\n");

//	i = img->textures.resolution_h - 1;
	fd = open(SCREEN, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd < 0)
		ft_error(errno);
//	ft_write_header(fd, img);
//	while (i >= 0)
//	{
//		write(fd, (img->addr + i * img->line_length),
//			  (img->textures.resolution_w * img->bits_per_pixel / 8));
//		i--;
//	}
//	if (close(fd) < 0)
//		ft_error(img, "Something went wrong while closing screenshot");
	exit(0);
}