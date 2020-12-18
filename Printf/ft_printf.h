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

# define SUBJ_TYPES "cspdiuxX"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# include <stdio.h>

typedef struct	s_part
{
	ssize_t		size;
	int			on;
	const char	*began;
	char		val;
}				t_part;

typedef struct	s_obj
{
	struct		s_part s_flag;
	struct		s_part s_width;
	struct		s_part s_precision;
	struct		s_part s_type;
}				t_obj;
int				ft_printf(const char *str, ...);
t_obj			ft_parse(const char *str);

#endif