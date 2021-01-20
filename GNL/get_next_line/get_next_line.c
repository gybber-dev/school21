/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:56:10 by desausag          #+#    #+#             */
/*   Updated: 2021/01/13 18:30:19 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int ft_free(char **str)
{
	if (*str != NULL)
	{
		printf("free reminder....\n");
		free(*str);
		*str = NULL;
	}
	return (1);
}


char	*rd_reminder(char **line, char *reminder)
{
	char	*p_t;

	p_t = NULL;
	if (reminder)
		if ((p_t = ft_strchr(reminder, '\n')))
		{
			*p_t = '\0';
			*line = ft_strdup(reminder);
			p_t++;
			ft_memcpy(reminder, p_t, ft_strlen(p_t) + 1);
		}
		else
		{
			*line = ft_strdup(reminder);
			while (*reminder)
				*reminder++ = '\0';
			reminder = NULL;
		}
	else
	{
		*line = (char *)malloc(sizeof(char));
		*line[0] = '\0';
	}
	return (p_t);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			rc;
	char		*p_b;
	char		*tmp;
	static char	*reminder;


	if ((read(fd, NULL, 0) == -1) || BUFFER_SIZE < 1 || !line)
		return (-1);
	p_b = rd_reminder(line, reminder);
	while ((!p_b && (rc = read(fd, buf, BUFFER_SIZE))))
	{
		buf[rc] = '\0';
		if ((p_b = ft_strchr(buf, '\n')))
		{
			*p_b = '\0';
			p_b++;
			tmp = reminder;
			reminder = ft_strdup(p_b);
			free(tmp);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	return ((rc || ft_strlen(reminder) || p_b) ? 1 : 0);
}
// #include "get_next_line.h"
// #include <stdio.h>
// int main()
// {
// 	int fd = open("/Users/desausag/Documents/gnl/final/text.txt", O_RDONLY);
// 	char *line;
// 	int i;

// 	while ((i = get_next_line(fd, &line)))
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	printf("%s\n", line);
// 	free(line);
// 	while (1);
// }