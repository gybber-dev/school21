/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:32:30 by yeschall          #+#    #+#             */
/*   Updated: 2021/01/17 16:32:33 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** All check functions MUST put the pointer to the next character!
** I'm in prod branch
*/

static void		parse_flag(const char **str, t_obj *obj)
{
	while (**str == '-' || **str == '0')
	{
		if (**str == '0' && obj->s_flag.on == 1)
		{
			(*str)++;
			continue ;
		}
		obj->s_flag.on = 1;
		obj->s_flag.val = **str;
		(*str)++;
	}
	return ;
}

static void		parse_width(const char **str, t_obj *obj, va_list p)
{
	int			flag;

	flag = 0;
	while (**str == '*' || ft_isdigit(**str))
	{
		obj->s_width.on = 1;
		if (**str == '*' && !flag)
		{
			flag = 1;
			obj->s_width.val = va_arg(p, int);
		}
		else if (flag != 1)
		{
			obj->s_width.val = obj->s_width.val * 10 + (**str) - '0';
		}
		(*str)++;
	}
	return ;
}

static void		parse_precision(const char **str, t_obj *obj, va_list p)
{
	int			flag;

	while (**str == '.')
	{
		(*str)++;
		flag = 0;
		obj->s_prec.on = 1;
		obj->s_prec.val = 0;
		while (**str == '*' || ft_isdigit(**str))
		{
			obj->s_prec.on = 1;
			if (**str == '*' && flag != 2)
			{
				flag = 2;
				obj->s_prec.val = va_arg(p, int);
			}
			else if (flag != 2)
			{
				obj->s_prec.val = obj->s_prec.val * 10 + (**str) - '0';
				flag = 1;
			}
			(*str)++;
		}
	}
	return ;
}

static void		parse_type(const char **str, t_obj *obj)
{
	if (ft_strchr(SUBJ_TYPES, **str))
	{
		obj->s_type.val = **str;
		obj->s_type.on = 1;
	}
	return ;
}

t_obj			ft_parse(const char **str, va_list p)
{
	t_obj		obj;

	ft_init_obj(&obj);
	if (**str)
		parse_flag(str, &obj);
	if (**str)
		parse_width(str, &obj, p);
	if (**str)
		parse_precision(str, &obj, p);
	if (**str)
		parse_type(str, &obj);
	check_additional_rules(&obj);
	return (obj);
}
