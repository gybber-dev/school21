#include "../ft_cub.h"
#include "../libft/libft.h"

static char			*parse_path(char *str)
{
	char			*res;
	char			*p;

	if ((p = ft_strchr(str, '\n')))
		*p = '\0';
	if (!(res = ft_strtrim(str, " ")))
		ft_error(errno);
	if (ft_strchr(res, ' ')) //not valid path
		ft_error(NOT_VALID_HEAD_0);
	return (res);
}

static int 			parse_rgb(char *str)
{
	int				r;
	int				g;
	int				b;
	char			*err_flag;

	DEBUG printf("RGB_PARSCING: '%s'\n", str);
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
	{
		if (!ft_strchr(line, ' ') || !reg_pass_string(" \\d", line))
			ft_error(NOT_VALID_HEAD_0);
		set->win.res1 = ft_atoi(ft_strchr(line, ' '));
		set->win.res2 = ft_atoi(reg_pass_string(" \\d", line));
	}
	if (*line == 'N' && *(line + 1) == 'O')
		if ((set->skin.no_ski = parse_path(line + 2)) == NULL)
			ft_error(errno);
	if (*line == 'S' && *(line + 1) == 'O')
		if ((set->skin.so_ski = parse_path(line + 2)) == NULL)
			ft_error(errno);
	if (*line == 'W' && *(line + 1) == 'E')
		if ((set->skin.we_ski = parse_path(line + 2)) == NULL)
			ft_error(errno);
	if (*line == 'E' && *(line + 1) == 'A')
		if ((set->skin.ea_ski = parse_path(line + 2)) == NULL)
			ft_error(errno);
	if (*line == 'F' && *(line + 1) == ' ')
		if ((set->skin.fl_col = parse_rgb(line + 1)) == -1)
			ft_error(NOT_VALID_HEAD_0);
	if (*line == 'C' && *(line + 1) == ' ')
		if ((set->skin.ce_col = parse_rgb(line + 1)) == -1)
			ft_error(NOT_VALID_HEAD_0);
	return (1);
}

void 			parse_file(char *file, t_set *set)
{
	char		*p;
	int			is_reading;

	p = NULL;
	is_reading = 0;
	while(file && *file)
	{
		p = ft_strchr(file, '\n');
		if (is_map(file) && !set->map.ismalloced)
			set_mem_for_map(file, set);
		if (p)
			*p = '\0';
		if(is_map(file) && set->map.ismalloced > 0)
		{
			set->map.ismalloced = (is_reading < 0)? -1 : set->map.ismalloced; // trying to parse splitted map
			is_reading = 1;
			ft_parse_map(file, set);
		}
		else
		{
			is_reading = (is_reading) ? -1 : 0; // end of map
			ft_parse_head(file, set);
		}
		file = (p)? p + 1 : NULL;
	}
}


void			ft_parser(char *file_name, t_set *set)
{
	int			fd;
	char		*file;
	int			res;

//	fd = open("map0.cub", O_RDONLY);
//	file_name = ft_strjoin("../", file_name);
//	ft_error(errno);
	fd = open(file_name, O_RDONLY);
	printf("sam: %s, %d, err: %d\n", file_name, fd, errno);
	ft_error(errno);
	if ((res = read_file(fd, &file)) < 1)
		ft_error(ERR_READ_FILE);
	parse_file(file, set);
	ft_error(ft_validate_data(set));

	DEBUG printf("win:\n\tres1: %d\n\tres2: %d\n", set->win.res1, set->win.res2);
	DEBUG printf("skins:\n\tno: '%s'\n\tso: '%s'\n\twe: '%s'\n\tea: '%s'\n\tfl: '%d'\n\tce: '%d'\n",
			  set->skin.no_ski, set->skin.so_ski, set->skin.we_ski, set->skin.ea_ski, set->skin.fl_col, set->skin.ce_col);
	DEBUG printf("\nMAP:\n");
//	char **p = set->map.c_map;
//	while(*p != NULL)
//	{
//		DEBUG printf("[%s]\n", *p);
//		p++;
//	}

	DEBUG printf("I want to free: '%s'\n", file);
	close(fd);
	ft_free(&file);
}
