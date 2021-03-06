#include "../ft_cub.h"

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
	set->map.lines = lines - 1;
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