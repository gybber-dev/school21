/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:17:07 by yeschall          #+#    #+#             */
/*   Updated: 2020/11/10 17:22:42 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)())
{
	t_list	*p;

	if (*lst == NULL && !del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		p = *lst;
		*lst = (*lst)->next;
		free(p);
	}
}
