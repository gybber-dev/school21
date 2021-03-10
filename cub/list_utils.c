#include "../ft_cub.h"

void		lst_iter(t_sl *lst, void (*f)(t_sprite *))
{
	if (lst == NULL && !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}