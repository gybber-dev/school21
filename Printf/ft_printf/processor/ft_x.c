#include "../ft_printf.h"

char			*ft_x(t_obj *obj, unsigned int val)
{
	char		*str_val;
	char		*p;

	DEBUG printf("PRINTING X:\t%x[%c]\n", val, obj->s_type.numb);
	if (val == 0 && obj->s_precision.on && obj->s_precision.numb == 0)
		str_val = ft_strdup("");
	else
		str_val = ft_itoa_uhex((unsigned int)val);
	DEBUG printf("STR (itoa): '%s'\n", str_val);
	if (obj->s_precision.on)
		str_val = ft_check_precision(obj, str_val);
	if (obj->s_width.on)
		str_val = ft_check_width(obj, str_val);
	DEBUG printf("STR (fin): '%s'\n", str_val);
	if (obj->s_type.numb == 'X')
	{
		p = str_val;
		while (*p)
		{
			*p = ft_toupper(*p);
			p++;
		}
	}
	return (str_val);
}
