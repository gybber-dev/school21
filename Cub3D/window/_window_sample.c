#include "_cub.h"

//TEST IT!!!!!
/*
 * gcc window/_window_sample.c -Llibmlx -lmlx -lX11 -lbsd -lm -lXext
 */

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct  s_vars {
	void        *mlx;
	void        *win;
	t_data		img1;
	t_data		img2;
}               t_vars;

int             key_hook(int keycode, t_vars *vars)
{
	printf("[%d] key up\n", keycode);
}
int             key_hook_press(int keycode, t_vars *vars)
{
	printf("[%d] key press\n", keycode);
}
int             pointer_hook_move(int keycode, t_vars *vars)
{
	printf("Pointer moving... %d\n", keycode);
}




void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char		*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void 			draw_square(t_data *img, int x, int y, int w, int color)
{
	int i = 0;
	int j = 0;
	while(j++ < w)
	{
		while(i++ < w)
		{
			my_mlx_pixel_put(img, i + x, j + y, color);
		}
		i = 0;
	}
}


int				main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_vars		win;
	void 		*p;
	int i = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 480, "Hello world!");
	win.img1.img = mlx_new_image(mlx, 640, 480);
	win.img1.addr = mlx_get_data_addr(win.img1.img, &win.img1.bits_per_pixel, &win.img1.line_length,
								 &win.img1.endian);
	win.img2.img = mlx_new_image(mlx, 200, 180);
	win.img2.addr = mlx_get_data_addr(win.img2.img, &win.img2.bits_per_pixel, &win.img2.line_length,
									  &win.img2.endian);

	draw_square(&win.img1, 50, 50, 100, 0x00FF0000);
	draw_square(&win.img1, 100, 100, 100, 0x0100FF00);
	i = 0;
	while (i < 10)
		my_mlx_pixel_put(&win.img2, 5, i++, 0x0000FF00);


	void			*pct;
	t_pix			size;

//	ft_bzero(&size, sizeof(t_pix));
	pct = mlx_xpm_file_to_image(mlx, "./textures/bricks.xpm", &size.x, &size.y);
	DEBUG printf("pct '%s' was read [%dx%d]\n", "./textures/bricks.xpm", size.x, size.y);

//	int i = 0;
//	int j = 0;
//	while (j < size.y)
//	{
//		while(i < size.x)
//		{
//			my_mlx_pixel_put(pct, i + 100, j + 100, 0x0000FF00);
//			i++;
//		}
//		j++;
//	}
	mlx_put_image_to_window(mlx, mlx_win, win.img1.img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, win.img2.img, 400, 0);
	mlx_put_image_to_window(mlx, mlx_win, pct, 0, 0);
//	hooks catcher:
	// on key up:
//	mlx_key_hook(mlx_win, key_hook, p);

	// key press
//	mlx_hook(mlx_win, 2, 1L<<0, key_hook_press, &vars);
	// Pointer motion
//	mlx_hook(mlx_win, 6, 1L<<6, pointer_hook_move, &vars);
	// Mouse press press what's a ...
//	mlx_hook(mlx_win, 4, 1L<<2, pointer_hook_move, &vars);

	mlx_loop(mlx);
}
