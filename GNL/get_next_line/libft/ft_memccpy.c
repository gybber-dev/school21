/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:04:53 by yeschall          #+#    #+#             */
/*   Updated: 2020/11/05 21:54:57 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_p;
	unsigned char	*src_p;
	int				is_meet;

	is_meet = 0;
	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n--)
	{
		*dst_p = *src_p;
		if (*src_p == (unsigned char)c)
		{
			is_meet = 1;
			dst_p++;
			break ;
		}
		dst_p++;
		src_p++;
	}
	if (is_meet)
		return (dst_p);
	return (NULL);
}
