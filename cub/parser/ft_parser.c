#include "../ft_cub.h"

static char			*parse_path(t_set *set, char *str)
{
	char			*file;
	int				fd;

	if (!(file = ft_strtrim(str, " ")))
		ft_error(set, errno);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(set, errno);
	close(fd);
	return (file);
}

static int 			parse_rgb(char *str)
{
	int				r;
	int				g;
	int				b;
	char			*err_flag;

	DEBUG printf("RGB_PARSING: '%s'\n", str);
	r = ft_atoi(str);
	if (!(err_flag = reg_pass_string("\\d,", str)))
		return (-1);
	g = ft_atoi(err_flag);
	if (!(err_flag = reg_pass_string("\\d,\\d,", str)))
		return (-1);
	b = ft_atoi(err_flag);
	return (create_trgb(0, r, g, b));
}


static int			ft_parse_head(char *line, t_set *set)
{
	if (*line == 'R' && *(line + 1) == ' ')
		parse_resolution(set, line);
	if (*line == 'N' && *(line + 1) == 'O')
		if ((set->skin.no_ski = parse_path(set, line + 2)) == NULL)
			ft_error(set, errno);
	if (*line == 'S' && *(line + 1) == 'O')
		if ((set->skin.so_ski = parse_path(set, line + 2)) == NULL)
			ft_error(set, errno);
	if (*line == 'W' && *(line + 1) == 'E')
		if ((set->skin.we_ski = parse_path(set, line + 2)) == NULL)
			ft_error(set, errno);
	if (*line == 'E' && *(line + 1) == 'A') {
		if ((set->skin.ea_ski = parse_path(set, line + 2)) == NULL) {
			ft_error(set, errno);
		}
	}
	if (*line == 'S' && *(line + 1) == ' ')
		if ((set->skin.sprite_ski = parse_path(set, line + 2)) == NULL)
			ft_error(set, errno);
	if (*line == 'F' && *(line + 1) == ' ')
		if ((set->skin.fl_col = parse_rgb(line + 1)) == -1)
			ft_error(set, NOT_VALID_HEAD_0);
	if (*line == 'C' && *(line + 1) == ' ')
		if ((set->skin.ce_col = parse_rgb(line + 1)) == -1)
			ft_error(set, NOT_VALID_HEAD_0);
	return (1);
}




static int			ft_parse_head0(char *line, t_set *set)
{
	if (*line == 'R' && *(line + 1) == ' ')
	{
		if (!ft_strchr(line, ' ') || !reg_pass_string(" \\d", line))
			ft_error(set, NOT_VALID_HEAD_0);
		set->win.img1.res.x = ft_atoi(ft_strchr(line, ' '));
		set->win.img1.res.y = ft_atoi(reg_pass_string(" \\d", line));
	}
	if (*line == 'N' && *(line + 1) == 'O')
		if ((set->skin.no_ski = parse_path(set, line + 2)) == NULL)
			ft_error(set, errno);
	if (*line == 'S' && *(line + 1) == 'O')
		if ((set->skin.so_ski = parse_path(set, line + 2)) == NULL)
			ft_error(set, errno);
	if (*line == 'W' && *(line + 1) == 'E') {
		if ((set->skin.we_ski = parse_path(set, line + 2)) == NULL) {
			ft_error(set, errno);
		}
	}
	if (*line == 'E' && *(line + 1) == 'A') {
		if ((set->skin.ea_ski = parse_path(set, line + 2)) == NULL) {
			ft_error(set, errno);
		}
	}
	if (*line == 'S' && *(line + 1) == ' ')
		if ((set->skin.sprite_ski = parse_path(set, line + 2)) == NULL)
			ft_error(set, errno);
	if (*line == 'F' && *(line + 1) == ' ')
		if ((set->skin.fl_col = parse_rgb(line + 1)) == -1)
			ft_error(set, NOT_VALID_HEAD_0);
	if (*line == 'C' && *(line + 1) == ' ')
		if ((set->skin.ce_col = parse_rgb(line + 1)) == -1)
			ft_error(set, NOT_VALID_HEAD_0);
	return (1);
}

void 			parse_file(char *line, t_set *set)
{
	char		*p;

	p = NULL;
	while(line && *line)
	{
		if (is_map(line) && !set->map.c_map)
			set_mem_for_map(line, set);
		if ((p = ft_strchr(line, '\n')))
			*p = '\0';
		if(is_map(line))
			ft_parse_map(line, set);
		else
		{
			if (set->map.c_map)
				set->map.isparsed = 1;
			ft_parse_head(line, set);
		}
		line = (p)? p + 1 : NULL;
	}
}


void			ft_parser(char *file_name, t_set *set)
{
	int			fd;
	char		*file;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_error(set, errno);
	if ((read_file(set, fd, &file)) < 1)
		ft_error(set, ERR_READ_FILE);
	parse_file(file, set);
	ft_validate_data(set);

	DEBUG printf("win:\n\tres.x: %d\n\tres.y: %d\n", set->win.img1.res.x, set->win.img1.res.y);
	DEBUG printf("skins:\n\tno: '%s'\n\tso: '%s'\n\twe: '%s'\n\tea: '%s'\n\tfl: '%d'\n\tce: '%d'\n\tsp: '%s'\n",
			  set->skin.no_ski, set->skin.so_ski, set->skin.we_ski, set->skin.ea_ski, set->skin.fl_col, set->skin.ce_col,
			  set->skin.sprite_ski);
	DEBUG printf("\nMAP:\n");
	DEBUG printf("I want to free: '%s'\n", file);
	close(fd);
	ft_free(&file);
}
