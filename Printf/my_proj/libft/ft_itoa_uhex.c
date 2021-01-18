/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 20:14:03 by yeschall          #+#    #+#             */
/*   Updated: 2021/01/17 20:14:05 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		ft_hex(int n)
{
	if (n == 10)
		return ('a');
	else if (n == 11)
		return ('b');
	else if (n == 12)
		return ('c');
	else if (n == 13)
		return ('d');
	else if (n == 14)
		return ('e');
	else if (n == 15)
		return ('f');
	else
		return (n + '0');
}

static size_t	count_len(unsigned long int n)
{
	if (n < 16)
		return (1);
	return (count_len(n / 16) + 1);
}

char			*ft_itoa_uhex(unsigned long int n)
{
	int			len;
	char		*str;

	len = count_len(n);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	str[0] = (n == 0) ? '0' : str[0];
	while (len-- && n != 0)
	{
		str[len] = ft_hex(n % 16);
		n = n / 16;
	}
	return (str);
}
