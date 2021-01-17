/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 20:39:45 by yeschall          #+#    #+#             */
/*   Updated: 2021/01/15 20:39:47 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *str, ...)
{
	va_list		p;
	t_obj		obj;
	char		*res;
	int			res_num;

	va_start(p, str);
	res_num = 0;
	while (*str)
	{
		if (*str == '%' && *(str++) != '\0')
		{
			obj = ft_parse(&str, p);
			res = obj.s_type.on ? ft_processor(&obj, p) : NULL;
			if (res == NULL && (res_num = -1 * ft_free(&res)) == -1)
				break ;
			write(1, res, obj.len);
			ft_free(&res);
			res_num += obj.len;
		}
		else if (++res_num)
			write(1, str, 1);
		str++;
	}
	va_end(p);
	return (res_num);
}
