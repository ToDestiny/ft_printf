/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 16:46:07 by acolas            #+#    #+#             */
/*   Updated: 2017/09/13 15:52:26 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "./libft/libft.h"

# define HEX "0123456789abcdef"
# define ERROR -1
# define OK 1
# define END 0

int 	ft_printf(const char *format, ...);
int     ft_hex(const char *format, int i, va_list ap);
int     ft_char(char c);
int     ft_count_int(int n);

#endif
