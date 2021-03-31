/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:10:51 by yeschall          #+#    #+#             */
/*   Updated: 2020/11/05 21:06:59 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*ps;

	ps = (const unsigned char*)s;
	while (n--)
	{
		if (*ps == (unsigned char)c)
			return ((void*)ps);
		ps++;
	}
	return (NULL);
}
