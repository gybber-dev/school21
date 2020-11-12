/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:06:53 by yeschall          #+#    #+#             */
/*   Updated: 2020/11/09 20:04:08 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	size_t	reading;
	char	*p;

	reading = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (*haystack && len--)
	{
		if (*haystack == needle[j])
		{
			p = (!reading) ? (char *)haystack : p;
			reading = (!reading) ? 1 : reading;
			j++;
		}
		else
		{
			reading = 0;
			j = 0;
		}
		if (needle[j] == 0 && reading)
			return (p);
		haystack++;
	}
	return (NULL);
}
