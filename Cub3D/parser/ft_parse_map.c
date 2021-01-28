#include "ft_parser.h"


int				is_map(char *str)
{
	if (!*str)
		return (0);
	while (*str != 0 && *str != '\n')
	{
		if (!ft_strchr(MAP_SYMBOLS, *str))
			return (0);
		str++;
	}
	return (1);
}

void			set_mem_for_map(char *str, t_set *set)
{
	int			lines;

	lines = 0;
	while(*str)
	{
		if(!(ft_strchr(str, '\n')))
			break ;
		lines++;
		str++;
	}
	DEBUG printf("Reserve for map [%d] lines\nin [%s]", lines, str);
	set->map = (char**)malloc(sizeof(char *) * lines);
//	ft_error(errno);
	*(set->map) = NULL;
	DEBUG printf("Check if malloced: '%s'\n", *(set->map));
}


void			ft_parse_map(char *line, t_set *set)
{
	char		**res;
	int			len;

	len = 0;
}