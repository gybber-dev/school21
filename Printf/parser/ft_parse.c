#include "../ft_printf.h"

/*
** All check functions MUST put the pointer to the next character!
*/
static void		check_flag(const char **str, t_obj *obj)
{
	printf("\nCHECK FLAG: ('%s')\n", *str);

	while (**str == '-' || **str == '0')
	{
		printf("\tflag is detected\n");
		obj->s_flag.val = **str;
		obj->s_flag.size++;

		(*str)++;
	}
	return ;
}

static void		check_width(const char **str, t_obj *obj)
{
	printf("\nCHECK WIDTH: ('%s')\n", *str);

	int just_once;

	just_once = 0;
	while ((**str == '*' && just_once == 0) || (ft_isdigit(**str) && just_once != 1))
	{
		printf("\twidth [%c] is detected\n", **str);
		obj->s_width.size++;
		obj->s_width.began = (just_once == 0) ? *str : NULL;
		just_once = (**str == '*')? 1 : 2;
		(*str)++;
	}
	return ;
}
//
static void		check_precision(const char **str, t_obj *obj)
{
	int just_once;

	printf("CHECK PRECISION: ('%s')\n", *str);
	just_once = 0;
	if (**str == '.')
	{
		obj->s_precision.on = 1;
		printf("\tprecision [%c] is detected\n", **str);
		while ((*(++(*str)) == '*' && !just_once) || (ft_isdigit(**str) && just_once != 1))
		{
			printf("\tprecision val [%c]\n", **str);
			obj->s_precision.size++;
			just_once = (**str == '*')? 1 : 2;
		}
	}
	return ;
}
//
static void		check_type(const char **str, t_obj *obj)
{
	printf("CHECK TYPE: ('%s')\n", *str);
	if (ft_strchr(SUBJ_TYPES, **str))
	{
		printf("\ttype [%c] is detected\n", **str);
		obj->s_type.val = **str;
	}
	return ;
}

t_obj			ft_parse(const char *str)
{
	t_obj		obj;

	printf("PARSER: ('%s')\n\n", str);
	while (*str)
	{
		if (*str == '%' && *(++str) != '%' )
		{
			check_flag(&str, &obj);
			check_width(&str, &obj);
			check_precision(&str, &obj);
			check_type(&str, &obj);
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
	return (obj);
}