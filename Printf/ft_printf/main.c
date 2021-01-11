#include "ft_printf.h"
#define STR_0 "repl: '%2.*d'\n", 5, int_v
#define STR_1 "repl: '%-12.*d'\n", 5, int_v
#define STR_2 "repl: '%-12.*u'\n", 5, int_v
#define STR_3 "repl: '%-12.*x'\n", 5, int_v
#define STR_5STR_4 "repl: '%012.*X'\n", 5, -int_v // flag 0 is ignored for d, i, o, u, x, X
#define STR_5 "With type 'c': '%4c'\n", int_v * 10
#define STR_6 "With type 'c': '%-*c'\n", 4, int_v * 10
#define STR_7 "Twice sample 'c': '%-4c' next: '%5d'\n", int_v * 10, 11
#define STR_8 "With type 's': '%20.8s'\n", s_v
#define STR_9 "With type 's': '%20p'\n", s_v
#define STR_10 "With type 's': '%p'\n", NULL // '0x0'
#define STR_11 "'%c'\n", 0
//#define STR_12 "With percent: '%-0*.*%'\n", 5, 8
#define STR_12 "%07i\n", -54

int		main(void)
{
	int		int_v = 5;
	char	*s_v = "hello";
	int		repl;
	int		orig;
//	char	*str_v = "hello";
//	char	ch_v = 'c';

//	repl = ft_printf("repl: '%%%d'\n", int_v);
//	repl = ft_printf("repl: '%---2*2d'\n", int_v);
//	repl = ft_printf("repl: '%---*22d'\n", int_v);
//	repl = ft_printf("repl: '%---22.3d'\n", int_v);
	repl = ft_printf(STR_12);
	printf("===================%d==%s=\n", int_v, s_v);
	orig = printf(STR_12);
	printf("res_o: %d\nres_r: %d\n", orig, repl);
}
