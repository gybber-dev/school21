#include <stdio.h>

int main(void)
{
	char c = 255;
	printf("%X\n", c);
	printf("%X\n", (unsigned char)c);
	printf("%hhX\n", c);
}