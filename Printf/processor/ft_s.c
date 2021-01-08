#include "../ft_printf.h"

static char			*ft_check_precision_s(t_obj *obj, char *str)
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

char			*ft_s(t_obj *obj, char **val)
{
	char		*str_val;

	str_val = NULL;
	DEBUG printf("PRINTING STRING:\t%s[%c]\n", *val, obj->s_type.numb);
	str_val = ft_strdup(*val);
	DEBUG printf("STR: '%s'\n", str_val);
	// максимальное число символов, которые будут выведены для типа s;
	if (obj->s_precision.on)
		str_val = ft_check_precision_s(obj, str_val);
	DEBUG printf("STR: '%s'\n", str_val);
	if (obj->s_width.on)
		str_val = ft_check_width(obj, str_val);
	DEBUG printf("STR: '%s'\n", str_val);
	return (str_val);
}