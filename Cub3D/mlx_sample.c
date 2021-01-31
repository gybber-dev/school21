#include "minilibx_mms/mlx.h"


/*
** Compilation:
** MacOS:
** 		gcc mlx_sample.c -Lminilibx_mms -lmlx -framework OpenGL -framework AppKit
** Linux:
**
*/
int			main(void)
{
	void    *mlx;
	void    *mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}
