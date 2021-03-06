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

void			parse_resolution(t_set *set, char *line)
{
	if (set->win.img1.res.x != 0 || set->win.img1.res.y != 0)
		ft_error(set, NOT_VALID_HEAD_1);
	while(*line == ' ')
		line++;
	if (ft_isdigit(*line))
		set->win.img1.res.x = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while(*line == ' ' || *line == ',')
		line++;
	if (ft_isdigit(*line))
		set->win.img1.res.y = ft_atoi(line);
	while(ft_isdigit(*line))
		line++;
	while(*line == ' ' || *line == ',')
		line++;
	if (*line != 0 ||
		set->win.img1.res.x == 0 || set->win.img1.res.y == 0)
		ft_error(set, NOT_VALID_HEAD_2);
}

void				parse_rgb(t_set *set, char *line, int *param)
{
	int				r;
	int				g;
	int				b;

	if (*param != -1)
		ft_error(set, NOT_VALID_HEAD_1);
	while(*line == ' ')
		line++;
	if (ft_isdigit(*line))
		r = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while(*line == ' ' || *line == ',')
		line++;
	if (ft_isdigit(*line))
		g = ft_atoi(line);
	while(ft_isdigit(*line))
		line++;
	while(*line == ' ' || *line == ',')
		line++;
	if (ft_isdigit(*line))
		b = ft_atoi(line);
	while(ft_isdigit(*line))
		line++;
	while(*line == ' ' || *line == ',')
		line++;
	if (*line != 0 || r < 0 || g < 0 || b < 0
			|| r > 255 || b > 255 || g > 255)
		ft_error(set, NOT_VALID_HEAD_2);
	*param = create_trgb(0, r, g, b);
}

static int			ft_parse_head(char *line, t_set *set)
{
	if (*line == 'R' && *(line + 1) == ' ')
		parse_resolution(set, line + 2);
	else if (*line == 'N' && *(line + 1) == 'O')
		set->skin.no_ski = parse_path(set, line + 2);
	else if (*line == 'S' && *(line + 1) == 'O')
		set->skin.so_ski = parse_path(set, line + 2);
	else if (*line == 'W' && *(line + 1) == 'E')
		set->skin.we_ski = parse_path(set, line + 2);
	else if (*line == 'E' && *(line + 1) == 'A')
		set->skin.ea_ski = parse_path(set, line + 2);
	else if (*line == 'S' && *(line + 1) == ' ')
		set->skin.sprite_ski = parse_path(set, line + 2);
	else if (*line == 'F' && *(line + 1) == ' ')
		parse_rgb(set, line + 2, &set->skin.fl_col);
	else if (*line == 'C' && *(line + 1) == ' ')
		parse_rgb(set, line + 2, &set->skin.ce_col);
	else if (*line == '\0')
		;
	else
		ft_error(set, NOT_VALID_LINE);
	return (1);
}

void 			parse_file(char *line, t_set *set)
{
	char		*p;

	p = NULL;
	while(line && *line)
	{
		if (ft_isdigit(*line) && !set->map.c_map)
			set_mem_for_map(line, set);
		if ((p = ft_strchr(line, '\n')))
			*p = '\0';
		if(ft_isdigit(*line))
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
