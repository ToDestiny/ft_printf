/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 16:46:07 by acolas            #+#    #+#             */
/*   Updated: 2017/09/05 18:08:49 by acolas           ###   ########.fr       */
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
	char	specifier;
	char	flags;
	int		width;
	int		precision;
	char	length;

}					t_type;

union				Data
{
	char 			*s;
	short int		h;
	long int		l;
	double			d;
	long double		dl;
	float			f;
	long long int	ll;
	intmax_t		j;
	uintmax_t		k;
	size_t			z;
	ssize_t			x;
};

int ft_printf(const char *format, ...);
int	ft_printf_putstr(char *s);
int	ft_funf(const char *format);

#endif
