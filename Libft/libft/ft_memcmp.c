/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:19:16 by yeschall          #+#    #+#             */
/*   Updated: 2020/11/05 21:48:49 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int							ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*ps1;
	const unsigned char		*ps2;

	ps1 = (const unsigned char *)s1;
	ps2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*ps1 != *ps2)
			return ((int)(*ps1) - (int)(*ps2));
		ps1++;
		ps2++;
	}
	return (0);
}
