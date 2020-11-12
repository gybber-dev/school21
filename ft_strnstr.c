/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:06:53 by yeschall          #+#    #+#             */
/*   Updated: 2020/11/09 20:41:35 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	size_t	needle_len;
	char	*p;

	needle_len = ft_strlen(needle);
	j = 0;
	if (needle_len == 0)
		return ((char *)haystack);
	while (*haystack != 0 && len-- >= needle_len)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
