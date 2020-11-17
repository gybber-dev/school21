/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 22:33:28 by yeschall          #+#    #+#             */
/*   Updated: 2020/11/13 18:40:08 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	char		*p;
	int			in_word;
	size_t		len;

	len = 0;
	in_word = 0;
	p = (char *)s;
	while (*p != 0)
	{
		if (in_word == 0)
			in_word = (*p != c) ? 1 : 0;
		else
		{
			in_word = (*p != c) ? 1 : 0;
			if (*p == c)
				len++;
		}
		p++;
	}
	len = (in_word == 1) ? len + 1 : len;
	return (len);
}

static size_t	get_first_word_len(const char **p, char c)
{
	int			in_word;
	int			found;
	size_t		len;

	len = 0;
	in_word = 0;
	found = 0;
	while (**p != 0)
	{
		if (in_word == 0)
		{
			in_word = (**p != c) ? 1 : 0;
			if (**p != c && found == 1)
				break ;
		}
		else
		{
			in_word = (**p != c) ? 1 : 0;
			if (**p == c && len != 0 && found == 0)
				found = 1;
		}
		len = (**p != c && found == 0) ? len + 1 : len;
		(*p)++;
	}
	return (len);
}

char			**ft_split(char const *s, char c)
{
	char		**arr;
	size_t		i;
	size_t		arr_len;

	if (s == NULL)
		return (NULL);
	while (*s == c && *s != 0)
		s++;
	arr_len = count_words(s, c);
	arr = (char **)malloc((arr_len + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = -1;
	while (++i < arr_len)
	{
		if ((arr[i] = ft_substr(s, 0, get_first_word_len(&s, c))) == NULL)
		{
			while (--i >= 0)
				free(arr[i]);
			free(arr);
			return (NULL);
		}
	}
	arr[i] = NULL;
	return (arr);
}
