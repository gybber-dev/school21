#include "ft_printf.h"

int		main(void)
{
	int		int_v = 12;
//	char	*str_v = "hello";
//	char	ch_v = 'c';

	int orig = printf("orig: '%---d'\n", int_v);
	int repl = ft_printf("0--repl: '%---d'\n", int_v);
	printf("res_o: %d\nres_r: %d\n", orig, repl);
}