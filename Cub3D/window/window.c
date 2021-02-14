#include "../ft_cub.h"

void			my_mlx_pixel_put(t_set *set, int x, int y, int color)
{
	char		*dst;

//	printf("x: %d, y: %d\n", x, y);
//	if (x >= 0 && x <= set->win.img1.res1 && y >= 0 && y <= set->win.img1.res2)
//	{
	dst = set->win.img1.addr + (y * set->win.img1.len + x * (set->win.img1.bpp / 8));
	*(unsigned int *) dst = color;
//	}
}

static void	init_player_pos(t_set *set)
{
	char	**p;
	int		i;

	DEBUG printf("Find player\n");
	p = set->map.c_map;
	set->player.pos.y = 0;
	while(*p != NULL && i >= 0)
	{
		i = 0;
		while ((*p)[i] != 0)
		{
			if ((*p)[i] == 'W' || (*p)[i] == 'N' || (*p)[i] == 'S' || (*p)[i] == 'E')
			{
				if ((*p)[i] == 'W')
					if ((set->player.plane.y = 0.66))
						set->player.dir.x = -1;
				if ((*p)[i] == 'N')
					if ((set->player.plane.x = 0.66))
						set->player.dir.y	= -1;
				if ((*p)[i] == 'S')
					if ((set->player.plane.x = 0.66))
						set->player.dir.y	= 1;
				if ((*p)[i] == 'E')
					if ((set->player.plane.y = 0.66))
						set->player.dir.x = 1;
				set->player.pos.x = i + 0.3;
				set->player.pos.y += 0.3;
				(*p)[i] = '0';
				return ;
			}
			i++;
		}
		p++;
		set->player.pos.y += 1;
	}
}

/*
** move |= 1 << N // sets N-th bit in move to 1.
*/

static int				key_hook_up(int keycode, t_set *set)
{
	DEBUG printf("[%d] key up\n", keycode);
	if (keycode == W || keycode == UP)
		set->player.move &= ~(1 << W_BIT);
	if (keycode == S || keycode == DOWN)
		set->player.move &= ~(1 << S_BIT);
	if (keycode == A )
		set->player.move &= ~(1 << A_BIT);
	if (keycode == D)
		set->player.move &= ~(1 << D_BIT);
	if (keycode == LEFT)
		set->player.move &= ~(1 << LEFT_BIT);
	if (keycode == RIGHT)
		set->player.move &= ~(1 << RIGHT_BIT);
	move_to(set);

	mlx_destroy_image(set->win.mlx, set->win.img1.img);
	set->win.img1.img = mlx_new_image(set->win.mlx, set->win.img1.res1, set->win.img1.res2);
	set->win.img1.addr = mlx_get_data_addr(set->win.img1.img, &set->win.img1.bpp,
							&set->win.img1.len, &set->win.img1.endian);
	draw_map(set);
	set_player(set);
	mlx_put_image_to_window(set->win.mlx, set->win.win, set->win.img1.img, 0, 0);
	return (1);
}

/*
** move &= ~(1 << N) // sets N-th bit in move to 0.
*/

static int				key_hook_press(int keycode, t_set *set)
{
	DEBUG printf("[%d] key press\n", keycode);
	if (keycode == W || keycode == UP)
		set->player.move |= 1 << W_BIT;
	if (keycode == S || keycode == DOWN)
		set->player.move |= 1 << S_BIT;
	if (keycode == A )
		set->player.move |= 1 << A_BIT;
	if (keycode == D)
		set->player.move |= 1 << D_BIT;
	if (keycode == LEFT)
		set->player.move |= 1 << LEFT_BIT;
	if (keycode == RIGHT)
		set->player.move |= 1 << RIGHT_BIT;
	move_to(set);
	mlx_destroy_image(set->win.mlx, set->win.img1.img);
	set->win.img1.img = mlx_new_image(set->win.mlx, set->win.img1.res1, set->win.img1.res2);
	set->win.img1.addr = mlx_get_data_addr(set->win.img1.img, &set->win.img1.bpp,
							&set->win.img1.len, &set->win.img1.endian);
	draw_map(set);
	set_player(set);
	mlx_put_image_to_window(set->win.mlx, set->win.win, set->win.img1.img, 0, 0);
	return (1);
}

void		run_game(t_set *set)
{
	set->win.mlx = mlx_init();
	set->win.win = mlx_new_window(set->win.mlx, set->win.img1.res1, set->win.img1.res2, "test");
	set->win.img1.img = mlx_new_image(set->win.mlx, set->win.img1.res1, set->win.img1.res2);
	set->win.img1.addr = mlx_get_data_addr(set->win.img1.img, &set->win.img1.bpp,
							&set->win.img1.len, &set->win.img1.endian);
	draw_map(set);
	if (set->player.pos.x == -1)
		init_player_pos(set);
	mlx_put_image_to_window(set->win.mlx, set->win.win, set->win.img1.img, 0, 0);
	mlx_hook(set->win.win, 2, 1L<<0, key_hook_press, set);
	mlx_hook(set->win.win, 3, 1L<<1, key_hook_up, set);


	set_player(set);
	mlx_put_image_to_window(set->win.mlx, set->win.win, set->win.img1.img, 0, 0);
	printf("tick\n");
	mlx_loop(set->win.mlx);
}