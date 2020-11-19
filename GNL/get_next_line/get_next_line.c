#include <stdio.h>
#include <fcntl.h> //open
#include "get_next_line.h"
#include <unistd.h>

// #define	FILE "short.txt"
// #define	FILE "str.txt"
// #define	FILE "0.txt"
// #define	FILE "n0.txt"
// #define	FILE "no_read.txt"
// #define	FILE "test_dir"
#define	FILE "test_dir/dir.txt"


/*	returns:
	NULL on error and free mem and line
	... Non NULL on success
*/
int				edit_mem(char **mem, char **line, char *pn)
{
	char		*tmp;

	// printf("edit mem:\n\tline: '%s'\n\tmem : '%s'\n", *line, *mem);
	while (1)
	{
		*pn = '\0';
		// *line = *mem; // ??? leaks may be
		tmp = *line;
		if (!(*line = ft_strdup(*mem)))
			break ;
		free(tmp);
		tmp = *mem;
		if (!(*mem = ft_strdup(pn + 1)))
			break ;
		free(tmp);
		return (1);
	}
	printf("error\n");
	free(tmp);
	free(*mem);
	free(*line);
	return (-1);
}
/*	returns:
	1 : A line has been read
	0 : EOF has been reached
	-1 : An error happened
*/
int				get_next_line(int fd, char **line)
{
	static char	*mem; // accumulate line
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	ssize_t		bytes;

	if (!mem)
		mem = ft_strdup("");
	*line = ft_strdup("");
	if (fd < 0 || *line == NULL)
		return (-1);
	while (1)
	{
		printf("line: '%s'\nmem : '%s'\n", *line, mem);
		if ((tmp = ft_strchr(mem, '\n')))
		{
			return (edit_mem(&mem, line, tmp) ? 1 : -1);
		}
		else
		{
			if ((bytes = (read(fd, buf, BUFFER_SIZE))) > 0)
			{
				buf[bytes] = '\0';
				tmp = mem;
				mem = ft_strjoin(mem, buf);
				if (!mem)
					break ;
				free(tmp);
			}
			else if (bytes == 0)
			{
				/* записать в line всё до '\0' */
				// *line = mem; // ??? leaks may be
				tmp = *line;
				*line = ft_strdup(mem);
				free(tmp);
				free(mem);
				if (!line || bytes == -1)
					break ;
				return (0);
			}
			else
			{
				printf("file reading error\n");
				break ;
			}
			
			
		}
	}
	printf("error:\n\tline: '%s'\n\tmem : '%s'\n", *line, mem);
	free(*line);
	free(tmp);
	free(mem);
	return (-1);

}

int			main(void)
{
	int		i = 0;
	// int		fd = open(FILE, O_RDONLY);
	int		fd = 1;
	char	*line;
	int		res;

	while ((res = get_next_line(fd, &line)) >= 0)
	{
		printf("===[%d]: '%s'\n\n", ++i, line);
		if (res == 0)
			break ;
		free(line);
	}
	if (res == -1)
		printf("===ERROR\n");
	// while (1)
	// {
	// 	;
	// }
}