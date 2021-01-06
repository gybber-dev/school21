 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marwin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20:25:44 by rchalmer          #+#    #+#             */
/*   Updated: 2020/12/30 11:30:08 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str1;
	size_t	sz;

	sz = count * size;
	if (!(str1 = malloc(sz)))
		return (NULL);
	ft_memset(str1, 0, sz);
	return (str1);
}

char	*ft_strcpy(char *dest, char *src)
{
    while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

char    *check_storage(char *what_left, char **line)
{
    char		    *new_line;
    char			*tmp;

    new_line = NULL;
	if ((new_line = ft_strchr(what_left, '\n')))
	{
		*new_line = '\0';
		what_left = ft_strcpy(what_left, ++new_line);
		tmp = *line;
		*line = ft_strdup(what_left);
		free(tmp);
	}
	else
	{
		tmp = *line;
		*line = ft_strdup(what_left);
		free(tmp);
		ft_memset(what_left, 0, BUFFER_SIZE + 1); // sdf
	}
    return (new_line);
}

int     get_next_line(int fd, char **line)
{
	char    	    buf[BUFFER_SIZE + 1];
	char		    *new_line;
	static char     *what_left;
	char            *tmp;
	int     	    rd;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	*line = ft_strdup("");
	if (what_left == NULL)
	{
		what_left = ft_calloc(BUFFER_SIZE + 1, 1);
	}
	new_line = check_storage(what_left, line);
	while (!new_line && (rd = read(fd, buf, BUFFER_SIZE)) && *line != NULL)
	{
		buf[rd] = '\0';
		if ((new_line = ft_strchr(buf, '\n')))
		{
			*new_line = '\0';
			ft_strcpy(what_left, ++new_line);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	if (rd == -1 || *line == NULL)
		return (-1);
	if (new_line)
		return (1);
    if (*what_left == '\0' && rd == 0)
    {
        free(what_left);
        return (0);
    }
    return (0);
}