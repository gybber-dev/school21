#include "../ft_cub.h"

int				read_file(t_set *set, int fd, char **file)
{
	int			bytes;
	char		buf[501];
	char		*tmp;
	int			res;

	res = 0;
	if (!(*file = ft_strdup("")))
		ft_error(set, errno);
	while ((bytes = read(fd, buf, 500)) > 0)
	{
		buf[bytes] = '\0';
		tmp = *file;
		*file = ft_strjoin(*file, buf);
		!(*file) ? ft_error(set, errno) : 0;
		ft_free(&tmp);
		res += bytes;
	}
	return(res);
}
