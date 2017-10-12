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

static int      ft_count(unsigned int n, int i)
{
    if (n >= 10)
        return (ft_count(n / 10, i + 1));
    else
        return (i + 1);
    return (END);
}

int             ft_count_int(int n)
{
    int             len;
    unsigned int    tmp;

    tmp = (n < 0) ? (n * -1) : n;
    len = ft_count(tmp, 0);
    len+= (n < 0) ? 1 : 0;
    return (len);
}