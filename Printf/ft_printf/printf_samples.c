#include <stdio.h>
#include <stdlib.h>
# define INT_MAX 2147483647
# define INT_MIN (-INT_MAX-1)

int main(void)
{
	int		int_v = 12;
	printf("repl: '%06d'\n", -int_v);
	//- then 0: is last 0 a width?		-last 0 included to flag
	printf("Sample: '%000000002d'\n", 2);

	// Does multiple digits for width mean multi range number? - Yes, multi-rangs number is available
	printf("Sample: '%-12d'\n", 2);

	// test the behavior when several * in width: - Only one * is required
	printf("Sample: '%-**d'\n", 1, 2);

	// test the precision beginning from 0:
	printf("Sample: '%.00000005d'\n", 2);

	// test if printf is working with multiple dots
	printf("Multiple dots (dots): '%...5d'\n", 2);
	char *str = "";
	printf("ATOI: '%s' is '%d'\n", str, atoi(str));

	//	test printf behaviour for different values of Flag (0, -, NONE):
	printf("FLAG Behaviour:\n-5d:\t'%-5d'\n05d\t'%05d'\n5d\t'%5d'\n", int_v, int_v, int_v);

	//	test the string displaying for different values of precision:
	char *s = "sample";
	printf("PRECISION for strings:\n\t'%.3s'\n", s);		// sam - cut the string
	printf("PRECISION for strings:\n\t'%-9.3s'\n", s);		// sam - cut the string
	printf("PRECISION for NULL:\n\t'%.3s'\n", NULL);		// '(nu' if precision < strlen("(null)")
	printf("PRECISION for digits :\n\t'%.3d'\n", (int_v * 100));	//1200 - not cut
	printf("PRECISION for digits :\n\t'%8.6d'\n", (int_v * -100));	//001200 - not cut

	//	test printf behaviour with type 'u':
	printf("With type 'u': '%u'\n", int_v * -1);

	//	test printf behaviour with type 'c':
	printf("With type 'c': '%4c'\n", int_v * 10); // '   x'

	//	test printf's behaviour with type 'p':
	printf("With type 'p': '%13p'\n", s);
	printf("%d\n", printf("1\n"));

	//	test printf's behaviour without types:
	printf("With %% : '%0*.*%'\n", 5, 4);
	printf("With str: '%0*.*s'\n", 8, 6, "%%%%%%%%%%");
	printf("Without types: '%0*%'\n", 5);

	printf("Percent: '%------%'\n");   // %
	printf("Percent: '%------s'\n", "%");   // %
	printf("Percent: '%-05%'\n");   // %
	printf("Percent: '%0-5%'\n");   // %
	printf("'%2.9p'\n", 1234);   // %
	printf("ASCII [128]: '%c'\n", 128);   // %
	printf("Flag is set and flag will set by width: '%0*d'\n", INT_MIN, 1);
	printf("Flag is set and flag will set by width: '%0*d'\n", INT_MIN, 1);
	printf("Flag is set and flag will set by width: '%-2147483648d'\n", INT_MIN);
	printf("res: %d\n", printf("%s\n", "a\0a"));
	printf("0 char returns: %d\n", printf("%c", '\0')); // 1
	printf("Char with width = 0: '%*c'\n", 0, 'a');

	if (printf("") || printf("1\n") || printf("2\n"))
		printf("DONE %d\n", printf(""));
}