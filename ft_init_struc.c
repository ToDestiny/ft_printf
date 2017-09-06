/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 21:12:15 by acolas            #+#    #+#             */
/*   Updated: 2017/09/06 22:13:13 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_init_struc(t_type var)
{
	var.flags = NULL;
	var.width = NULL;
	var.precision = NULL;
	var.type = NULL;
	return;
}
