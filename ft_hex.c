/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 19:24:08 by acolas            #+#    #+#             */
/*   Updated: 2017/09/13 17:45:25 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_hex_count(unsigned int n)
{
    if (n >= 16)
        return (ft_hex_count(n / 16) + ft_hex_count(n % 16));
    else
        return (ft_char(HEX[n]));
}

int     ft_hex(const char *format, int i, va_list ap)
{
    if (format[i] == 'x')
        return (ft_hex_count(va_arg(ap, unsigned int)));
    if (format[i] == 'X')
        return (ft_hexm(va_arg(ap, unsigned int)));
    if (format[i] == 'p')
        return (ft_ptr(va_arg(ap, void *)));
    return (OK);
}

int     ft_hexl_count(unsigned long n)
{
    if (n >= 16)
        return (ft_hexl_count(n / 16) + ft_hexl_count(n % 16));
    else
        return (ft_char(HEX[n]));
}

int     ft_ptr(void *n)
{
    int i;

    if (n = NULL)
        return (i = ft_str("0x0"));
    i = ft_str("0x");
    return (ft_hexl_count((unsigned long)n) + i);
}