#include "../ft_printf.h"

char			*ft_u(t_obj *obj, unsigned int val)
{
	char		*str_val;

	DEBUG printf("PRINTING U:\t%u[%c]\n", val, obj->s_type.numb);
	if (val == 0 && obj->s_precision.on && obj->s_precision.numb == 0)
		str_val = ft_strdup("");
	else
		str_val = ft_itoa_u((unsigned int)val);
	DEBUG printf("STR: '%s'\n", str_val);
	if (obj->s_precision.on)
		str_val = ft_check_precision(obj, str_val);
	if (obj->s_width.on)
		str_val = ft_check_width(obj, str_val);
	DEBUG printf("STR: '%s'\n", str_val);
	return (str_val);
}