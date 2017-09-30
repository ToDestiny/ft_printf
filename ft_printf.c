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

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;

	len = 0;
	va_start(ap, format);
 	if (!format)
	{
		ft_putstr("No format input");
		return (END);
	}
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '%')
		{
			format++;
			if (*format == '%')
				count += ft_putchar_fd(*format, 1);
			else
				count += ft_putchar_fd(*format, 1);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			len++;
		}
		format++;
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
