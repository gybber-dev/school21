/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:03:26 by yeschall          #+#    #+#             */
/*   Updated: 2021/01/17 17:03:27 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char					*ft_p(t_obj *obj, char **val)
{
	char				*str_val;
	char				*tmp;

	str_val = NULL;
	if (*val)
	{
		if (!(str_val = ft_itoa_uhex((long unsigned int)*val)))
			return (NULL);
		tmp = str_val;
		if (!(str_val = ft_strjoin("0x", str_val)) && ft_free(&tmp))
			return (NULL);
		free(tmp);
	}
	else
	{
		if (obj->s_prec.on && obj->s_prec.val == 0)
			str_val = ft_strdup("0x");
		else if (!(str_val = ft_strdup("0x0")))
			return (NULL);
	}
	if (obj->s_width.on)
		str_val = ft_check_width(obj, str_val);
	return (str_val);
}
