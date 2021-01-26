#include "../ft_cub.h"
#define PARAMS

/*
** Get pointer to string (str) and pass all symbols defined in argument c.
** Returns pointer to the next symbol after c (if it was).
** If length(c) == 1 - pass the symbols defined in c;
** If length(c) == 2 - symbol class is defined:
** Symbol classes:
** \d - digits
*/

static char	*pass_sympols(char *str, char *c)
{
	int				is_numb;

	is_numb = 0;
	while(*str)
	{
		if (ft_isdigit(*str) && is_numb == 0)
			is_numb = 1;
		if (!ft_isdigit(*str) && is_numb == 1)
			return (str);
		str++;
	}
	return (str);
}

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


static int			ft_parse_head(char *line, char *keys, t_set *set)
{
	char			*tmp;

	if (*keys == 'R' && *(keys + 1) == ' ')
	{
		set->win.res1 = ft_atoi((tmp = ft_strchr(line, ' ')));
		set->win.res2 = ft_atoi(reg_pass_string(" \\d", line));
	}
	if (*keys == 'N' && *(keys + 1) == 'O')
		if ((set->skin.no_ski = parse_path(line + 2)) == NULL)
			ft_error(errno);
	if (*keys == 'S' && *(keys + 1) == 'O')
		if ((set->skin.so_ski = parse_path(line + 2)) == NULL)
			ft_error(errno);
	if (*keys == 'W' && *(keys + 1) == 'E')
		if ((set->skin.we_ski = parse_path(line + 2)) == NULL)
			ft_error(errno);
	if (*keys == 'E' && *(keys + 1) == 'A')
		if ((set->skin.ea_ski = parse_path(line + 2)) == NULL)
			ft_error(errno);
	if (*keys == 'F' && *(keys + 1) == ' ')
		// write in bytes
		return (-1);
	if (*keys == 'C' && *(keys + 1) == ' ')
		// write in bytes
		return (-1);
	return (1);
}

static int			parse_line(char *line, t_set *set)
{
	char			*keys;
	char			*begin;
	int				res;
	char			*p;

	keys = "R ONOSOWEEAS F C ";
	while (*keys)
	{
		if (!ft_strncmp(line, keys, 2))
		{
			printf("line: '%s' is '%.2s'\n", line, keys);
			if ((res = ft_parse_head(line, keys, set)) < 0)
				return (EXIT_FAILURE);
		}
		else
		{
//			ft_parse_map(line);
		}
		keys++;
		if (!(*keys))
			keys++;
	}
	return (EXIT_SUCCESS);
}

void 			parse_file(char *file, t_set *set)
{
	char		*p;

	p = NULL;
	while(*file)
	{
		if ((p = ft_strchr(file, '\n')))
		{
			*p = '\0';
			parse_line(file, set);
			file = p + 1;
			continue ;
		}
		parse_line(file, set);
		DEBUG printf("last line: %s\n", file);
	}
}


t_set			ft_parser(char *file_name, char **map)
{
	t_set		set;
	int			fd;
	char		*file;
	int			res;

//	file_name = ft_strjoin("../", file_name);
//	ft_error(errno);
	fd = open(file_name, O_RDONLY);
	ft_error(errno);
	if ((res = read_file(fd, &file)) < 1)
		ft_error(ERR_READ_FILE);
	parse_file(file, &set);


	DEBUG printf("win:\n\tres1: %d\n\tres2: %d\n", set.win.res1, set.win.res2);
	DEBUG printf("skins:\n\tno: '%s'\n\tso: '%s'\n\twe: '%s'\n\tea: '%s'\n",
			  set.skin.no_ski, set.skin.so_ski, set.skin.we_ski, set.skin.ea_ski);
	DEBUG printf("I want to free: '%s'\n", file);
	ft_free(&file);
	return (set);
}
