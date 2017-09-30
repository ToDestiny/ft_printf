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

#include <stdio.h>
#include "ft_printf.h"

int			ft_parse(const char *format, int i, va_list ap)
{
	if (format[i] == 's')
		return (ft_str(va_arg(ap, char *)));
	else if (format[i] == 'd'|| format[i] == 'i')
		return (ft_nbr(va_arg(ap, int)));
	else if (format[i] == 'c')
		return (ft_char(va_arg(ap, int)));
	else if (format[i] == 'u')
		return(ft_unbr(va_arg(ap, unsigned int)));
	else if (format[i] == 'Z')
		return (ft_char('Z'));
	else if (format[i] == 'o')
		return (ft_octal(va_arg(ap, int)));
	else if (format[i] == 'x'|| format[i] == 'X'|| format[i] == 'p')
		return (ft_hex(format, i, ap));
	else if (format[i] == 'l')
		return (ft_long(format, i, ap));
	else if (format[i] == 'f')
		return (ft_nbr_lf(va_arg(ap, double)));
	else if (format[i] == ' ')
		return (END);
	else
		return (ft_char(format[i]));
	return (END);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;
	int			i;

	len = 0;
	i = 0;
	va_start(ap, format);
 	if (!format)
	{
		ft_putstr("No format input");
		return (END);
	}
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				count += ft_putchar_fd(format[i], 1);
			else
				count += ft_parse(format, i, ap);
		}
		else if (format[i] != '%')
		{
			ft_putchar_fd(*format, 1);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}


int			main(void)
{
	ft_printf("@@@@@%-0@@@@@%s@@@@@%d@@@@@%c\n");
	printf("%-10.10s", "test");
	return (0);
}
