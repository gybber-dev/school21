#include "../ft_printf.h"

char			*ft_check_precision(t_obj *obj, char *str)
{
	char		*addition;
	char		*tmp;

	DEBUG printf("%d\n", obj->s_precision.numb);
	if (str && obj->s_precision.numb > (int)ft_strlen(str))
	{
		addition = ft_strmultiply("0", (obj->s_precision.numb - ft_strlen(str)));
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

char		*ft_check_width(t_obj *obj, char *str)
{
	char	*tmp;
	char	*addition;
//	char	add_symb;
	DEBUG printf("%d\n", obj->s_width.numb);
	if (str && obj->s_width.numb > (int)ft_strlen(str))
	{
		if (obj->s_flag.on)
		{
//			add_symb = (obj->s_flag.numb == '0') ? '0' : '-';
			if (obj->s_flag.numb == '0')
			{
				addition = ft_strmultiply("0", (obj->s_width.numb - ft_strlen(str)));
				tmp = str;
				str = ft_strjoin(addition, tmp);
				ft_free(&tmp);
			}
			if (obj->s_flag.numb == '-')
			{
				addition = ft_strmultiply(" ", (obj->s_width.numb - ft_strlen(str)));
				tmp = str;
				str = ft_strjoin(tmp, addition);
				ft_free(&tmp);
			}
		}
		else
		{
			addition = ft_strmultiply(" ", (obj->s_width.numb - ft_strlen(str)));
			tmp = str;
			str = ft_strjoin(addition, tmp);
			ft_free(&tmp);
		}
		ft_free(&addition);
	}
	return (str);
}

char			*ft_int(t_obj *obj, int val)
{
	char		*str_val;
	int			minus;
	char		*tmp;
//	int			add_len;

	DEBUG printf("PRINTING DIGIT:\t%d[%c]\n", val, obj->s_type.numb);
	minus = val < 0 ? 1 : 0;
//	add_len = 0;
	if (val == 0 && obj->s_precision.on && obj->s_precision.numb == 0)
		str_val = ft_strdup("");
	else
	{
		str_val = ft_itoa(val);
		if (minus)
		{
			tmp = str_val;
			str_val = ft_strtrim(str_val, "-");
			ft_free(&tmp);
		}

	}
	DEBUG printf("STR: '%s'\n", str_val);

	if (obj->s_precision.on && str_val && (obj->s_precision.numb > (int)ft_strlen(str_val)))
	{
//		add_len = obj->s_precision.numb - ft_strlen(str_val);
		str_val = ft_check_precision(obj, str_val);
	}

	DEBUG printf("STR (precis): '%s'\n", str_val);

	// всегда ставим минус, за исключением случая, когда задана ширина и флаг '0'
	if (minus && !(obj->s_flag.on && obj->s_flag.numb == '0' &&
				   obj->s_width.on && (obj->s_width.numb > (int)ft_strlen(str_val))))
	{
		tmp = str_val;
		if (!(str_val = ft_strjoin("-", str_val)))
			return (NULL);
		minus = 0;
		ft_free(&tmp);
	}
	if (obj->s_width.on)
	{
		str_val = ft_check_width(obj, str_val);
		if (minus && obj->s_flag.on && obj->s_flag.numb == '0' && *str_val == '0')
		{
			*str_val = '-';
			minus = 0;
		}
	}
	DEBUG printf("STR: '%s'\n", str_val);
	return (str_val);
}