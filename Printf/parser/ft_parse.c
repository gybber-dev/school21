#include "../ft_printf.h"

t_struct		ft_parse(char *str)
{
	t_struct	obj;

	printf("PARSER: ('%s')\n\n", str);
	obj.flags = 1;
	return (obj);
}