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


void			free_mem(char **arg0, char **arg1)
{
	if (*arg0 != NULL)
		free(*arg0);
	*arg0 = NULL;
	if (*arg1 != NULL)
		free(*arg1);
	*arg1 = NULL;
}

/*	returns: move string before \n to *line. After \n - to mem
	-1:	on error then free mem and line
	1:	on success
*/
int				edit_mem(char **m, char **l, char *p)
{
	*p = '\0';
	if ((*l = ft_strjoin(*m, NULL, l)) && (*m = ft_strjoin((p + 1), NULL, m)))
		return (1);
	free_mem(l, m);
	return (-1);
}



/*
	returns:
	2	- buffer
	-1	- on error
	0	- end of text
	1	- end of line
*/
int				read_line(char **line, char *buf, char **mem, int fd)
{
	char		*tmp;
	ssize_t		bytes;

	if ((tmp = ft_strchr(*mem, '\n')))
		{
			free_mem(buf, buf);
			return (edit_mem(mem, line, tmp));
		}
		else
		{
			if ((bytes = (read(fd, *buf, BUFFER_SIZE))) > 0)
			{
				(*buf)[bytes] = '\0';
				if (!(*mem = ft_strjoin(*mem, *buf, mem)))
					return (-1);
			}
			else
			{
				tmp = *line;
				*line = ft_strjoin(*mem, NULL, line);
				free_mem(mem, buf);
				// printf("tmp: '%s'\n", tmp);
				free_mem(&tmp, &tmp);
				if (!(*line) || bytes == -1)
					return (-1);
				return (0);
			}		
		}
	return (2);
}


/*	returns:
	1 : A line has been read
	0 : EOF has been reached
	-1 : An error happened
*/
int				get_next_line(int fd, char **line)
{
	static char	*mem;
	char		*buf;
	int			result;

	result = -1;
	if (BUFFER_SIZE <= 0 || !(buf = (char *)malloc(BUFFER_SIZE + 1)) ||
			fd < 0 || (*line = (char *)malloc(1)) == NULL)
		return (-1);
	*line[0] = '\0';
	if (!mem)
	{
		if (!(mem = (char *)malloc(1)))
			return (-1);
		mem[0] = '\0';
	}
	while ((result = read_line(line, &buf, &mem, fd)) == 2)
		;
	if (result == -1)
	{
		free_mem(&buf, line);
		free_mem(&mem, &mem);
	}
	return (result);
}
