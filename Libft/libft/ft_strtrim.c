/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:53:38 by yeschall          #+#    #+#             */
/*   Updated: 2020/11/15 15:33:44 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s1, char const *set)
{
	size_t			len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (ft_strlen(set) == 0)
		return ((char *)s1);
	else
	{
		while (*s1 != 0 && (ft_strchr(set, *s1) != NULL))
			s1++;
		len = ft_strlen(s1);
		if (len == 0)
			return (ft_substr(s1, 0, 0));
		// check for str: "      c       "; set: " "
		while (ft_strchr(set, s1[len - 1]) != NULL && len != 0)
			len--;
	}
	return (ft_substr(s1, 0, len + 1));
}
