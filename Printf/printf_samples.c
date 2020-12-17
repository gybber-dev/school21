#include <stdio.h>

int main(void)
{
	//- then 0: is last 0 a width?		-last 0 included to flag
	printf("Sample: '%000000002d'\n", 2);

	// Does multiple digits for width mean multi range number? - Yes, multi-rangs number is available
	printf("Sample: '%-12d'\n", 2);

	// test the behavior when several * in width:
	printf("Sample: '%-**d'\n", 1, 2);
}