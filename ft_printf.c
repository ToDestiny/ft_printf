/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 14:42:44 by acolas            #+#    #+#             */
/*   Updated: 2017/08/22 17:22:10 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	va_list		ap2;
	char		*s;
	
	va_start(ap, format);
	va_copy(ap2, ap);
	while (*format)
	{
		if (*format == 's')
		{
			s = va_arg(ap, char *);
			if (ft_flag_s(s) != 0)
				return (ERROR);
		}
	}
	va_end(ap);
	va_end(ap2);
	return (END);
}

int		main(int ac, char ** av)
{
	if (av)
	{
		ac = 0;
		ft_putstr("test\n");
		ft_printf("s", "hello");
		ft_putchar('\n');
	}
	return (END);
}
