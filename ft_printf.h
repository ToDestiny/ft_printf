/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 16:46:07 by acolas            #+#    #+#             */
/*   Updated: 2017/08/23 18:51:26 by acolas           ###   ########.fr       */
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

int ft_printf(const char *format, ...);
int	ft_printf_putstr(char *s);
int	ft_funf(const char *format);

#endif
