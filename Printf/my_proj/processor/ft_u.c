/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:01:09 by yeschall          #+#    #+#             */
/*   Updated: 2021/01/17 17:01:11 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char			*ft_u(t_obj *obj, unsigned int val)
{
	char		*str_val;

	if (val == 0 && obj->s_prec.on && obj->s_prec.val == 0)
		str_val = ft_strdup("");
	else
		str_val = ft_itoa_u((unsigned int)val);
	if (obj->s_prec.on && str_val)
		str_val = ft_check_precision(obj, str_val);
	if (obj->s_width.on && str_val)
		str_val = ft_check_width(obj, str_val);
	return (str_val);
}
