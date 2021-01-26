#include "../ft_cub.h"

int				read_file(int fd, char **file)
{
	int			bytes;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			res;

	res = 0;
	if (!(*file = ft_strdup("")))
		ft_error(errno);
	while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		tmp = *file;
		printf("\n'%s'\n", buf);
		*file = ft_strjoin(*file, buf);
		(*file) ? ft_error(errno) : 0;
		ft_free(&tmp);
		res += bytes;
	}
	printf("\n\n========\n%s\n\n===========\n", *file);
	return(res);
}
