# include <stdio.h>
# define DEBUG_ON 1 == 0 ? printf("%s", "") : // TRUE condition to OFF debug mode
# define DEBUG_OFF 1 == 1 ? printf("%s", "") :
# define DEBUG DEBUG_ON
# define INT_MAX 2147483647
# define INT_MIN (-INT_MAX-1)