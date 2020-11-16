/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:26:29 by yeschall          #+#    #+#             */
/*   Updated: 2020/11/16 19:06:00 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*res;
	size_t	len;

	len = ft_strlen(s1) + 1;
	res = (char *)malloc(len * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, s1, len);
	return (res);
}
