#include <stdio.h>
#include <fcntl.h> //open
#include "get_next_line.h"
#include <unistd.h>

void			free_mem(char **arg0)
{
	// printf("FREE MEM: '%s'\n", *arg0);
	// free(*arg0);
	if (*arg0 != NULL)
	{
		// printf("FR")
		free(*arg0);
		*arg0 = NULL;
	}
	else
	{
		printf("!!!!!!CATCH IT!!!!!!!!!!!!!!!!!\n");
	}
	// if (*arg1 != NULL)
	// 	free(*arg1);
	// *arg1 = NULL;
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
	
	// printf("edit mem:\n\tmem : '%s'\n\tline: '%s'\n", *mem, *line);
	tmp = NULL;
	if (ft_strjoin(&tmp, (p + 1), NULL, 0))
	{
		// printf("tmp is: %s\n", tmp);
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

	// printf("\n\n==============\nbuf: '%s'\nline: '%s'\nmem: '%s'\n\n", *buf, *line, *mem);
	if ((tmp = ft_strchr(*mem, '\n')))
	{
		// printf("CHECK_0\n");
		free_mem(buf);
		return (edit_mem(mem, line, tmp));
			// printf("\n\nerror2\n");
		// return (bytes);
	}
	else
	{
		if ((bytes = (read(fd, *buf, BUFFER_SIZE))) > 0)
		{
			// printf("CHECK_1 %zd\n", bytes);
			(*buf)[bytes] = '\0';
			if (!ft_strjoin(mem, *mem, *buf, 0))
			{
				// printf("\n\nerror1\n\n");
				return (-1);
			}
		}
		else
		{
			// printf("CHECK_2\n");
			ft_strjoin(line, *mem, NULL, 1);
			if (!(*line) || bytes == -1)
			{
				// printf("\n\nerror0\n");
				return (-1);
			}
			free_mem(buf);
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
		; // printf("RESULT: %zu, is end? '%s'\n", result, ft_strchr(mem, '\0'));
	if (result == -1)
	{
		free_mem(&buf);
		free_mem(line);
		free_mem(&mem);
	}
	return (result);
}
