#include "../ft_cub.h"

int				read_file(int fd, char **file)
{
	int			bytes;
	char		buf[501];
	char		*tmp;
	int			res;

	res = 0;
	if (!(*file = ft_strdup("")))
		ft_error(errno);
	while ((bytes = read(fd, buf, 500)) > 0)
	{
		buf[bytes] = '\0';
		tmp = *file;
		*file = ft_strjoin(*file, buf);
		(*file) ? ft_error(errno) : 0;
		ft_free(&tmp);
		res += bytes;
	}
	return(res);
}
