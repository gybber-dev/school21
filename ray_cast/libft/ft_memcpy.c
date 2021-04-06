/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:00:26 by yeschall          #+#    #+#             */
/*   Updated: 2020/11/05 21:05:45 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
