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

/*	
	returns: move string before \n to *line. After \n - to mem
	-1:	on error (don't free mem and line)
	1:	on success
*/
int				edit_mem(char **mem, char **line, char *p)
{
	char		*tmp;

	*p = '\0';
	
	printf("edit mem:\n\tmem : '%s'\n\tline: '%s'\n", *mem, *line);
	tmp = NULL;
	if (ft_strjoin(&tmp, (p + 1), NULL, 0))
	{
		printf("tmp is: %s\n", tmp);
		if ((ft_strjoin(line, *mem, NULL, 1)) && (*mem = tmp))
			return (1);
	}
	return (-1);
}



/*
	returns:
	2	- buffer
	-1	- on error don't free mem, buf and line
	0	- end of text
	1	- end of line
*/
ssize_t			read_line(char **line, char **buf, char **mem, int fd)
{
	char		*tmp;
	ssize_t		bytes;

	printf("\n\n_____tik___\n");
	printf("buf: '%s'\nline: '%s'\nmem: '%s'\n", *buf, *line, *mem);
	if ((tmp = ft_strchr(*mem, '\n')))
	{
		printf("CHECK_0\n");
		if ((bytes = edit_mem(mem, line, tmp)) != -1)
			free(buf);
		return (bytes);
	}
	else
	{
		if ((bytes = (read(fd, *buf, BUFFER_SIZE))) > 0)
		{
			printf("CHECK_1\n");
			(*buf)[bytes] = '\0';
			if (!ft_strjoin(mem, *mem, *buf, 0))
				return (-1);
		}
		else
		{
			printf("CHECK_2\n");
			ft_strjoin(line, *mem, NULL, 1);
			free(buf);
			printf("tmp: '%s'\n", tmp);
			if (!(*line) || bytes == -1)
				return (-1);
			return (0);
		}		
	}
	return (2); //continue
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
	ssize_t		result;

	result = -1;
	if (BUFFER_SIZE <= 0 || !(buf = (char *)malloc(BUFFER_SIZE + 1)) ||
			fd < 0)
		return (-1);
	if ((*line = (char *)malloc(1)) == NULL)
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
