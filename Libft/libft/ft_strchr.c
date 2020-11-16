/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:50:23 by yeschall          #+#    #+#             */
/*   Updated: 2020/11/16 19:12:35 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *s, int c)
{
	if (c == 0)
		return (char *)s;
	while (*s)
	{
		if (*s == (char)c)
			return (char *)s;
		s++;
	}
	return (char *)NULL;
}
