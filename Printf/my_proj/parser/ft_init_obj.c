/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:32:07 by yeschall          #+#    #+#             */
/*   Updated: 2021/01/17 16:32:12 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_init_flag(t_part *flag)
{
	flag->val = 0;
	flag->on = 0;
}

void			ft_init_obj(t_obj *obj)
{
	ft_init_flag(&obj->s_flag);
	ft_init_flag(&obj->s_width);
	ft_init_flag(&obj->s_prec);
	ft_init_flag(&obj->s_type);
	obj->len = 0;
	return ;
}

/*
** 0. If precision < 0 then precision is not defined
** 1. For diouxX if precision is defined flag '0' is switched off
** 2. If width < 0 switch the flag to the '-', and width = -width
*/

void			check_additional_rules(t_obj *obj)
{
	if (obj->s_prec.on && obj->s_prec.val < 0)
	{
		obj->s_prec.on = 0;
		obj->s_prec.val = 0;
	}
	if (obj->s_flag.on && obj->s_flag.val == '0' && obj->s_prec.on &&
		obj->s_type.on && ft_strchr("diouxX", obj->s_type.val))
	{
		obj->s_flag.on = 0;
		obj->s_flag.val = 0;
	}
	if (obj->s_width.on && obj->s_width.val < 0)
	{
		obj->s_flag.on = 1;
		obj->s_flag.val = '-';
		obj->s_width.val *= -1;
	}
}
