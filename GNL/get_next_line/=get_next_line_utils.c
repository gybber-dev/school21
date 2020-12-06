/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 01:57:10 by yeschall          #+#    #+#             */
/*   Updated: 2020/12/01 15:25:28 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++ != 0)
		i++;
	return (i);
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

char		*ft_strjoin(char *s1, char *s2, char **clear)
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
		!(len2) ? free_mem(&s2, &s2) : 0;
		return (NULL);
	}
	ft_memmove(res, s1, len1 * sizeof(char));
	ft_memmove(&(res[len1]), s2, len2 * sizeof(char));
	res[len1 + len2] = 0;
	// printf("joining: s1: '%s', s2: '%s', res: '%s'\n\tclear s1? %d\n", s1, s2, res, clear);
	!(len2) ? free_mem(&s2, &s2) : 0;
	(*clear) ? free_mem(clear, clear) : 0;
	// printf("s1: '%s', s2: '%s', res: '%s'\n", s1, s2, res);
	return (res);
}