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
	if (!(set->map.c_map = (char**)malloc(sizeof(char *) * (lines))))
		ft_error(set, errno);
	*(set->map.c_map) = NULL;
}


void			ft_parse_map(char *line, t_set *set)
{
	char		**p;

	if (set->map.isparsed)
		ft_error(set, ERR_READ_FILE);
	p = set->map.c_map;
	while(*p != NULL)
		p++;
	if (!(*p = ft_strdup(line)))
		ft_error(set, errno);
	*(p + 1) = NULL;
}