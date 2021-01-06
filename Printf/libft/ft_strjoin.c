/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:52:05 by yeschall          #+#    #+#             */
/*   Updated: 2020/11/06 22:29:21 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** Just join s1 and s2. If s2 == NULL malloc the memory for s1
** return:
** malloced char* on success
** NULL on error
*/

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*res;
	size_t		len1;
	size_t		len2;

	res = NULL;
	if (s1 != NULL)
	{
		len1 = ft_strlen(s1);
		len2 = (s2 == NULL) ? 0 : ft_strlen(s2);
		if ((res = (char *)malloc(len1 + len2 + 1)) == NULL)
			return (res);
		ft_memmove(res, s1, len1 * sizeof(char));
		if (len2)
			ft_memmove(&(res[len1]), s2, len2 * sizeof(char));
		res[len1 + len2] = 0;
	}
	return (res);
}
