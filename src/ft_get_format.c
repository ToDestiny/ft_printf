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

const char      *ft_get_format(t_print *list, const char *fm)
{
    while(*fm && ft_strchr("-+ #0.123456789lhzj", *fm))
    {
        while (FLAG(*fm))
            ft_get_flag(list, *(fm++));
        if ((*fm) >= '1' && (*fm) <= '9')
        {
            list->width = 0;
            while (ft_isdigit(*fm))
                list->width = (list->width * 10) + (*fm++) - '0';
        }
        if (*fm == '.')
        {
            list->dot = 1;
            list->precision = 0;
            while (ft_isdigit((*(++fm))))
                list->precision = (list->precision * 10) + (*fm) - '0';
        }
        while (*fm && ft_strchr("lhzj", *fm))
            ft_get_size(list, *(fm++));
    }
    ft_check_size(list);
    ft_check_converse(list, &fm);
    return (fm);
}