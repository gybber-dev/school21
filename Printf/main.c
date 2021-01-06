#include "ft_printf.h"
#define STR_0 "repl: '%2.*d'\n", 5, int_v
#define STR_1 "repl: '%-12.*d'\n", 5, int_v
#define STR_2 "repl: '%-12.*u'\n", 5, int_v
#define STR_3 "repl: '%-12.*x'\n", 5, int_v
#define STR_4 "repl: '%012.*X'\n", 5, -int_v // flag 0 is ignored for d, i, o, u, x, X

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
	repl = ft_printf(STR_4);
	printf("======================\n");
	orig = printf(STR_4);
	DEBUG printf("res_o: %d\nres_r: %d\n", orig, repl);
}