#include <stdio.h> // for printf
#include <fcntl.h> // for open
#include <string.h> // for strdup
#include <unistd.h>
#include "get_next_line.h"
#include "libft/libft.h"

#define	SAMPLE "str.txt"
#define	NONREAD "non-read.txt"
#define	SHORT "short.txt"

char			*read_mem(char *mem, char **line)
{
	
	return (mem);
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
	int			flag;
	static char	*mem;
	result = 1;
	if (ft_strlen(mem))
		*line = ft_strdup(mem);
	else
		*line = "";
	while ((end_read = read(fd, buf, BUFFER_SIZE)) != -1)
	{
		printf("->line is: '%s'\n->mem is: '%s'\n", *line, mem);
		printf("read symbols: '%s' (%d)\n", buf, end_read);
		if (end_read < BUFFER_SIZE) // end of doc
		{
			flag = 0;
			buf[end_read] = 0;
		}
		if ((end_line = ft_strchr(buf, '\n')) != NULL) // end of line
		{
			flag = 2;
			printf("last symbol in line: '%c'\n", *(end_line));
			// set 0;
			*end_line = 0;
			// save lost string
			mem = end_line + 1;
		}
		else if (end_line == NULL) // center of line
		{
			flag = 1;
			buf[BUFFER_SIZE] = 0;
		}
		printf("__flag is: %d\n", flag);
		if (flag == 1)
		{
			*line = ft_strjoin(*line, buf);
		}
		if (flag == 0)
		{
			*line = ft_strjoin(*line, buf);
			break ;
		}
		if (flag == 2)
		{
			printf("buf is '%s'\n", buf);
			*line = ft_strjoin(*line, buf);
			break ;
		}
	}
	printf("<-mem: '%s'\n", mem);
	if (end_read == -1) // error: trying to read unreadable file 
		return (-1);
	return (result);
}

int			main(void)
{
	int		fd;
	char	*str =  "";
	int		N = 2;
	int		res;
	char	*filename = SAMPLE;

	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	fd = open(filename, O_RDONLY);
	while(N--){
		res = get_next_line(fd, &str);
		if (res == 0)
		{
			printf("result: %d, line: '%s'\n", res, str);
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
			printf("result: %d, line: '%s'\n", res, str);
		}
	}
	
}