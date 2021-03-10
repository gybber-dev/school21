#include "ft_cub.h"

int		create_trgb(int t, int r, int g, int b)
{
	printf("TRGB: %d\t%d\t%d\n", r, g, b);
	return(t << 24 | r << 16 | g << 8 | b);
}

void			my_mlx_pixel_put(t_set *set, int x, int y, int color)
{
	char		*dst;

	if (y < set->win.img1.res.y && x < set->win.img1.res.x && x >= 0 && y >= 0)
	{
		dst = set->win.img1.addr + (y * set->win.img1.len + x * (set->win.img1.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

int			get_color(t_img *img, int x, int y)
{

	int			res;
	char		*dst;

	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->endian);
	dst = img->addr + y * img->len + x * (img->bpp / 8);
	res =  (*(int*)dst);
	return (res);
}