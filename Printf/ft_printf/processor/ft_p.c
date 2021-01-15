#include "../ft_printf.h"

char					*ft_p(t_obj *obj, char **val)
{
	char				*str_val;
	char				*tmp;

	DEBUG printf("PRINTING POINTER:\t%lu\n", (long unsigned int)*val);
	str_val = NULL;
	if (*val)
	{
		if (!(str_val = ft_itoa_uhex((long unsigned int)*val)))
			return (NULL);
		tmp = str_val;
		if (!(str_val = ft_strjoin("0x", str_val)))
		{
			ft_free(&tmp);
			return (NULL);
		}
		free(tmp);
	}
	else
	{
		if (obj->s_precision.on && obj->s_precision.numb == 0)
			str_val = ft_strdup("0x");
		else
			if (!(str_val = ft_strdup("0x0")))
				return (NULL);
	}
	DEBUG printf("STR (itoa_x): '%s'\n", str_val);
	if (obj->s_width.on)
	{
		str_val = ft_check_width(obj, str_val);
	}
	DEBUG printf("STR: '%s'\n", str_val);
	return (str_val);
}