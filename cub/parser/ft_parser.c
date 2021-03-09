#include "../ft_cub.h"


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

/*
** Counts the number of '\n' (lines) and mallocs (lines + 2)
** for the last line and NULL-terminator
*/

static void			set_mem_for_map(char *str, t_set *set)
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

static void 			parse_file(char *line, t_set *set)
{
	char		*p;

	p = NULL;
	while(line && *line)
	{
		if ((*line == ' ' || ft_isdigit(*line)) && !set->map.c_map)
			set_mem_for_map(line, set);
		if ((p = ft_strchr(line, '\n')))
			*p = '\0';
		if(ft_isdigit(*line) || *line == ' ')
		{
			if (set->skin.ce_col == -1 || set->skin.fl_col == -1 ||
				!set->win.img1.res.x || !set->win.img1.res.y || !set->skin.ea_ski ||
				!set->skin.we_ski || !set->skin.so_ski || !set->skin.no_ski)
				ft_error(set, ERR_FEW_DATA);
			ft_parse_map(line, set);
		}
		else
		{
			if (set->map.c_map)
				set->map.isparsed = 1;
			ft_parse_head(line, set);
		}
		line = (p)? p + 1 : NULL;
	}
}

static int				read_file(t_set *set, int fd, char **file)
{
	int			bytes;
	char		buf[501];
	int			res;

	res = 0;
	if (!(*file = ft_strdup("")))
		ft_error(set, errno);
	while ((bytes = read(fd, buf, 500)) > 0)
	{
		buf[bytes] = '\0';
		set->tmp = *file;
		if (!(*file = ft_strjoin(*file, buf)))
			ft_error(set, errno);
		ft_free(&set->tmp);
		res += bytes;
	}
	return(res);
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
