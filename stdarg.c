/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdarg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:24:21 by acolas            #+#    #+#             */
/*   Updated: 2017/08/22 17:03:03 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	foo(char *fmt, ...)
{
	va_list		ap;
	va_list		ap2;
	int			d;
	char		c;
	char		*s;

	va_start(ap, fmt);
	va_copy(ap2, ap);
	while (*fmt)
	{
		if(*fmt == 's')
		{
			s = va_arg(ap, char *);
			printf("string %s\n", s);
		}
		else if (*fmt == 'd')
		{
			d = va_arg(ap, int);
			printf("int %d\n", d);
		}
		else if	(*fmt == 'c')
		{
			c = va_arg(ap, int);
			printf("char %c\n", c);
		}
		fmt++;
	}
	va_end(ap);
	va_end(ap2);
}

int		main(void)
{
	foo("sdc", "hello", 42, 'c');
	return (0);
}
