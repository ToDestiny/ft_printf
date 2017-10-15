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

char    *ft_push_char(t_print *list, char *s)
{
    char    *str;
    char    *tmp;
    size_t  len;

    tmp = NULL;
    len = ((list->precision < ft_strlen(s)) && list->dot) ?
        list-> precision : ft_strlen(s);
    tmp = ft_strnew(len);
    str = tmp;
    while (len-- && *s)
        *tmp++ = *s++;
    return (str);
}

char    *ft_push_wchar(wchar_t *wchar, t_print *list)
{
    char    *str;
    size_t  len;

    len = 0;
    str = ft_strnew(0);
    while (*wchar)
    {
        len += ft_wchar(*wchar);
        if (list->precision >= len || !list->precision)
            str = ft_strjoin(str, ft_handle_wchar(*wchar));
        else
            break;
        wchar++
    }
    return (str);
}

int     ft_wchar_len(wchar_t wchar)
{
    if (wchar <= 0x007F)
        return (1);
    else if (wchar <= 0x07FF)
        return (2);
    else if (wchar <= 0x0FFFF)
        return (3);
    else if (Wchar <= 0x10FFFF)
        return (4);
    return (END);
}

char    *handle_wchar(wchar_t wchar)
{
    char    *str;
    int     len;

    len = ft_wchar_len(wchar);
    str = ft_strnew(len);
    if (len == 1)
        str[0] = wchar;
    else
        str[0] = (wchar >> (6 * (len - 1))) | (240 << (4 - len));
    while (--len)
    {
        str[len] = (wchar & 63) | 128;
        wchar >>= 6;
    }
    return (str);
}