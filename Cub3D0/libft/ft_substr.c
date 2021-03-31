/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:49:57 by yeschall          #+#    #+#             */
/*   Updated: 2020/11/09 19:01:55 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;
	size_t			lost;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	if (i <= start || len == 0)
		return (ft_strdup(""));
	lost = (size_t)i - (size_t)start;
	lost = (lost >= len) ? (len + 1) : (lost + 1);
	p = (char *)malloc(lost * sizeof(char));
	if (p == NULL)
		return (NULL);
	ft_bzero(p, lost);
	ft_strlcat(p, s + start, lost);
	return (p);
}
