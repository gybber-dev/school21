/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:10:40 by yeschall          #+#    #+#             */
/*   Updated: 2021/01/17 17:10:42 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char			*ft_processor(t_obj *obj, va_list p)
{
	char		*res;
	char		*tmp;

	if (obj->s_type.val == 'd' || obj->s_type.val == 'i')
		res = ft_int(obj, va_arg(p, int));
	if (obj->s_type.val == 'u')
		res = ft_u(obj, va_arg(p, unsigned int));
	if (obj->s_type.val == 'x' || obj->s_type.val == 'X')
		res = ft_x(obj, va_arg(p, unsigned int));
	if (obj->s_type.val == 'c')
		res = ft_char(obj, va_arg(p, int));
	if (obj->s_type.val == 's' || obj->s_type.val == '%')
	{
		tmp = (obj->s_type.val == '%') ? "%" : va_arg(p, char*);
		res = ft_s(obj, &tmp);
	}
	if (obj->s_type.val == 'p')
	{
		tmp = va_arg(p, char*);
		res = ft_p(obj, &tmp);
	}
	if (obj->s_type.val != 'c' && res)
		obj->len = ft_strlen(res);
	return (res);
}
