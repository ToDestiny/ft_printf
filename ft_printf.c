/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 14:42:44 by acolas            #+#    #+#             */
/*   Updated: 2017/09/05 18:08:32 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

va_list		*unknown_flag(va_list ap, char *format)
{
	va_arg(ap, void*);
	ft_putstr(format);
	return (END);
}

va_list		*ft_type_flag(va_list ap, char format)
{
	if ((format == 'i') || (format == 'd'))
		ft_putnbr(va_arg(ap, int));
	else if (format == 's')
		ft_putstr(va_arg(ap, char *));
	else if (format == 'c')
		ft_putchar(va_arg(ap, int));
	return (END);
}

va_list		*ft_flag(va_list ap, char format)
{
	static int		n;
	
	if (format == '-' && ap < 0)
		ft_putchar('-');
	else if (format == '+' && ap >= 0)
		ft_putchar('+');
	else if (format == '#')
	{
		format++;
		if (format == 'o')
			ft_putchar('0');
		if (format == 'x')
			ft_putstr("0x");
		if (format == 'X')
			ft_putstr("0X");
		format--;
	}
	else if (format == ' ' && ap > 0)
		ft_putchar(' ');
	return (END);
}

int			ft_printf(const char *format, ...)
{
	va_list			ap;
	static int		i;
	
	i = ft_strlen(format);;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '+' || *format == '-' || *format == ' ' || 
					*format == '#')
			{
				ft_flag(ap, *format);
				format++;
			}
			while (*format >= '0' && *format <= '9')
			{
				
			}	
			ft_type_flag(ap, *format);
			format++;
			if (*format == '\0')
				return (END);
		}
		ft_putchar(*format);
	format++;	
	}
	va_end(ap);
	return (END);
}

int		main(void)
{
	ft_printf("%4d : %s \n", 123456, "Hello World");
	ft_putchar('\n');
	return (END);
}
