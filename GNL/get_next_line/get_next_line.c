/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 06:33:22 by yeschall          #+#    #+#             */
/*   Updated: 2020/12/08 06:40:51 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <unistd.h>
#include <string.h>

/*
** returns: move string before \n to *line. After \n - to mem
*/

int				edit_mem(char **mem, char **line, char *p)
{
	char		*tmp;

//	printf("split string: '%s'\n", *mem);
	*p = '\0';
	if ((*line = ft_strjoin1(*mem, NULL)) == NULL)
		return (-1);
//	printf("line: '%s'\n", *line);
	tmp = *mem;
	if ((*mem = ft_strjoin1(p + 1, NULL)) == NULL)
	{
		*mem = tmp;
		return (-1);
	}
	free(tmp);
//	printf("mem: '%s'\n", *mem);
	return (1);
}

/*
** returns:
** 	2	: end of line or file have not reached yet
**	-1	: on error
**	0	: end of file
**	1	: end of line
*/
ssize_t			read_line(char **line, char **mem, char *buf, int fd)
{
	char		*tmp;
	ssize_t		bytes;

//	printf("\n\n==============\nbuf: '%s'\nline: '%s'\nmem: '%s'\n\n", buf, *line, *mem);
	if ((tmp = ft_strchr(*mem, '\n')))
		return (edit_mem(mem, line, tmp));
	else
	{
		if ((bytes = (read(fd, buf, BUFFER_SIZE))) > 0)
		{
			buf[bytes] = '\0';
			tmp = *mem;
			if (!(*mem = ft_strjoin1(*mem, buf)))
			{
				*mem = tmp;
				return (-1);
			}
			free(tmp);
		}
		else
		{
			// printf("CHECK_2\n");
			*line = *mem;
			//line = ft_strjoin(line, *mem, NULL, 1);
			if (!(*line) || bytes == -1)
			{
				// printf("\n\nerror0\n");
				return (-1);
			}
//			free(buf);
			return (0);
		}		
	}
	return (2); //continue
}

int				init_mem(char **mem, char **buf)
{
	if (!(*mem))
	{
		if ((*mem = (char *)malloc(1)) == NULL)
			return (-1);
		*mem[0] = '\0';
	}
	if ((*buf = (char *)malloc(BUFFER_SIZE + 1)) == NULL)
	{
		free(mem);
		return (-1);
	}
	return (1);
}

/*	returns:
**	1	: A line has been read
**	0	: EOF has been reached
**	-1	: An error happened
*/
int				get_next_line(int fd, char **line)
{
	static char	*mem;
	ssize_t		result;
	char 		*buf;

	result = -1;
	if (BUFFER_SIZE <= 0 || fd < 0 || init_mem(&mem, &buf) == -1)
		return (-1);
//	printf("check\n");
	while ((result = read_line(line, &mem, buf, fd)) == 2)
		; // printf("RESULT: %zu, is end? '%s'\n", result, ft_strchr(mem, '\0'));
	free(buf);
	if (result == -1)
		free(mem);
	return (result);
}
