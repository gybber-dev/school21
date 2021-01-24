#include "../ft_cub.h"
#define PARAMS

static const char	*pass_number(const char *str)
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

static char			*parse_path(const char *str)
{
	char			*res;

	if (!(res = ft_strtrim(str, " ")))
		return (NULL);
	if (ft_strchr(res, ' ')) //not valid path
		return (NULL);
	return (res);
}

static int			ft_parse_head(const char *line, char *keys, t_set *set)
{
	char			*tmp;

	if (*keys == 'R' && *(keys + 1) == ' ')
	{
		set->win.res1 = ft_atoi((tmp = ft_strchr(line, ' ')));
		set->win.res2 = ft_atoi(pass_number((char*)line));
	}
	if (*keys == 'N' && *(keys + 1) == 'O')
		if ((set->skin.no_ski = parse_path(line + 2)) == NULL)
			return (-1);
	if (*keys == 'S' && *(keys + 1) == 'O')
		if ((set->skin.so_ski = parse_path(line + 2)) == NULL)
			return (-1);
	if (*keys == 'W' && *(keys + 1) == 'E')
		if ((set->skin.we_ski = parse_path(line + 2)) == NULL)
			return (-1);
	if (*keys == 'E' && *(keys + 1) == 'A')
		if ((set->skin.ea_ski = parse_path(line + 2)) == NULL)
			return (-1);
	if (*keys == 'F' && *(keys + 1) == ' ')
		// write in bytes
		return (-1);
	if (*keys == 'C' && *(keys + 1) == ' ')
		// write in bytes
		return (-1);
	return (1);
}

static int			parse_line(const char *line, t_set *set)
{
	char			*keys;
	char			*begin;
	int				res;

	keys = "R ONOSOWEEAS F C ";
	while (*keys)
	{
		if (!ft_strncmp(line, keys, 2))
		{
			printf("line: '%s' is '%.2s'\n", line, keys);
			if ((res = ft_parse_head(line, keys, set)) < 0)
				return (res);
		}
		else
		{
//			ft_parse_map(line);
		}
		keys++;
		if (!(*keys))
			keys++;
	}
	return (1);
}


t_set			ft_parser(char *file, char **map)
{
	t_set		set;
	int			fd;
	char		*line;
	int			res;

	fd = open(file, O_RDONLY);
	while( (res = get_next_line(fd, &line)) >= 0)
	{
		if (*line == '\n')
			continue ;
		parse_line(line, &set);
		ft_free(&line);
		if (res == 0)
			break ;
	}
	DEBUG printf("SET:\n");
	DEBUG printf("win:\n\tres1: %d\n\tres2: %d\n", set.win.res1, set.win.res2);
	DEBUG printf("skins:\n\tno: '%s'\n\tso: '%s'\n\twe: '%s'\n\tea: '%s'\n",
			  set.skin.no_ski, set.skin.so_ski, set.skin.we_ski, set.skin.ea_ski);
	if (res == -1)
		printf("gnl_error\n");
	return (set);
}
