/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 19:24:08 by acolas            #+#    #+#             */
/*   Updated: 2017/09/12 18:26:09 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_type		var;

	va_start(ap, format);
 	if (!format)
	{
		ft_putstr("No format input");
		return (END);
	}
	ft_init_struc(&var);
	while (*format)
	{
		if (*format == '%')
		{
			ft_putchar('%');
			ft_putchar('\n');
			ft_parse_flags(&var, format);
		//	ft_parse_width(format);
		//	ft_parse_precision(format);
		//	ft_parse_type(format);
		}
		format++;
	}
	//ft_putstr(&format[0]);
	printf("sign == %d\nleft_justify == %d\nspace == %d\nhashtag == %d\npad == %d\n", var.sign, var.left_justify, var.space, var.hashtag, var.pad);
	va_end(ap);
	return (END);
}


int			main(void)
{
	ft_printf("%-0\n");
	return (0);
}
