/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:17:32 by yeschall          #+#    #+#             */
/*   Updated: 2021/01/17 19:17:37 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char			*ft_check_precision(t_obj *obj, char *str)
{
	char		*addition;
	char		*tmp;

	if (str && obj->s_prec.val > (int)ft_strlen(str))
	{
		addition = ft_strmultiply("0", (obj->s_prec.val - ft_strlen(str)));
		tmp = str;
		str = ft_strjoin(addition, tmp);
		free(tmp);
		free(addition);
	}
	return (str);
}

/*
** Concat additional string to str
** free str
** returns joined string or NULL on error
*/

char			*ft_check_width(t_obj *obj, char *s)
{
	char		*res;

	if (s && obj->s_width.val > (int)ft_strlen(s))
	{
		if (!(res = ft_calloc(obj->s_width.val + 1, 1)))
			return (NULL);
		if (obj->s_flag.on && (obj->s_flag.val == '0'))
		{
			ft_memset(res, '0', obj->s_width.val - ft_strlen(s));
			ft_memcpy(res + obj->s_width.val - ft_strlen(s), s, ft_strlen(s));
		}
		if (obj->s_flag.on && (obj->s_flag.val == '-'))
		{
			ft_memcpy(res, s, ft_strlen(s));
			ft_memset(res + ft_strlen(s), ' ', obj->s_width.val - ft_strlen(s));
		}
		else if (!obj->s_flag.on)
		{
			ft_memset(res, ' ', obj->s_width.val - ft_strlen(s));
			ft_memcpy(res + obj->s_width.val - ft_strlen(s), s, ft_strlen(s));
		}
		ft_free(&s);
		return (res);
	}
	return (s);
}

static char		*check_0(t_obj *obj, int val, int *minus)
{
	char		*tmp;
	char		*str;

	*minus = val < 0 ? 1 : 0;
	if (val == 0 && obj->s_prec.on && obj->s_prec.val == 0)
		str = ft_strdup("");
	else
	{
		str = ft_itoa(val);
		if (*minus)
		{
			tmp = ft_strtrim(str, "-");
			ft_free(&str);
			str = tmp;
		}
	}
	return (str);
}

char			*ft_int(t_obj *obj, int val)
{
	char		*str;
	int			minus;
	char		*tmp;

	str = check_0(obj, val, &minus);
	if (obj->s_prec.on && str && (obj->s_prec.val > (int)ft_strlen(str)))
		str = ft_check_precision(obj, str);
	if (minus && !(obj->s_flag.on && obj->s_flag.val == '0' &&
		obj->s_width.on && (obj->s_width.val > (int)ft_strlen(str))))
	{
		tmp = str;
		if (!(str = ft_strjoin("-", str)))
			return (NULL);
		minus = ft_free(&tmp) == 1 ? 0 : 0;
	}
	if (obj->s_width.on)
	{
		str = ft_check_width(obj, str);
		if (minus && obj->s_flag.on && obj->s_flag.val == '0' && *str == '0')
		{
			*str = '-';
			minus = 0;
		}
	}
	return (str);
}
