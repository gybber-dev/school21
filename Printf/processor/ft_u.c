#include "../ft_printf.h"

char			*ft_u(t_obj *obj, unsigned int val)
{
	char		*str_val;
//	int			minus;

	DEBUG printf("PRINTING U:\t%u[%c]\n", val, obj->s_type.numb);
	str_val = ft_itoa(val);
	DEBUG printf("STR: '%s'\n", str_val);
//	if (obj->s_precision.on)
//		str_val = ft_check_precision(obj, str_val);
//	DEBUG printf("STR: '%s'\n", str_val);
//	if (minus)
//		if (!(str_val = ft_strjoin("-", str_val)))
//			return (NULL);
//	if (obj->s_width.on)
//		str_val = ft_check_width(obj, str_val);
//	DEBUG printf("STR: '%s'\n", str_val);
	return (str_val);
}