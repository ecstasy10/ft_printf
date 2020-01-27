/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrius <hbarrius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:23:09 by hbarrius          #+#    #+#             */
/*   Updated: 2020/01/21 20:42:37 by hbarrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab   *select_print(t_tab *tab)
{
    char    ident;

    ident = tab->flag_ident;
    if (ident == 'd' || ident == 'i')
        print_d(tab);
    else if (ident == 's')
        print_s(tab);
    else if (ident == 'c')
        print_c(tab);
    else if (ident == 'x' || ident == 'X')
        print_x(tab);
    else if (ident == 'u')
        print_u(tab);
    else if (ident == 'p')
        print_p(tab);
    else if (ident == '%')
    {
        print_aux(tab, '%', 1, 0);
        tab->len++;
    }
    return (tab);
}
