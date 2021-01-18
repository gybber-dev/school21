/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:02:46 by yeschall          #+#    #+#             */
/*   Updated: 2021/01/17 17:02:47 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char			*ft_s(t_obj *obj, char **val)
{
	char		*str_val;

	str_val = NULL;
	if (*val == NULL)
		*val = "(null)";
	if (obj->s_prec.on == 1)
	{
		if ((size_t)obj->s_prec.val < ft_strlen(*val))
		{
			if (!(str_val = ft_calloc((obj->s_prec.val + 1), sizeof(char))))
				return (NULL);
			ft_strlcpy(str_val, *val, obj->s_prec.val + 1);
		}
	}
	if (!str_val)
		str_val = ft_strdup(*val);
	if (obj->s_width.on)
		str_val = ft_check_width(obj, str_val);
	return (str_val);
}
