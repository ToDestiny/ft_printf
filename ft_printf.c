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
		if (*format == '%' && *(format + 1) != '%')
		{
			ft_parse_flags(&var, &format);
			printf("sign == %d\nleft_justify == %d\nspace == %d\nhashtag == %d\npad == %d\n", var.sign, var.left_justify, var.space, var.hashtag, var.pad);
			// width
			// precision
			// write %s etc
			ft_init_struc(&var);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			format++;
		}
	}
	va_end(ap);
	return (END);
}


int			main(void)
{
	ft_printf("@@@@@%-0@@@@@%s@@@@@%d@@@@@%c\n");
	printf("%-10.10s", "test");
	return (0);
}
