#include <stdio.h> // for printf
#include <fcntl.h> // for open
#include <string.h> // for strcpy
#include <unistd.h>
#include "get_next_line.h"

#define	SAMPLE "str.txt"
#define	NONREAD "non-read.txt"
#define	SHORT "short.txt"

char			*read_mem(char *mem, char **line)
{
	char		*end_line;
	size_t		memlen;
	char		*tmp;

	end_line = NULL;
	if (mem)
	{
		memlen = ft_strlen(mem);
		printf("mem has '%s' (%zu)\n", mem, memlen);
		if ((end_line = ft_strchr(mem, '\n'))) //\n asdf\0
		{
			*end_line = 0;
			tmp = *line;
			*line = ft_strjoin(*line, mem);
			free(tmp);
			tmp = mem;
			mem = ft_strdup(end_line + 1);
			free(tmp);
			// ft_strlcpy(mem, ++end_line, memlen);
			// mem = end_line + 1; // ! leak
			printf("from '%c' mem is '%s'\n", *end_line, mem);
		}
		else
		{
			*line = ft_strdup(mem);
			free(mem);
			// ft_bzero(mem, memlen);
		}
	}
	printf("memread out: '%s'\n", mem);
	return (end_line);
}


/*	returns:
	1 : A line has been read
	0 : EOF has been reached
	-1 : An error happened
*/
int				get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			end_read;
	int			result;
	char		*end_line;
	static char	*mem;

	*line = ft_strdup("");
	end_line = read_mem(mem, line);
	result = 0;
	while (!end_line && (end_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		printf("->line is: '%s'\n->mem is: '%s'\n", *line, mem);
		printf("read in buf: '%s' (%d)\n", buf, end_read);
		if ((end_line = ft_strchr(buf, '\n'))) // end of line
		{
			buf[end_read] = 0;
			printf("...end_line in buf! Save in mem\n");
			// set 0;
			*end_line = 0;
			// save lost string
			mem = ft_strdup(end_line + 1);
			printf("...mem saved as '%s'\n", mem);
			*line = ft_strjoin(*line, buf);
			break ;
		}
		else if (end_line == NULL) // center of line
		{
			printf("...just add buf to line\n");
			*line = ft_strjoin(*line, buf);
		}
	}
	if (ft_strlen(mem) || end_read || ft_strlen(*line))
		result = 1;
	if (end_read == -1) // error: trying to read unreadable file 
		return (-1);
	return (result);
}

int			main(void)
{
	int		fd;
	char	*str =  "";
	int		N = 80;
	int		res;
	char	*filename = SHORT;
	int		i = 0;

	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	fd = open(filename, O_RDONLY);
	while(N--){
		printf("====================\n[%d]\n\n", ++i);
		res = get_next_line(fd, &str);
		if (res == 0)
		{
			printf("==[%d]result: %d, line: '%s'==\n", i, res, str);
			printf("\n==Text is off.==\n");
			return (0);
		}
		else if(res == -1)
		{
			printf("\n==Error==\n");
			break ;
		}
		else
		{
			printf("\n==[%d]result: %d, line: '%s'==\n\n", i, res, str);
		}
	}
	
}