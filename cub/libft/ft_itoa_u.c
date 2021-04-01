/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:17:46 by yeschall          #+#    #+#             */
/*   Updated: 2021/03/11 16:17:50 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(unsigned int n)
{
	if (n < 10)
		return (1);
	return (count_len(n / 10) + 1);
}

char			*ft_itoa_u(unsigned int n)
{
	size_t		len;
	char		*str;

	len = count_len(n);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, len + 1);
	str[0] = (n == 0) ? '0' : str[0];
	while (len-- && n != 0)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
