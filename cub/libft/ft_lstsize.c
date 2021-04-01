/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 03:34:54 by yeschall          #+#    #+#             */
/*   Updated: 2020/11/10 19:32:46 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstsize(t_list *lst)
{
	t_list	*p;
	int		len;

	len = 0;
	p = lst;
	if (p == NULL)
		return (0);
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return (len);
}
