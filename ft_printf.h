/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 16:46:07 by acolas            #+#    #+#             */
/*   Updated: 2017/09/12 18:26:18 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "./libft/libft.h"

# define BUFSZ  10
# define ERROR -1
# define OK 1
# define END 0

typedef struct		s_type
{
	int		sign;
	int		left_justify;
	int		space;
	int		hashtag;
	int		pad;

	int		width;

	union	Data
	{
		short int				h;
		char					hh;
		long int				l;
		long long int			ll;
		intmax_t				j;
		size_t					z;
	}		data;
}					t_type;

int 	ft_printf(const char *format, ...);
void	ft_init_struc(t_type *var);
int		ft_parse_flags(t_type *var, const char *format);

#endif
