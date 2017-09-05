/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 14:42:44 by acolas            #+#    #+#             */
/*   Updated: 2017/08/23 18:51:08 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

va_list		*unknown_flag(va_list ap, char format)
{
	va_arg(ap, void*);
	ft_printf_putstr(format);
	return (0);
}

va_list		*ft_type_flag(va_list ap, char format)
{
	if ((format == 'i') || (format == 'd'))
		ft_putnbr(va_arg(ap, int));
	else if (format == 's')
		ft_putstr(va_arg(ap, char *));
	else if (format == 'c')
		ft_putchar(va_arg(ap, int));

}

va_list		*ft_flag(va_list ap, char format)
{
	if (format == '-' && ap < 0)
		ft_printf_putstr('-');
	else if (format == '+' && ap >= 0)
		ft_printf_putstr('+');
	else if (format == '#')
	{
		format++;
		if (format == 'o')
			ft_printf_putstr('0');
		if (format == 'x')
			ft_printf_putstr("0x");
		if (format == 'X')
			ft_printf_putstr("0X");
		format--;
	}
	else if (format == ' ' && ap > 0)
	ft_printf_putstr(' ');
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list			ap;
	static int		n;

	i = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '+' || *format == '-' || *format == ' ' || 
					format == '#')
			{
				ft_flag(ap, *format);
				format++;
			}
			if (*format >= '0' && *format <= '9')
				format++;
			ft_type_flag(ap, *format);
			format++;
			if (*format == '\0')
				return (0);
		}
		ft_printf_putstr(*format);
	format++;	
	}
	va_end(ap);
	return (END);
}

int		main(void)
{
	ft_printf("%s", "hello");
	ft_putchar('\n');
	return (END);
}
