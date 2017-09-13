/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 21:12:15 by acolas            #+#    #+#             */
/*   Updated: 2017/09/13 15:53:13 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_init_struc(t_type *var)
{
	var->sign = 0;
	var->left_justify = 0;
	var->space = 0;
	var->hashtag = 0;
	var->pad = 0;

	var->width = 0;
	var->precision = 0;
	return;
}
