/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:20:26 by yeschall          #+#    #+#             */
/*   Updated: 2020/11/06 22:10:29 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
