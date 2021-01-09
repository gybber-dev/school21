#include "../ft_printf.h"

char			*ft_char(t_obj *obj, int val)
{
	char		*str_val;

	DEBUG printf("PRINTING CHAR:\t%d[%c]\n", val, obj->s_type.numb);
	if (!(str_val = ft_strdup((char *)&val)))
		return (NULL);
	DEBUG printf("STR (dupes): '%s'\n", str_val);
	if (obj->s_width.on)
	{
		str_val = ft_check_width(obj, str_val);
		if (!str_val)
			return (NULL);
	}
	DEBUG printf("STR (fin): '%s'\n", str_val);
	return (str_val);
}