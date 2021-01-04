#include "../ft_printf.h"

char			*ft_strmultiply(char *c, size_t times)
{
	char		*res;
	char		*tmp;

	res = NULL;
	DEBUG printf("times: [%zu]\n", times);
	if (!times)
		return (ft_strdup(""));
	while (times--)
	{
		tmp = res;
		if (!(res = ft_strjoin(c, res)))
			break ;
		if (tmp)
			free(tmp);
	}
	DEBUG printf("res: '%s'\n", res);
	return (res);
}

static char		*ft_check_precision(t_obj *obj, char *str)
{
	char		*addition;
	char		*tmp;

	DEBUG printf("%d\n", obj->s_precision.numb);
	if (obj->s_precision.numb > (int)ft_strlen(str))
	{
		addition = ft_strmultiply("0", (obj->s_precision.numb - ft_strlen(str)));
		tmp = str;
		str = ft_strjoin(addition, tmp);
		free(tmp);
		free(addition);
	}
	return (str);
}

char		*ft_check_width(t_obj *obj, char *str)
{
	char	*tmp;
	char	*addition;
	DEBUG printf("%d\n", obj->s_width.numb);
	if (obj->s_width.numb > (int)ft_strlen(str))
	{
		if (obj->s_flag.on)
		{
			if (obj->s_flag.numb == '0')
			{
				addition = ft_strmultiply("0", (obj->s_width.numb - ft_strlen(str)));
				tmp = str;
				str = ft_strjoin(addition, tmp);
				free(tmp);
			}
			else if (obj->s_flag.numb == '-')
			{
				addition = ft_strmultiply(" ", (obj->s_width.numb - ft_strlen(str)));
				tmp = str;
				str = ft_strjoin(tmp, addition);
				free(tmp);
			}
		}
		else
		{
			addition = ft_strmultiply(" ", (obj->s_width.numb - ft_strlen(str)));
			tmp = str;
			str = ft_strjoin(addition, tmp);
			free(tmp);
		}
		free(addition);
	}
	return (str);
}

char			*ft_int(t_obj *obj, int val)
{
	char		*str_val;
	int			minus;

	DEBUG printf("PRINTING DIGIT:\t%d[%c]\n", val, obj->s_type.numb);
	minus = val < 0 ? 1 : 0;
	str_val = minus? ft_itoa(-1 * val) : ft_itoa(val);
	DEBUG printf("STR: '%s'\n", str_val);
	if (obj->s_precision.on)
		str_val = ft_check_precision(obj, str_val);
	DEBUG printf("STR: '%s'\n", str_val);
	if (minus)
		if (!(str_val = ft_strjoin("-", str_val)))
			return (NULL);
	if (obj->s_width.on)
		str_val = ft_check_width(obj, str_val);
	printf("STR: '%s'\n", str_val);
	return (str_val);
}