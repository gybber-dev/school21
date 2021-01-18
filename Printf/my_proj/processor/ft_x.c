/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:02:52 by yeschall          #+#    #+#             */
/*   Updated: 2021/01/17 17:02:54 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char			*ft_x(t_obj *obj, unsigned int val)
{
	char		*str_val;
	char		*p;

	if (val == 0 && obj->s_prec.on && obj->s_prec.val == 0)
		str_val = ft_strdup("");
	else
		str_val = ft_itoa_uhex((unsigned int)val);
	if (obj->s_prec.on)
		str_val = ft_check_precision(obj, str_val);
	if (obj->s_width.on)
		str_val = ft_check_width(obj, str_val);
	if (obj->s_type.val == 'X')
	{
		p = str_val;
		while (*p)
		{
			*p = ft_toupper(*p);
			p++;
		}
	}
	return (str_val);
}
