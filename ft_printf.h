/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 16:46:07 by acolas            #+#    #+#             */
/*   Updated: 2017/09/06 22:13:04 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft.h"

# define BUFSZ  10
# define ERROR -1
# define OK 1
# define END 0

typedef struct		s_type
{
	char	flags;
	int		width;
	int		precision;
	union	Data
	{
		short int				h;
		char					hh;
		long int				l;
		long long int			ll;
		intmax_t				j;
		size_t					z;
	}		data;
	char	type;

}					t_type;

int 	ft_printf(const char *format, ...);
void	ft_init_struc(t_type var);

#endif
