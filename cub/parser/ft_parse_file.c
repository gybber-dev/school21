#include "../ft_cub.h"

int				read_file(t_set *set, int fd, char **file)
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
