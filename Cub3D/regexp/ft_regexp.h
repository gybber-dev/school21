#ifndef FT_REGEXP_H
# define FT_REGEXP_H

# include "../libft/libft.h"

/*
** REGEXP LITE IMPLEMENTATION:
** Symbol classes:
** \d - any number [1, 10, 432, ..]
** \s -
*/

int				reg_test(char *rule, char c);
char			*reg_find_symbol(char *rule, char *str);
char			*reg_pass_string(char *rule, char *str);

#endif