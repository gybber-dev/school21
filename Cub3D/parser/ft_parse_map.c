#include "../ft_cub.h"


int				is_map(char *str)
{
	if (!*str || *str == '\n')
		return (0);
	while (*str != 0 && *str != '\n')
	{
		if (!ft_strchr(MAP_SYMBOLS, *str))
			return (0);
		str++;
	}
	return (1);
}

/*
** Counts the number of '\n' (lines) and mallocs (lines + 2)
** for the last line and NULL-terminator
*/

void			set_mem_for_map(char *str, t_set *set)
{
	int			lines;
	char		*p;

	lines = 0;
	while(*str)
	{
		if(!(p = ft_strchr(str, '\n')))
			break ;
		lines++;
		str = p + 1;
	}
	lines += 2;
	DEBUG printf("Reserve for map [%d] lines\nin [%s]", lines, str);
	set->map.c_map = (char**)malloc(sizeof(char *) * (lines));
	ft_error(errno);
	set->map.ismalloced = lines;
	*(set->map.c_map) = NULL;
	DEBUG printf("Check if malloced: '%s'\n", *(set->map.c_map));
}


void			ft_parse_map(char *line, t_set *set)
{
	char		**p;

	p = set->map.c_map;
	while(*p != NULL)
		p++;
	*p = ft_strdup(line);
	ft_error(errno);
	*(p + 1) = NULL;
}