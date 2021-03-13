/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_head.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:55:37 by yeschall          #+#    #+#             */
/*   Updated: 2021/03/10 20:55:39 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub.h"

static char			*parse_path(t_set *set, char *str, char **dst)
{
	char			*file;
	int				fd;

	if (*dst)
		ft_error(set, ERR_HEAD_1);
	if (!(file = ft_strtrim(str, " ")))
		ft_error(set, errno);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(set, errno);
	close(fd);
	*dst = file;
	return (file);
}

static void			parse_resolution(t_set *set, char *line)
{
	if (set->win.img.res.x != 0 || set->win.img.res.y != 0)
		ft_error(set, ERR_HEAD_1);
	while (*line == ' ')
		line++;
	if (ft_isdigit(*line))
		set->win.img.res.x = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ' || *line == ',')
		line++;
	if (ft_isdigit(*line))
		set->win.img.res.y = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ' || *line == ',')
		line++;
	if (*line != 0 ||
		set->win.img.res.x <= 0 || set->win.img.res.y <= 0)
		ft_error(set, ERR_HEAD_2);
}

static void			parse_rgb(t_set *set, char *line, int *param)
{
	int				col;
	int				i;

	i = 3;
	if (*param != -1)
		ft_error(set, ERR_HEAD_1);
	while (*line == ' ')
		line++;
	*param = (0 << 24);
	while (i--)
	{
		if (ft_isdigit(*line))
			col = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		while (*line == ' ' || *line == ',')
			line++;
		if (col < 0 || col > 255)
			ft_error(set, ERR_HEAD_2);
		*param |= (col << i * 8);
	}
	if (*line != 0)
		ft_error(set, ERR_HEAD_2);
}

int					ft_parse_head(char *line, t_set *set)
{
	if (*line == 'R' && *(line + 1) == ' ')
		parse_resolution(set, line + 2);
	else if (*line == 'N' && *(line + 1) == 'O')
		parse_path(set, line + 2, &set->skin.no_ski);
	else if (*line == 'S' && *(line + 1) == 'O')
		parse_path(set, line + 2, &set->skin.so_ski);
	else if (*line == 'W' && *(line + 1) == 'E')
		parse_path(set, line + 2, &set->skin.we_ski);
	else if (*line == 'E' && *(line + 1) == 'A')
		parse_path(set, line + 2, &set->skin.ea_ski);
	else if (*line == 'S' && *(line + 1) == ' ')
		parse_path(set, line + 2, &set->skin.spr_ski);
	else if (*line == 'F' && *(line + 1) == ' ')
		parse_rgb(set, line + 2, &set->skin.fl_col);
	else if (*line == 'C' && *(line + 1) == ' ')
		parse_rgb(set, line + 2, &set->skin.ce_col);
	else if (*line == '\0')
		;
	else
		ft_error(set, ERR_LINE);
	return (1);
}
