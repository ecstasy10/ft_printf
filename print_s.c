/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 20:31:19 by dbalboa-          #+#    #+#             */
/*   Updated: 2019/12/13 20:31:50 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

t_tab   *print_s(t_tab *tab)
{
    char    *str;

    str = NULL;
    if (tab->flag_ident == 's')
        str = va_arg(tab->args, char *);
    ft_putstr(str);
    return (tab);
}
