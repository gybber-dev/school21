/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:46:44 by yeschall          #+#    #+#             */
/*   Updated: 2020/12/09 16:04:58 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen(const char *str)
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

/*
** Just join s1 and s2. If s2 == NULL malloc the memory for s1
** return:
** malloced char* on success
** NULL on error
*/

char			*ft_strjoin(char *s1, char *s2)
{
	char		*res;
	size_t		len1;
	size_t		len2;

	res = NULL;
	if (s1 != NULL)
	{
		len1 = ft_strlen(s1);
		len2 = (s2 == NULL) ? 0 : ft_strlen(s2);
		if ((res = (char *)malloc(len1 + len2 + 1)) == NULL)
			return (res);
		ft_memmove(res, s1, len1 * sizeof(char));
		if (len2)
			ft_memmove(&(res[len1]), s2, len2 * sizeof(char));
		res[len1 + len2] = 0;
	}
	return (res);
}
