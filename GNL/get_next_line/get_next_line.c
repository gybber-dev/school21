#include <stdio.h>
#include <fcntl.h> //open
#include "get_next_line.h"
#include <unistd.h>

// #define	FILE "short.txt"
#define	FILE "str.txt"
// #define	FILE "0.txt"
// #define	FILE "n0.txt"
// #define	FILE "no_read.txt"
// #define	FILE "test_dir"
// #define	FILE "test_dir/dir.txt"
// #define FILE "64bit_paragraph.txt"
// #define FILE "long_line.txt"


void	free_mem(char **mem)
{
	if (*mem != NULL)
		free(*mem);
	*mem = NULL;
}

/*	returns:
	-1:	on error and free mem and line
	1:	on success
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
		free_mem(&tmp);
		tmp = *mem;
		if (!(*mem = ft_strdup(pn + 1)))
			break ;
		free_mem(&tmp);
		return (1);
	}
	// printf("error\n");
	free_mem(&tmp);
	free_mem(mem);
	free_mem(line);
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
	char		*buf;
	char		*tmp;
	ssize_t		bytes;

	if (BUFFER_SIZE <= 0 || !(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (fd < 0 || (*line = ft_strdup("")) == NULL)
		return (-1);
	if (!mem)
		mem = ft_strdup("");
	while (1)
	{
		if ((tmp = ft_strchr(mem, '\n')))
		{
			free_mem(&buf);
			return (edit_mem(&mem, line, tmp));
		}
		else
		{
			if ((bytes = (read(fd, buf, BUFFER_SIZE))) > 0)
			{
				buf[bytes] = '\0';
				tmp = mem;
				mem = ft_strjoin(mem, buf);
				free_mem(&tmp);
				if (!mem)
					break ;
			}
			else
			{
				/* записать в line всё до '\0' */
				tmp = *line;
				*line = ft_strdup(mem);
				free_mem(&tmp);
				free_mem(&mem);
				if (!line || bytes == -1)
					break ;
				free_mem(&buf);
				return (0);
			}		
		}
	}
	// printf("error:\n\tline: '%s'\n\tmem : '%s'\n", *line, mem);
	free_mem(&buf);
	free_mem(line);
	free_mem(&tmp);
	free_mem(&mem);
	return (-1);

}

// int			main(void)
// {
// 	int		i = 0;
// 	int		fd = open(FILE, O_RDONLY);
// 	// int		fd = 1;
// 	char	*line;
// 	int		res;

// 	while ((res = get_next_line(fd, &line)) >= 0)
// 	{
// 		printf("===[%d]: '%s'\n\n", ++i, line);
// 		if (res == 0)
// 			break ;
// 		free_mem(&line);
// 	}
// 	if (res == -1)
// 		printf("===ERROR\n");
// 	// while (1);
// }