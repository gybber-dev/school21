#include "../ft_cub.h"

//TEST IT!!!!!
/*
 * gcc window/window.c -Llibmlx -lmlx -lX11 -lbsd -lm -lXext
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
int				main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_vars		vars;
	void 		*p;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 480, "Hello world!");
	img.img = mlx_new_image(mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 6, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 7, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 8, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 9, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

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
