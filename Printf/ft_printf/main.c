#include "ft_printf.h"
#define STR_0 "repl: '%2.3.*s'\n", 5,  "123456789", int_v
#define STR_1 "repl: '%-12.*d'\n", 5, int_v
#define STR_2 "repl: '%-12.*u'\n", 5, int_v
#define STR_3 "repl: '%-12.*x'\n", 5, int_v
#define STR_4 "repl: '%012.*X'\n", 5, -int_v // flag 0 is ignored for d, i, o, u, x, X
#define STR_5 "With type 'c': '%4c'\n", int_v * 10
#define STR_6 "With type 'c': '%-*c'\n", 4, int_v * 10
#define STR_7 "Twice sample 'c': '%-4c' next: '%5d'\n", int_v * 10, 11
#define STR_8 "With type 's': '%20.8s'\n", s_v
#define STR_9 "With type 'p': '%2.20p'\n", s_v
#define STR_10 "With type 'p': '%p'\n", NULL // '0x0'
#define STR_11 "'%c'\n", 0
//#define STR_12 "With percent: '%-0*.*%'\n", 5, 8
#define STR_12 "%07i\n", -54
#define STR_13 "repl: '%06.4d'\n", -12
#define STR_14 "'%2.9p'\n", 1234
#define STR_15 "'%c'\n", 0
#define STR_16 "ASCII [128]: '%c'\n", 128
#define STR_17 "min int: '%d'\n", INT_MIN
#define STR_18 "max '%c'\n", INT_MAX
#define STR_19 "'%0*.*d'\n", 5, -5, '8'
#define STR_20 "'%-5c'\n", '0'
#define STR_21 "%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0
#define STR "%2.9p\n", 4, 1234

int		main(void)
{
	int		int_v = 5;
	char	*s_v = "hello";
	int		repl;
	int		orig = 0;
//	char	*str_v = "hello";
//	char	ch_v = 'c';

//	repl = ft_printf("repl: '%%%d'\n", int_v);
//	repl = ft_printf("repl: '%---2*2d'\n", int_v);
//	repl = ft_printf("repl: '%---*22d'\n", int_v);
//	repl = ft_printf("repl: '%---22.3d'\n", int_v);
	repl = ft_printf(STR_0);
	printf("===============%d====%s==%d=%d\n", int_v, s_v, orig, repl);
//	orig = printf(STR_0);
//	printf("res_o: %d\nres_r: %d\n", orig, repl);
//	while(1);
}
