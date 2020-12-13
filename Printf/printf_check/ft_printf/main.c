#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	   printf("orig: '%x'\n", 1221);
	ft_printf("repl: '%x'\n", 1221);
}