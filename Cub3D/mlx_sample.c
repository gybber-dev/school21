#include "minilibx_opengl_20191021/mlx.h"
#include <stdio.h>

/*
** Compilation:
** MacOS:
** 		gcc mlx_sample.c -Lminilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit
** Linux:
**
*/
int			main(void)
{
	void    *mlx = NULL;
	void    *mlx_win = NULL;
	int x = 100;
	int y = 100;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 480, "Hello world!");
	while (y++ < 200)
	{
		x = 100;
		while (x++ < 200)
			if (x%2)
				mlx_pixel_put(mlx, mlx_win, x, y, 0xFFFFFF);


	}

	mlx_loop(mlx);
}
