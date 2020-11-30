/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 01:57:10 by yeschall          #+#    #+#             */
/*   Updated: 2020/11/30 16:17:17 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t		ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (*str++ != 0)
// 		i++;
// 	return (i);
// }

// void			*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	const char	*src_p;
// 	const char	*src_end;
// 	char		*dst_p;
// 	char		*dst_end;

// 	if (dst == NULL && src == NULL)
// 		return (NULL);
// 	dst_p = (char *)dst;
// 	src_p = (char *)src;
// 	if (dst_p < src_p)
// 		while (len--)
// 			*dst_p++ = *src_p++;
// 	else
// 	{
// 		src_end = src_p + (len - 1);
// 		dst_end = dst_p + (len - 1);
// 		while (len--)
// 			*dst_end-- = *src_end--;
// 	}
// 	return (dst);
// }

// char			*ft_strchr(const char *s, int c)
// {
// 	if (s == NULL)
// 		return (NULL);
// 	while (*s)
// 	{
// 		if (*s == (char)c)
// 			return (char *)s;
// 		s++;
// 	}
// 	if (c == 0)
// 		return (char *)s;
// 	return (char *)NULL;
// }

// /*
// returns:
// s2 == NULL?
// 	like: strdup(s1)
//  :	join(s2 and s1)

//  clear == 1?
// 	free(s1)
// */
// char		*ft_strjoin(char *s1, char *s2, int clear)
// {
// 	char	*res;
// 	size_t	len1;
// 	size_t	len2;

// 	if (s1 == NULL)
// 		return (NULL);
// 	if (s2 == NULL)
// 	{
// 		if (!(s2 = (char *)malloc(1)))
// 			return (NULL);
// 		*s2 = '\0';
// 	}
// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	if ((res = (char *)malloc(len1 + len2 + 1)) == NULL)
// 	{
// 		(!len2) ? free(s2) : 0;
// 		return (NULL);
// 	}
// 	ft_memmove(res, s1, len1 * sizeof(char));
// 	ft_memmove(&(res[len1]), s2, len2 * sizeof(char));
// 	res[len1 + len2] = 0;
// 	free(s2);
// 	(clear) ? free(s1) : 0;
// 	s1 = (clear) ? NULL : s1;
// 	return (res);
// }
