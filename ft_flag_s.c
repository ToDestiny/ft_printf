/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 17:08:38 by acolas            #+#    #+#             */
/*   Updated: 2017/08/23 18:51:28 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_putstr(char *s)
{
	int			i;
	static int	n;

	i = 0;
	if (!s)
		return (ERROR);
	i =  ft_strlen(s);
	n = i + n;
	ft_putstr(s);
	return (OK);
}
