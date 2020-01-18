/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 20:39:43 by dbalboa-          #+#    #+#             */
/*   Updated: 2019/12/13 20:53:20 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    logic_c(int c, t_tab *tab)
{
    if (c <= 127)
	{
		tab->len += 1;
	}
	if (c > 127 && c <= 2047)
	{
		tab->len += 2;
	}
	if (c >= 2048 && c <= 65535)
	{
		tab->len += 3;
	}
	if (c >= 65536 && c <= 2097151)
	{
		tab->len += 4;
	}
}

t_tab   *print_c(t_tab *tab)
{
    int     c;

    c = (char) va_arg(tab->args, int);
    c = (int) c;
    if (tab->flags[3] == '0' && tab->flags[0] != '-')
        print_aux(tab, '0', tab->wide - 1, 1);
    else if (tab->flags[0] != '-')
        print_aux(tab, ' ', tab->wide - 1, 1);
    write(1, &c, 1);
    logic_c(c, tab);
    if (tab->flags[0] == '-')
        print_aux(tab, ' ', tab->wide - 1, 1);
    return (tab);
}
