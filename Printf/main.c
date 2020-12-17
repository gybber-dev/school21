#include "ft_printf.h"

int		main(void)
{
	int		int_v = 12;
	int		repl;
//	char	*str_v = "hello";
//	char	ch_v = 'c';

	int orig = printf("orig: '%---2d'\n", int_v);
	repl = ft_printf("repl: '%---22*d'\n", int_v);
	repl = ft_printf("repl: '%---2*2d'\n", int_v);
	repl = ft_printf("repl: '%---*22d'\n", int_v);
	repl = ft_printf("repl: '%---22d'\n", int_v);
	printf("res_o: %d\nres_r: %d\n", orig, repl);
}