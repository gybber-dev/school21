/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:51:02 by yeschall          #+#    #+#             */
/*   Updated: 2020/11/09 18:50:52 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "CONST.h"
#include "libft.h"

static size_t	count_len(int n)
{
	if (n > -10 && n < 10)
	{
		if (n < 0)
			return (2);
		else
			return (1);
	}
	return (count_len(n / 10) + 1);
}

char			*ft_itoa(int n)
{
	int			minus;
	size_t		len;
	char		*str;
	char		*p;

	len = count_len(n);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, len + 1);
	str[0] = (n < 0) ? '-' : str[0];
	str[0] = (n == 0) ? '0' : str[0];
	p = (n < 0) ? str + 1 : str;
	while (len-- && n != 0)
	{
		str[len] = (n < 0) ? -(n % 10) + '0' : (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
