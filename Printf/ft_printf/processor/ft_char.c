#include "../ft_printf.h"

char			*ft_char(t_obj *obj, int val)
{
	char		*str_val;
	size_t		addition_len;

	addition_len = 0;
	DEBUG printf("PRINTING CHAR:\t%d[%c]\n", val, obj->s_type.numb);
	addition_len = (obj->s_width.on && obj->s_width.numb > 0) ? (obj->s_width.numb - 1) : 0;
	if (!(str_val = ft_calloc(2 + addition_len, 1)))
		return (NULL);

	DEBUG printf("STR (malloced %zu bytes): '%s'\n", (addition_len + 2), str_val);
	DEBUG printf("foo2\n");

	if (obj->s_width.numb > 1 && obj->s_flag.on && obj->s_flag.numb == '0')
	{
		DEBUG printf("boo2\n");
		ft_memset(str_val, '0', addition_len);
		ft_memset(str_val + addition_len, val, 1);
		//	ft_strlcat(str_val, &val, addition_len + 2);
	}
	else if (obj->s_width.numb > 1 && obj->s_flag.on && obj->s_flag.numb == '-')
	{
		DEBUG printf("boo1\n");
		ft_memset(str_val, val, 1);
		ft_memset(str_val + 1, ' ', addition_len);
		}
	else
	{
		DEBUG printf("boo\n");
		ft_memset(str_val, ' ', addition_len);
		ft_memset(str_val + addition_len, val, 1);
	}
	obj->len = addition_len + 1;
	DEBUG printf("STR (fin) len=%zu: '%s'\n", obj->len, str_val);
//	ft_free(&str_val);
//	while(1);
	return (str_val);
}