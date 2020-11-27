/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:44:20 by msamual           #+#    #+#             */
/*   Updated: 2020/11/19 13:44:22 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	clear(t_list **begin_list, int fd)
{
	t_list *list_ptr;
	t_list *tmp;

	if (!begin_list)
		return ;
	while (*begin_list && (*begin_list)->fd == fd)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	if (!(*begin_list))
		return ;
	list_ptr = *begin_list;
	while (list_ptr && list_ptr->next)
	{
		if (list_ptr->next->fd == fd)
		{
			tmp = list_ptr->next->next;
			free(list_ptr->next);
			list_ptr->next = tmp;
		}
		else
			list_ptr = list_ptr->next;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*destination;
	unsigned char	*source;

	if (!dst && !src)
		return (NULL);
	destination = (unsigned char*)dst;
	source = (unsigned char*)src;
	i = 0;
	if (source < destination)
		while (++i <= len)
			destination[len - i] = source[len - i];
	else
		while (len-- > 0)
			*(destination++) = *(source++);
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2, int code)
{
	char	*res;
	size_t	l1;
	size_t	l2;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		*s1 = '\0';
	}
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = (char *)malloc((l1 + l2 + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_memmove(res, s1, l1 * sizeof(char));
	ft_memmove(&(res[l1]), s2, l2 * sizeof(char));
	res[l1 + l2] = '\0';
	free(s1);
	if (code)
		free(s2);
	return (res);
}

int		read_line(t_list *lst, char **line)
{
	int		ret;
	int		res;
	char	*buf;

	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((ret = read(lst->fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = '\0';
		if (ret < 0)
		{
			free(buf);
			return (-1);
		}
		if ((res = check(buf, line, lst, 0)))
		{
			free(buf);
			return (res);
		}
	}
	buf[ret] = '\0';
	res = check(buf, line, lst, 0);
	free(buf);
	return (res);
}
