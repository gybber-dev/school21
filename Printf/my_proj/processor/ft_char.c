/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:08:35 by yeschall          #+#    #+#             */
/*   Updated: 2021/01/17 17:08:37 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char			*ft_char(t_obj *obj, int val)
{
	char		*str_val;
	size_t		addition_len;

	addition_len = 0;
	if (obj->s_width.on && obj->s_width.val > 0)
		addition_len = obj->s_width.val - 1;
	if (!(str_val = ft_calloc(2 + addition_len, 1)))
		return (NULL);
	if (obj->s_width.val > 1 && obj->s_flag.on && obj->s_flag.val == '0')
	{
		ft_memset(str_val, '0', addition_len);
		ft_memset(str_val + addition_len, val, 1);
	}
	else if (obj->s_width.val > 1 && obj->s_flag.on && obj->s_flag.val == '-')
	{
		ft_memset(str_val, val, 1);
		ft_memset(str_val + 1, ' ', addition_len);
	}
	else
	{
		ft_memset(str_val, ' ', addition_len);
		ft_memset(str_val + addition_len, val, 1);
	}
	obj->len = addition_len + 1;
	return (str_val);
}
