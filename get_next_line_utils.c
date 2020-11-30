/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 01:57:10 by yeschall          #+#    #+#             */
/*   Updated: 2020/11/19 02:39:01 by yeschall         ###   ########.fr       */
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

void		ft_bzero(void *b, size_t len)
{
	char	*p;

	p = b;
	while (len-- > 0)
		*p++ = 0;
}

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	filling;

	i = 0;
	j = 0;
	while (i <= dstsize && dst[i++] != '\0')
		;
	if (--i == dstsize)
		return (i + ft_strlen(src));
	filling = i;
	while (src[j] && (dstsize - i - 1 > 0))
		dst[i++] = src[j++];
	dst[i] = 0;
	if (filling > dstsize)
		filling = dstsize;
	return (filling + ft_strlen(src));
}

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dst == NULL || src == NULL)
		return (0);
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && (dstsize - i - 1) > 0)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

void		*ft_memcpy(void *dst, const void *src, size_t len)
{
	char	*p_dst;
	char	*p_src;

	p_src = (char *)src;
	p_dst = (char *)dst;
	if (p_dst == NULL && p_src == NULL)
		return (NULL);
	while (len-- > 0)
		*p_dst++ = *p_src++;
	return (dst);
}

char		*ft_strdup(const char *s1)
{
	char	*res;
	size_t	len;

	len = ft_strlen(s1) + 1;
	res = (char *)malloc(len * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, s1, len);
	return (res);
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

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(len);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, len);
	ft_strlcat(res, s1, len);
	ft_strlcat(res, s2, len);
	return (res);
}
