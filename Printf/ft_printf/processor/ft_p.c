#include "../ft_printf.h"

char					*ft_p(t_obj *obj, char **val)
{
	char				*str_val;
	long unsigned int	numb;
	char				*tmp;

	numb = 0;
	DEBUG printf("PRINTING POINTER:\t%lu\n", numb);
	str_val = NULL;
	if (*val)
	{
		numb = (long unsigned int)&(**val);
		if (!(str_val = ft_itoa_uhex((long unsigned int)*val)))
			return (NULL);
		tmp = str_val;
		if (!(str_val = ft_strjoin("0x", str_val)))
		{
			free(tmp);
			return (NULL);
		}
		free(tmp);
	}
	else
	{
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