/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchprecision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:03:11 by marvin            #+#    #+#             */
/*   Updated: 2019/12/16 17:18:59 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab   *searchprecision(t_tab *tab)
{
    if (tab->trat[tab->i] == '.')
    {
        tab->i++;
        tab->precision = 0;
    }
    while (tab->trat[tab->i] >= 0 && tab->trat[tab->i] <= 9)
    {
        tab->precision *= 10;
        tab->precision += tab->trat[tab->i];
        tab->i++;
    }
    return (tab);
}
