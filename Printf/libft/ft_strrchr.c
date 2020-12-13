/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:19:30 by yeschall          #+#    #+#             */
/*   Updated: 2020/11/05 20:58:17 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	const char	*p;
	int			is_matched;

	is_matched = 0;
	while (*s)
	{
		if (*s == (char)c)
		{
			is_matched = 1;
			p = s;
		}
		s++;
	}
	if (is_matched)
		return ((char *)p);
	if (c == 0)
		return ((char *)s);
	return (NULL);
}
