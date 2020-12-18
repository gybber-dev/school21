/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 08:36:49 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/12 16:29:22 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		i = ft_putstr("-2147483648");
		return (i);
	}
	if (nb < 0)
	{
		ft_putchar('-');
		i++;
		nb = nb * (-1);
	}
	if (nb > 9)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
		i++;
	}
	return (i);
}