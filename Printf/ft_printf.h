/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:57:28 by yeschall          #+#    #+#             */
/*   Updated: 2020/11/11 17:57:15 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# include <stdio.h>

typedef struct	s_struct
{
	int			flags;
	int			width;
	int			precision;
	int			type;
}				t_struct;
int				ft_printf(const char *str, ...);
t_struct		ft_parse(const char *str);

#endif
