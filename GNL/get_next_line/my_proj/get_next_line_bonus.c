/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 06:33:22 by yeschall          #+#    #+#             */
/*   Updated: 2021/01/15 18:40:27 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void			free_mem(char **mem)
{
	if (*mem != NULL)
	{
		free(*mem);
		*mem = NULL;
	}
}

/*
** returns: move string before \n to *line. After \n - to mem
*/

int				split_mem(char **mem, char **line, char *p)
{
	char		*tmp;

	*p = '\0';
	if ((tmp = ft_strjoin(p + 1, NULL)) == NULL)
		return (-1);
	if ((*line = ft_strjoin(*mem, NULL)) == NULL)
		return (-1);
	free_mem(mem);
	*mem = tmp;
	return (1);
}

/*
** returns:
** 	2	: end of line or file have not reached yet
**	-1	: on error
**	0	: end of file
**	1	: end of line
*/

int				read_line(char **line, char **mem, char *buf, int fd)
{
	char		*tmp;
	ssize_t		bytes;

	if ((tmp = ft_strchr(*mem, '\n')))
		return (split_mem(mem, line, tmp));
	else
	{
		if ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[bytes] = '\0';
			if (!(tmp = ft_strjoin(*mem, buf)))
				return (-1);
			free_mem(mem);
			*mem = tmp;
		}
		else
		{
			*line = ft_strjoin(*mem, NULL);
			if (!(*line) || bytes == -1)
				return (-1);
			return (0);
		}
	}
	return (2);
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
		free_mem(mem);
		return (-1);
	}
	return (1);
}

/*
**	returns:
**	1	: A line has been read
**	0	: EOF has been reached
**	-1	: An error happened
*/

int				get_next_line(int fd, char **line)
{
	static char	*mem[1024];
	int			result;
	char		*buf;

	result = -1;
	if (fd < 0)
		return (result);
	if (BUFFER_SIZE <= 0 || init_mem(&mem[fd], &buf) == -1 || !line)
		return (result);
	while ((result = read_line(line, &mem[fd], buf, fd)) == 2)
		;
	if (result < 1)
		free_mem(&mem[fd]);
	free_mem(&buf);
	return (result);
}
