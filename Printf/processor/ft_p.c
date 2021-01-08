#include "../ft_printf.h"

char			*ft_p(t_obj *obj, char **val)
{
	char		*str_val;

	str_val = NULL;
	if (*val == NULL)
		*val = "(null)";
	DEBUG printf("PRINTING STRING:\t%s[%c]\n", *val, obj->s_precision.numb);
	if (obj->s_precision.on == 1)
	{
		if ((size_t )obj->s_precision.numb < ft_strlen(*val))
		{
			DEBUG printf("\tval: '%s'\n\tstr_val: '%s'\n", *val, str_val);
			DEBUG printf("\tcalloc: [%d]\n", obj->s_precision.numb + 1);
			if (!(str_val = ft_calloc((obj->s_precision.numb + 1), sizeof(char))))
				return (NULL);
			ft_strlcpy(str_val, *val, obj->s_precision.numb + 1);
			DEBUG printf("\tstr_val: '%s'\n", str_val);
		}
	}
	if (!str_val)
		str_val = ft_strdup(*val);
	DEBUG printf("STR: '%s'\n", str_val);
	if (obj->s_width.on)
		str_val = ft_check_width(obj, str_val);
	DEBUG printf("STR: '%s'\n", str_val);
	return (str_val);
}