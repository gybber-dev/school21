/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 01:57:10 by yeschall          #+#    #+#             */
/*   Updated: 2020/12/06 18:34:21 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++ != 0)
		i++;
	return (i);
}

char			*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return (char *)s;
		s++;
	}
	if (c == 0)
		return (char *)s;
	return (char *)NULL;
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*src_p;
	const char	*src_end;
	char		*dst_p;
	char		*dst_end;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_p = (char *)dst;
	src_p = (char *)src;
	if (dst_p < src_p)
		while (len--)
			*dst_p++ = *src_p++;
	else
	{
		src_end = src_p + (len - 1);
		dst_end = dst_p + (len - 1);
		while (len--)
			*dst_end-- = *src_end--;
	}
	return (dst);
}

/*
	join s1 and s2, and put the result in dst.
	dst's contant will be saved to *tmp and will be cleared
	at the end of function ALWAYS! At the end because s1 may be
	the pointer to the memory of dst
	it works like:
		dst = (s2 == NULL)? s1 : s1 + s2;
	optionaly for clear:
	1: free(s1)
	2: free(s2)
	3: free(s1), free(s2)
*/
int			ft_strjoin(char **dst, char *s1, char *s2, int clear)
{
	char	*res;
	char	*tmp;
	size_t	len1;
	size_t	len2;

	printf("joining:\ns1(%zu): '%s'\ns2(%zu): '%s'\n\tclear? %d\n", ft_strlen(s1), s1, ft_strlen(s2), s2, clear);
	tmp = *dst;
	while (s1 != NULL)
	{
		len1 = ft_strlen(s1);
		len2 = (s2 == NULL)? 0: ft_strlen(s2);
		printf("total: %zu\n", len1 + len2);
		if ((res = (char *)malloc(len1 + len2 + 1)) == NULL)
			break ;
		ft_memmove(res, s1, len1 * sizeof(char));
		res[len1] = 0;
		printf("res<-s1: '%s'\n", res);
		if (len2)
			ft_memmove(&(res[len1]), s2, len2 * sizeof(char));
		res[len1 + len2] = 0;
		*dst = res;
		if (clear == 1 || clear == 3)
			free(s1);
		if (clear == 2 || clear == 3)
			free(s2);
		printf("end join (%zu): '%s'\n\n\n", ft_strlen(*dst), *dst);
		(tmp != NULL) ? free(tmp) : 0;
		return (1);
	}
	(tmp != NULL) ? free(tmp) : 0;
	return (0);
}


int main(void)
{
	char *mem;
	mem = strdup("DRACULACHAPTER IJONATHAN HARKER'S JOURNAL(_Kept in shorthand._)_3 May. Bistritz._--Left Munich at 8:35 P. M., on 1st May, arriving atVienna early next morning; should have arrived at 6:46, but train was anhour late. Buda-Pesth seems a wonderful place, from the glimpse which Igot of it from the train");
	char *buf;
	buf = strdup(" and the little I could walk through thestreets. I feared to go very far from the station, as we had");
	// printf("mem: '%s'\nbuf: '%s'\n", mem, buf);
	ft_strjoin(&mem, mem, buf, 0);
	ft_strjoin(&mem, mem, buf, 0);
	ft_strjoin(&mem, mem, buf, 0);
	ft_strjoin(&mem, mem, buf, 0);
}