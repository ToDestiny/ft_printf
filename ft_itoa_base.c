/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 16:20:27 by acolas            #+#    #+#             */
/*   Updated: 2017/09/13 17:45:35 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int		count_digit(int num, int base)
{
	int	i;

	i = 1;
	while (num > base - 1)
	{
		num = num / base;
		i++;
	}
	return (i);
}

char 	*ft_itoa_base(int num, int base)
{
	int 	i;
	int		j;
	int		neg;
	char	*str;

	i = 0;
	neg = 0;
	
	j = count_digit(num, base);
	if (!(str = (char *)malloc(sizeof((char * j) + 1))
				   return (END);

	if (num == '0')
	{
		str[i] = '0';
		str[i++] = '\0';
		return (str);
	}

		
	//negatif
	//
	//process
	//
	//negative -
	//
	//string terminator
	//
	//reverse
}
