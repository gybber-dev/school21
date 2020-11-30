#include <stdio.h>
#include <fcntl.h> //open
#include "get_next_line.h"
#include <unistd.h>

#define	FILE "short.txt"
// #define	FILE "str.txt"
// #define	FILE "0.txt"
// #define	FILE "n0.txt"
// #define	FILE "no_read.txt"
// #define	FILE "test_dir"
// #define	FILE "test_dir/dir.txt"
// #define FILE "64bit_paragraph.txt"
// #define FILE "long_line.txt"


size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++ != 0)
		i++;
	return (i);
}

void			free_mem(char **arg0, char **arg1, char **arg2)
{
	if (*arg0 != NULL)
		free(*arg0);
	*arg0 = NULL;
	if (*arg1 != NULL)
		free(*arg1);
	*arg1 = NULL;
	if (*arg2 != NULL)
		free(*arg2);
	*arg2 = NULL;
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*src_p;
	const char	*src_end;
	char		*dst_p;
	char		*dst_end;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_p = (char *)dst;
	src_p = (char *)src;
	if (dst_p < src_p)
		while (len--)
			*dst_p++ = *src_p++;
	else
	{
		src_end = src_p + (len - 1);
		dst_end = dst_p + (len - 1);
		while (len--)
			*dst_end-- = *src_end--;
	}
	return (dst);
}

char			*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return (char *)s;
		s++;
	}
	if (c == 0)
		return (char *)s;
	return (char *)NULL;
}

/*
returns:
s2 == NULL?
	like: strdup(s1)
 :	join(s2 and s1)

 clear == 1?
	free(s1)
*/
char		*ft_strjoin(char *s1, char *s2, int clear)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL)
	{
		if (!(s2 = (char *)malloc(1)))
			return (NULL);
		*s2 = '\0';
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((res = (char *)malloc(len1 + len2 + 1)) == NULL)
	{
		!(len2) ? free_mem(&s2, &s2, &s2) : 0;
		return (NULL);
	}
	ft_memmove(res, s1, len1 * sizeof(char));
	ft_memmove(&(res[len1]), s2, len2 * sizeof(char));
	res[len1 + len2] = 0;
	printf("joining: s1: '%s', s2: '%s', res: '%s'\n\tclear s1? %d\n", s1, s2, res, clear);
	!(len2) ? free_mem(&s2, &s2, &s2) : 0;
	(clear) ? free_mem(&s1, &s1, &s1) : 0;
	printf("s1: '%s', s2: '%s', res: '%s'\n", s1, s2, res);
	return (res);
}

/*	returns:
	-1:	on error, then free mem and line
	1:	on success
*/
// int				edit_mem(char **mem, char **line, char *pn)
// {
// 	char		*tmp;

// 	while (1)
// 	{
// 		*pn = '\0';
// 		// *line = *mem; // ??? leaks may be
// 		printf("---line: '%s'\n", *line);
		
// 		if (!(*line = ft_strjoin(*line, *mem, 1)))
// 			break ;
// 		tmp = *mem;
// 		printf("\n")
// 		if (!(*mem = ft_strjoin(pn + 1, NULL, 0)))
// 			break ;
// 		free_mem(&tmp, &tmp, &tmp);
// 		return (1);
// 	}
// 	// printf("error\n");
// 	free_mem(&tmp, mem, line);
// 	return (-1);
// }

int				edit_mem(char **mem, char **line, char *pn)
{
	char		*tmp;

	while (1)
	{
		*pn = '\0';
		// *line = *mem; // ??? leaks may be
		tmp = *line;
		if (!(*line = ft_strjoin(*mem, NULL, 0)))
			break ;
		free_mem(&tmp, &tmp, &tmp);
		tmp = *mem;
		if (!(*mem = ft_strjoin(pn + 1, NULL, 0)))
			break ;
		free_mem(&tmp, &tmp, &tmp);
		return (1);
	}
	// printf("error\n");
	free_mem(&tmp, mem, line);
	return (-1);
}

/*
	returns:
	2	- buffer
	-1	- on error
	0	- end of text
	1	- end of line
*/
int				read_line(char **line, char **buf, char **mem, int fd)
{
	char		*tmp;
	ssize_t		bytes;

	if ((tmp = ft_strchr(*mem, '\n')))
	{
		printf("n in line detected...\n");
		printf("..clearing buf: '%s'...", *buf);
		free_mem(buf, buf, buf);
		printf("buf is cleared: '%s'\n", *buf);
		return (edit_mem(mem, line, tmp));
	}
	else
	{
		printf("n not in line:\n");
		if ((bytes = (read(fd, *buf, BUFFER_SIZE))) > 0)
		{
			printf("read [%zu]. 0 is not in line\n", bytes);
			(*buf)[bytes] = '\0';
			*mem = ft_strjoin(*mem, *buf, 1);
			if (!mem)
				return (-1); //break ;
		}
		else
		{
			printf("0 in line detected...\n");
			printf("____, line: '%s', mem: '%s'\n", *line, *mem);
			*line = ft_strjoin(*line, *mem, 1);
			if (!(*line) || bytes == -1)
				return (-1); //break ;
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
	static char	*mem; // accumulate line
	char		*buf;
	int			result;

	result = -1;
	if (BUFFER_SIZE <= 0 || !(buf = (char *)malloc(BUFFER_SIZE + 1)) ||
			fd < 0 || (*line = (char *)malloc(1)) == NULL)
		return (-1);
	*line[0] = '\0';
	if (!mem)
	{
		printf("mem is empty\n");
		if (!(mem = (char *)malloc(1)))
			return (-1);
		mem[0] = '\0';
	}
	else
	{
		printf("mem is not empty: '%s'\n", mem);
	}
	
	while ((result = read_line(line, &buf, &mem, fd)) == 2)
		printf("result: %d\n", result);
	printf("result: %d\n", result);
	if (result == -1)
		free_mem(&mem, &buf, line);
	return (result);

}

int			main(void)
{
	int		i = 0;
	int		fd = open(FILE, O_RDONLY);
	// int		fd = 1;
	char	*line;
	int		res;

	while ((res = get_next_line(fd, &line)) >= 0)
	{
		printf("===[%d]: '%s'\n\n", ++i, line);
		if (res == 0)
			break ;
		free_mem(&line, &line, &line);
	}
	if (res == -1)
		printf("===ERROR\n");
	// while (1);
}