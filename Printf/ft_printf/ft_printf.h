#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SUBJ_TYPES "cspdiuxX%"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# include <stdio.h>
# define DEBUG_ON 1 == 0 ? printf("%s", "") : // TRUE condition to OFF debug mode
# define DEBUG_OFF 1 == 1 ? printf("%s", "") :
# define DEBUG DEBUG_ON


/*
** on	-	flag is in a line
** numb	-	parsed value
** type	-	for params with *:
**		 0	init value;
**		 1	describes by digits;
**		 2	describes by *;
**		-1	reserved for errors;
*/
typedef struct	s_part
{
	size_t		size;
	int			on;
	int			type;
	const char	*began;
	char		val;
	int			numb;
}				t_part;

typedef struct	s_obj
{
	struct		s_part s_flag;
	struct		s_part s_width;
	struct		s_part s_precision;
	struct		s_part s_type;
	size_t		len;
}				t_obj;

int				ft_printf(const char *str, ...);
t_obj			ft_parse(const char **str, va_list p);
void			ft_init_obj(t_obj *obj);
char			*ft_processor(t_obj *obj, va_list p);
char			*ft_check_precision(t_obj *obj, char *str);
char			*ft_check_width(t_obj *obj, char *str);
char			*ft_int(t_obj *obj, int val);
char			*ft_u(t_obj *obj, unsigned int val);
char			*ft_x(t_obj *obj, unsigned int val);
char			*ft_char(t_obj *obj, int val);
char			*ft_s(t_obj *obj, char **val);
char			*ft_p(t_obj *obj, char **val);
#endif