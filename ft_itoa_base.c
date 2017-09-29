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

static int		ft_count_char_len(int num, int base)
{
	int	len;

	len = 1;
	if (num < 0)
		num = -num;
	while (num >= base)
	{
		num = num / base;
		len++;
	}
	return (len);
}

char 	*ft_itoa_base(int num, int base)
{
	int 	i;
	char	*dest;
	char	*tab;

	i = 0;
	tab = NULL;
	dest = NULL;
	
	if (base == 10)
		return (ft_itoa(num));
	if (base < 2 && base > 16)
		return (NULL);
	if (num < 0)
		return (NULL);
	if ((tab = (char *)malloc(sizeof(char) * 17)))
		ft_strcpy(tab, "0123456789ABCDEF");
	i = ft_count_char_len(num, base);
	if (!(dest = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	dest [i + 1] = '\0';
	while (i >= 0)
	{
		dest[i--] = tab[num % base];
		num = num / base;
	}
	free (tab);
	return (dest);
}