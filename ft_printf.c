/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 19:24:08 by acolas            #+#    #+#             */
/*   Updated: 2017/09/06 22:07:55 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_type		var;

	va_start(ap, format);
	ft_init_struc(var);
	if (!format)
		return (END);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			while (*format == '+' || *format == '-' || *format == '0' ||
					*format == ' ' || *format == '#')
			{
				var.flags = 1;
				format++;
			}
			while (*format >= '0' && *format <= '9')
			{
				var.width = 1;
				format++;
			}
			if (*format == '.')
			{
				var.precision = 1;
				format++;
			}
			if (*format == 'h' || *format == 'l' || *format == 'j' ||
					*format == 'z')
			{
				var.type = 1;
				format++;
			}
		}
	}
	//ft_print_stream(format[0]);
	printf("flags == %d\nwidth == %d\nprecision == %d\ntype == %d\n", var.flags, var.width, var.precision, var.type);
	va_end(ap);
	return (END);
}


int			main(void)
{
	ft_printf("%1.h");
	return (0);
}
