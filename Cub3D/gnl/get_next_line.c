/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 06:33:22 by yeschall          #+#    #+#             */
/*   Updated: 2020/12/09 16:32:52 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub.h"

/*
** returns: move string before \n to *line. After \n - to mem
*/

static int				split_mem(char **mem, char **line, char *p)
{
	char		*tmp;

	*p = '\0';
	if ((tmp = ft_strjoin(p + 1, NULL)) == NULL)
		return (-1);
	if ((*line = ft_strjoin(*mem, NULL)) == NULL)
		return (-1);
	ft_free(mem);
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

static int				read_line(char **line, char **mem, char *buf, int fd)
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
			ft_free(mem);
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

static int				init_mem(char **mem, char **buf)
{
	if (!(*mem))
	{
		if ((*mem = (char *)malloc(1)) == NULL)
			return (-1);
		*mem[0] = '\0';
	}
	if ((*buf = (char *)malloc(BUFFER_SIZE + 1)) == NULL)
	{
		ft_free(mem);
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
	static char	*mem;
	int			result;
	char		*buf;

	result = -1;
	if (BUFFER_SIZE <= 0 || init_mem(&mem, &buf) == -1 || fd < 0 || !line)
		return (result);
	while ((result = read_line(line, &mem, buf, fd)) == 2)
		;
	if (result < 1)
		ft_free(&mem);
	ft_free(&buf);
	return (result);
}
