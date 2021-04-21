/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmultiply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:24:02 by yeschall          #+#    #+#             */
/*   Updated: 2021/03/11 16:25:16 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** returns N [times] times repeated string [*c]
** 	NULL on error
*/

char			*ft_strmultiply(char *c, size_t times)
{
	char		*res;
	char		*tmp;

	res = NULL;
	if (times == 0)
		return (ft_strdup(""));
	while (times--)
	{
		tmp = res;
		if (!(res = ft_strjoin(c, res)))
		{
			if (tmp)
				free(tmp);
			break ;
		}
		if (tmp)
			free(tmp);
	}
	return (res);
}
