/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 15:56:38 by acolas            #+#    #+#             */
/*   Updated: 2017/09/13 15:52:28 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_flags(t_type *var, const char **format)
{
	(*format)++;
	while (**format == '+' || **format == '-' || **format == ' ' ||
			**format == '#' || **format == '0')
	{
		if (**format == '+')
			var->sign = 1;
		else if (**format == '-')
			var->left_justify = 1;
		else if (**format == ' ')
			var->space = 1;	
		else if (**format == '#')
			var->hashtag = 1;
		else if (**format == '0')
			var->pad = 1;		
		(*format)++;
	}
	return (OK);
}
