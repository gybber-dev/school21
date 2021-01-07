#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int		int_v = 12;
	printf("repl: '%22.3d'\n", int_v);
	//- then 0: is last 0 a width?		-last 0 included to flag
	printf("Sample: '%000000002d'\n", 2);

	// Does multiple digits for width mean multi range number? - Yes, multi-rangs number is available
	printf("Sample: '%-12d'\n", 2);

	// test the behavior when several * in width: - Only one * is required
	printf("Sample: '%-**d'\n", 1, 2);

	// test the precision beginning from 0:
	printf("Sample: '%.00000005d'\n", 2);

	// test if printf is working with multiple dots
	printf("Sample (dots): '%...5d'\n", 2);
	char *str = "";
	printf("ATOI: '%s' is '%d'\n", str, atoi(str));

	//	test printf behaviour for different values of Flag (0, -, NONE):
	printf("FLAG Behaviour:\n-5d:\t'%-5d'\n05d\t'%05d'\n5d\t'%5d'\n", int_v, int_v, int_v);

	//	test the string displaying for different values of precision:
	char *s = "sample";
	printf("PRECISION for strings:\n\t%.3s\n", s);		// sam - cut the string
	printf("PRECISION for digits :\n\t%.3d\n", (int_v * 100));	//1200 - not cut
	printf("PRECISION for digits :\n\t'%8.6d'\n", (int_v * -100));	//001200 - not cut

	//	test printf behaviour with type 'u':
	printf("With type 'u': '%u'\n", int_v * -1);

	//	test printf behaviour with type 'c':
	printf("With type 'c': '%4c'\n", int_v * 10);
}