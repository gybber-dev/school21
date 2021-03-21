/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:07:40 by yeschall          #+#    #+#             */
/*   Updated: 2021/03/11 16:18:25 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_atoi(const char *str)
{
	int				i;
	int				minus;
	long long int	max;
	long long int	result;

	i = 0;
	minus = 1;
	result = 0;
	max = result;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		minus = str[i++] == '-' ? -1 : minus;
	while (str[i] >= '0' && str[i] <= '9')
	{
		max = result;
		result = result * 10 + (str[i] - '0');
		if (max > result)
		{
			result = (minus == -1) ? 0 : -1;
			return ((int)result);
		}
		i++;
	}
	return ((int)result * minus);
}
