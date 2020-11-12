#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h> //size_t
#include "libft.h"

int			main()
{
    char    *str = "test";
    char    *str0 = "";

    printf("TEST\n\n");


    printf("\n== STRLEN ==\n\n");
    printf("For str = '%s':\norig = '%lu'\nrepl = '%lu'\n\n", str, strlen(str), ft_strlen(str));
    printf("For str = '%s':\norig = '%lu'\nrepl = '%lu'\n\n", str0, strlen(str0), ft_strlen(str0));


    printf("\n== MEMSET ==\n\n");
    printf("For size_t n = 0:\n\n");


    printf("\n== ATOI ==\n\n");
    int     N = 21;
    int     i = 0;
    char    *test_arr[N];
    
    test_arr[0] = "123";
    test_arr[1] = "0123";
    test_arr[2] = " 123";
    test_arr[3] = "  123";
    test_arr[4] = "t\v\f\r\n \f-06050";
    test_arr[5] = "1 23";
    test_arr[6] = "+123";
    test_arr[7] = "++123";
    test_arr[8] = "1+23";
    test_arr[9] = "-085";
    test_arr[10] = "+-123";
    test_arr[11] = "-+123";
    test_arr[12] = "--123";
    test_arr[13] = "a";
    test_arr[14] = "";
    test_arr[15] = " ";
    test_arr[16] = "1---23";
    test_arr[17] = "2147483648";
    test_arr[18] = "-9223372036854776000";
    test_arr[19] = "9223372036854775808";
    test_arr[20] = "-99999999999999999999999999";
    while(i < N)
    {
        printf("For '%s' orig: '%d'\n", test_arr[i], atoi(test_arr[i]));
        printf("For '%s' repl: '%d'\n\n", test_arr[i], ft_atoi(test_arr[i]));
        i++;
    }
    i = 0;

    
    printf("\n== ISALPHA ==\n\n");

    int     int_test_arr[] = {1, -2, 74, 65, 'd', 102};
    N = 6;
    i = 0;
    while (i < N)
    {
        printf("For '%c' (%d)\n", int_test_arr[i], int_test_arr[i]);
        printf("orig: %d\n", isalpha(int_test_arr[i]));
        printf("repl: %d\n", ft_isalpha(int_test_arr[i]));
        i++;
    }


    printf("\n== MEMSET0 ==\n\n");
    // size_t  len;
    // char    str_src0[8] = "1234567\0";
    // char    str_src1[8] = "1234567\0";
    // int     symb_code;


    // symb_code = 40;
    // len = 10;
    // memset(str_src0, symb_code, len);
    // ft_memset(str_src1, symb_code, len);
    // printf("orig result: %s\n", str_src0);
    // printf("repl result: %s\n", str_src1);

    printf("\n== STRLCPY ==\n\n");
	// N = 21;
	// while(i < N)
    // {
    //     printf("For '%s' orig: '%d' buf: '%s'\n", test_arr[i], strlcpy(test_arr[i]));
    //     printf("For '%s' repl: '%d'\n\n", test_arr[i], ft_atoi(test_arr[i]));
    //     i++;
    // }
    // i = 0;

    printf("\n== ISDIGIT ==\n\n");

	printf("test: 's'\norig: %d\n", isdigit('s'));
	printf("repl: %d\n", ft_isdigit('s'));
	printf("test: '5'\norig: %d\n", isdigit('5'));
	printf("repl: %d\n", ft_isdigit('5'));
	printf("test: -1000\norig: %d\n", isdigit(-1000));
	printf("repl: %d\n", ft_isdigit(-1000));

    printf("\n== ISALNUM ==\n\n");

	printf("test: 's'\norig: %d\n", isalnum('s'));
	printf("repl: %d\n", ft_isalnum('s'));
	printf("test: '5'\norig: %d\n", isalnum('5'));
	printf("repl: %d\n", ft_isalnum('5'));
	printf("test: 177\norig: %d\n", isalnum(177));
	printf("repl: %d\n", ft_isalnum(177));
	printf("test: ')'\norig: %d\n", isalnum(')'));
	printf("repl: %d\n", ft_isalnum(')'));
	printf("test: 'A'\norig: %d\n", isalnum('A'));
	printf("repl: %d\n", ft_isalnum('A'));
	i = -1;
	while (i < 530)
	{
		if (!!ft_isalnum(i) != !!isalnum(i))
		{
			printf("test: %d\norig: %d\n", i, isalnum(i));
			printf("repl: %d\n\n", ft_isalnum(i));
		}
		i++;
	}

    printf("\n== ISPRINT ==\n\n");
	i = -1;
	while (i < 100)
	{
		if (!!ft_isprint(i) != !!isprint(i))
		{
			printf("test: %d\norig: %d\n", i, isprint(i));
			printf("repl: %d\n", ft_isprint(i));
		}
		i++;
	}

    printf("\n== STRNSTR ==\n\n");

	char *haystack = "MZIRIBMZIRIBMZE123";
	char *needle = "MZIRIBMZE";
	size_t		len = strlen(needle);
	printf("haystack = '%s'\nneedle: %s\nlen = %zu\n", haystack, needle, len);
	printf("orig: '%s'\n", strnstr(haystack, needle, len));
	printf("repl: '%s'\n", ft_strnstr(haystack, needle, len));

	printf("orig: '%s'\n", strnstr("see FF your FF return FF now FF", "FF", 20));
	printf("repl: '%s'\n", ft_strnstr("see FF your FF return FF now FF", "FF", 20));
    
	printf("\n== STRTRIM ==\n\n");

	char *s1 = "MZIRIBMZIRIBMZE123";
	char *s2 = "MZIRIBMZE";
	char *ret = ft_strtrim(s1, " \n\t");
	printf("============\nstr: '%s'\nset: '%s'\n===========\n", s1, s2);
	if (!strcmp(ret, s2))
		printf("nice!!!!\n");
	printf("repl: '%s'\norig: '%s'", ret, s2);
	free(ret);

    printf("\n== FT_SPLIT ==\n\n");

	char **arr;
	// char *str_split = "      split       this for   me  !       ";
	char *str_split = "            ";
	// char *str_split = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
	// printf("words: %zu\n", ft_count_words(str_split, 'a'));
	// printf("words: %zu\n", first_word_len(str_split + 8, 'a'));
	arr = ft_split(str_split, ' ');

	  printf("\n== FT_BONUS ==\n\n");

	t_list *root;
	t_list *p0;
	t_list *p1;
	t_list *p2;
	t_list *p3;
	t_list *p;

	root = NULL;
	printf("there is nothing to count. Len = %d\n", ft_lstsize(root));
	
	p0 = ft_lstnew("root");
	p1 = ft_lstnew("back0");
	p2 = ft_lstnew("back1");
	p3 = ft_lstnew("front0");
	ft_lstadd_back(&root, p0);
	ft_lstadd_back(&root, p1);
	ft_lstadd_back(&root, p2);
	ft_lstadd_front(&root, p3);
	printf("Len after: = %d\n", ft_lstsize(root));
	i = 0;
	p = root;
	while (p->next)
	{
		printf("elem[%d]: '%s'\n", i++, p->content);
		p = p->next;
	}
	p = ft_lstlast(root);
	printf("Last elem: '%s'\n", p->content);
}
