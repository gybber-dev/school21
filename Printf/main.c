#include "ft_printf.h"
#define DIGIT_0 "repl: '%2.*d'\n", 5, int_v
#define DIGIT_1 "repl: '%-12.*d'\n", 5, int_v

int		main(void)
{
	int		int_v = -12;
	int		repl;
	int		orig;
//	char	*str_v = "hello";
//	char	ch_v = 'c';

//	repl = ft_printf("repl: '%%%d'\n", int_v);
//	repl = ft_printf("repl: '%---2*2d'\n", int_v);
//	repl = ft_printf("repl: '%---*22d'\n", int_v);
//	repl = ft_printf("repl: '%---22.3d'\n", int_v);
	repl = ft_printf(DIGIT_1);
	printf("======================\n");
	orig = printf(DIGIT_1);
	DEBUG printf("res_o: %d\nres_r: %d\n", orig, repl);
}