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

#include "ft_printf.h"

int		ft_printf(const char *fm, ...)
{
	size_t	ret;
	va_list	args;

	ret = 0;
	va_start(args, fm);
	if (!*fm)
		return (END);
		ret = ft_check_fm(&args, fm, ret);
		va_ends(args);
		if (ret > INT_MAX)
			return (ERROR);
}