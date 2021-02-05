#include "ft_cub.h"
#include <string.h>
#define SCALE 30
//#include "minilibx_opengl_20191021/mlx.h"

void			my_mlx_pixel_put(t_set *set, int x, int y, int color)
{
	char		*dst;

	dst = set->win.addr + (y * set->win.line_len + x * (set->win.bpp / 8));
	*(unsigned int*)dst = color;

}

static void				init_set(t_set *set)
{
	set->map.c_map = NULL;
	set->map.ismalloced = 0;
	set->win.mlx = NULL;
	set->win.win = NULL;
	set->win.res1 = 0;
	set->win.res2 = 0;
	set->skin.fl_col = 0;
	set->skin.ce_col = 0;
	set->skin.no_ski = NULL;
	set->skin.so_ski = NULL;
	set->skin.we_ski = NULL;
	set->skin.ea_ski = NULL;
	set->skin.sprite_ski = NULL;
	set->player.from.x = -1;
	set->player.from.y = -1;
	set->player.to.x = -1;
	set->player.to.y = -1;
}

static void	init_player_pos(t_set *set)
{
	char	**p;
	int		i;

	DEBUG printf("Find player\n");
	p = set->map.c_map;
	i = 0;
	set->player.to.y = 0;
	while(*p != NULL && i >= 0)
	{
		i = 0;
		while ((*p)[i] != 0)
		{
			if ((*p)[i] == 'W' || (*p)[i] == 'N' || (*p)[i] == 'S' || (*p)[i] == 'E')
			{
				set->player.to.x = i * SCALE;
				set->player.to.y *= SCALE;
				return ;
			}
			i++;
		}
		p++;
		set->player.to.y++;
	}
}

void					set_player(t_set *set)
{
	DEBUG printf("Player SET from [%d; %d] to [%d; %d]\n",
				 set->player.from.x, set->player.from.y, set->player.to.x, set->player.to.y);
	// final position is defined and it is not a start position
	if (set->player.to.x != -1 &&
		set->player.from.x != set->player.to.x &&
		set->player.from.y != set->player.to.y)
	{
		my_mlx_pixel_put(set, set->player.to.x, set->player.to.y, 0xFF0000);
		set->player.from.x = set->player.to.x;
		set->player.from.y = set->player.to.y;
	}
	printf("check\n");
	DEBUG printf("Player is on\n\t[%d, %d]\n", set->player.to.x, set->player.to.y);
}

void		scale_pix(t_set *set, t_pix *pix)
{
	t_pix	p;
	t_pix	end;

	p.x = SCALE * pix->x;
	p.y = SCALE * pix->y;
	end.x = p.x + SCALE - 1;
	end.y = p.y + SCALE - 1;
	while (p.y <= end.y)
	{
		p.x = SCALE * pix->x;
		while (p.x <= end.x)
		{
			my_mlx_pixel_put(set, p.x, p.y, 0xFFFFFF);
			p.x++;
		}
		p.y++;
	}
}

void		draw_map(t_set *set)
{
	t_pix	pix;

	DEBUG printf("DRAW THE MAP: %s\n", *(set->map.c_map));
	ft_bzero(&pix, sizeof(t_pix));
	while (set->map.c_map[pix.y])
	{
		pix.x = 0;
		while (set->map.c_map[pix.y][pix.x])
		{
			if (set->map.c_map[pix.y][pix.x] == '1')
//				my_mlx_pixel_put(set, pix.x, pix.y, 0xFFFFFF);
				scale_pix(set, &pix);
			pix.x++;
		}
		pix.y++;
	}
}


int				key_hook_up(int keycode, t_set *set)
{
	printf("[%d] key up\n", keycode);
}

int				key_hook_press(int keycode, t_set *set)
{
	DEBUG printf("[%d] key press\n", keycode);
	if (keycode == 119 || keycode == 65362)
		set->player.to.x++;
	if (keycode == 115 || keycode == 65364)
		set->player.to.x--;
	if (keycode == 97 || keycode == 65361)
		set->player.to.y--;
	if (keycode == 100 || keycode == 65363)
		set->player.to.y++;

}

void		run_game(t_set *set)
{
	void	*default_map;
	set->win.mlx = mlx_init();
	set->win.win = mlx_new_window(set->win.mlx, set->win.res1, set->win.res2, "test");
	set->win.img = mlx_new_image(set->win.mlx, set->win.res1, set->win.res2);
	set->win.addr = mlx_get_data_addr(set->win.img, &set->win.bpp, &set->win.line_len,
									  &set->win.endian);
	printf("win:params:\n\taddr: '%s'\n\tbpp: [%d]\n\tlen: [%d]\n\tendian: [%d]\n",
		set->win.addr, set->win.bpp, set->win.line_len, set->win.endian);
	draw_map(set);
	if (set->player.to.x == -1)
		init_player_pos(set);
	mlx_hook(set->win.win, 2, 1L<<0, key_hook_press, set);
	printf("tick\n");
	set_player(set);
//	my_mlx_pixel_put(set, 15, 15, 0x00FF0000);
	mlx_put_image_to_window(set->win.mlx, set->win.win, set->win.img, 0, 0);
	mlx_loop(set->win.mlx);
}

int			main(int argc, char **argv)
{
	t_set 	set;

	printf("sam: %d\n", errno);
	errno = 0;
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], SAVE_FLAG, ft_strlen(SAVE_FLAG)))
			printf("it's necessary to save in .bmp format\n");
		else
		{
			init_set(&set);
			ft_parser(argv[1], &set);
			run_game(&set);
		}

	}
	else
		ft_error(22);
//	auto_clear();
	return (0);
}
