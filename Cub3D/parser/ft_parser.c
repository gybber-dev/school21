#include "../ft_cub.h"

t_obj			ft_parser(char *file, char **map)
{
	t_obj		obj;
	int			fd;
	char		*line;
	int			res;

	DEBUG printf("PARSER:\n\tfile: '%s'\n", file);
	fd = open(file, O_RDONLY);
	while( (res = get_next_line(fd, &line)) >= 0)
	{
		printf("[%s]\n", line);
		ft_free(&line);
		if (res == 0)
			break ;
	}
	if (res == -1)
		printf("gnl_error\n");
	return (obj);
}