#include "../ft_cub.h"

void			my_mlx_pixel_put(t_set *set, int x, int y, int color)
{
	char		*dst;

	dst = set->win.addr + (y * set->win.line_len + x * (set->win.bpp / 8));
	*(unsigned int*)dst = color;

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
					set->player.angle = 0;
				if ((*p)[i] == 'N')
					set->player.angle = 0;
				if ((*p)[i] == 'S')
					set->player.angle = 0;
				if ((*p)[i] == 'E')
					set->player.angle = 0;
				set->player.pos.x = i;
//				set->player.pos.y *= SCALE;
				(*p)[i] = '0';
				return ;
			}
			i++;
		}
		p++;
		set->player.pos.y += 1;
	}
}

static int				key_hook_up(int keycode, t_set *set)
{
	printf("[%d] key up\n", keycode);
	return (1);
}

static int				key_hook_press(int keycode, t_set *set)
{
	DEBUG printf("[%d] key press\n", keycode);
	float to_y = set->player.pos.y;
	float to_x = set->player.pos.x;
	if (keycode == W || keycode == UP)
	{
		to_x += cos(set->player.angle) * STEP;
		to_y += sin(set->player.angle) * STEP;
	}
	if (keycode == S || keycode == DOWN)
	{
		to_x += cos(set->player.angle + M_PI) * STEP;
		to_y += sin(set->player.angle + M_PI) * STEP;
	}
	if (keycode == A )
	{
		to_x += cos(set->player.angle - M_PI_2) * STEP;
		to_y += sin(set->player.angle - M_PI_2) * STEP;
	}
	if (keycode == D)
	{
		to_x += cos(set->player.angle + M_PI_2) * STEP;
		to_y += sin(set->player.angle + M_PI_2) * STEP;
	}
	if (keycode == LEFT)
		set->player.angle -= 0.1;
	if (keycode == RIGHT)
		set->player.angle += 0.1;
	if (set->map.c_map[(int)to_y][(int)to_x] != '1')
	{
		set->player.pos.y = to_y;
		set->player.pos.x = to_x;
	}
	DEBUG printf("Player is to '%c'\n\t[%f, %f] a=(%f)\n", set->map.c_map[(int)to_y][(int)to_x], set->player.pos.y, set->player.pos.x, set->player.angle);
	mlx_destroy_image(set->win.mlx, set->win.img);
	set->win.img = mlx_new_image(set->win.mlx, set->win.res1, set->win.res2);
	set->win.addr = mlx_get_data_addr(set->win.img, &set->win.bpp, &set->win.line_len,
									  &set->win.endian);
	draw_map(set);
	set_player(set);
	mlx_put_image_to_window(set->win.mlx, set->win.win, set->win.img, 0, 0);
	return (1);
}

void		run_game(t_set *set)
{
	set->win.mlx = mlx_init();
	set->win.win = mlx_new_window(set->win.mlx, set->win.res1, set->win.res2, "test");
	set->win.img = mlx_new_image(set->win.mlx, set->win.res1, set->win.res2);
	set->win.addr = mlx_get_data_addr(set->win.img, &set->win.bpp, &set->win.line_len,
									  &set->win.endian);
	draw_map(set);
	if (set->player.pos.x == -1)
		init_player_pos(set);
	mlx_put_image_to_window(set->win.mlx, set->win.win, set->win.img, 0, 0);
	mlx_hook(set->win.win, 2, 1L<<0, key_hook_press, set);
	set_player(set);
//	my_mlx_pixel_put(set, 15, 15, 0x00FF0000);
	mlx_put_image_to_window(set->win.mlx, set->win.win, set->win.img, 0, 0);
	mlx_loop(set->win.mlx);
}