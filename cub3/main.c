/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:21:26 by yeschall          #+#    #+#             */
/*   Updated: 2021/03/10 21:21:27 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include <string.h>

int				finish_program(t_set *set)
{
	auto_clear(set);
	exit(EXIT_SUCCESS);
}

static int		check_extension(char *file, char *exp)
{
	int			f_len;
	int			e_len;
	int			i;

	f_len = (int)ft_strlen(file);
	e_len = (int)ft_strlen(exp);
	i = -1;
	if (f_len <= e_len)
		return (0);
	while (++i < e_len)
		if (exp[e_len - 1 - i] != file[f_len - 1 - i])
			return (0);
	if (f_len - 1 - i >= 0 && file[f_len - 1 - i] == '/')
		return (0);
	return (1);
}

void			auto_clear(t_set *set)
{
	char		**p;

	if (set->map.c_map)
	{
		p = set->map.c_map;
		while (*p)
		{
			ft_free(p);
			p++;
		}
		free(set->map.c_map);
	}
	if (set->tmp)
		ft_free(&set->tmp);
	if (set->sprs)
		free(set->sprs);
}

static void		init_set(t_set *set)
{
	set->tmp = NULL;
	set->map.c_map = NULL;
	set->map.isparsed = 0;
	set->map.player_counter = 0;
	set->map.player_dir = 0;
	set->win.mlx = NULL;
	set->win.win = NULL;
	set->skin.fl_col = -1;
	set->skin.ce_col = -1;
	set->skin.no_ski = NULL;
	set->skin.so_ski = NULL;
	set->skin.we_ski = NULL;
	set->skin.ea_ski = NULL;
	set->sl = NULL;
	set->sprs = NULL;
	set->skin.spr_ski = NULL;
	set->player.pos.x = -1;
	set->player.pos.y = -1;
	set->player.hor = 2;
	set->player.move = 0;
	ft_bzero(&set->win.img.res, sizeof(t_fpix));
	ft_bzero(&set->player.dir, sizeof(t_fpix));
	ft_bzero(&set->player.plane, sizeof(t_fpix));
	set->os = (!ft_strncmp(OS, "MAC", 3)) ? 2 : 1;
}

int				main(int argc, char **argv)
{
	t_set		set;

	set.save = 0;
	if ((argc == 2 && check_extension(argv[1], ".cub"))
		|| (argc == 3 && (!ft_strncmp(argv[2], SAVE, ft_strlen(SAVE))
		&& !argv[2][ft_strlen(SAVE)])))
	{
		if (argc == 3)
			set.save = 1;
		init_set(&set);
		ft_parser(argv[1], &set);
		run_game(&set);
	}
	else
	{
		ft_putstr_fd("Error\n\tmessage: ", 1);
		ft_putstr_fd(strerror(22), 1);
		write(1, "\n", 1);
		exit(EXIT_FAILURE);
	}
	return (0);
}
