/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchprecision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:12:25 by dbalboa-          #+#    #+#             */
/*   Updated: 2020/01/28 21:12:45 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab		*searchprecision(t_tab *tab)
{
	if (tab->trat[tab->i] == '.')
	{
		tab->i++;
		tab->precision = 0;
	}
	if (tab->trat[tab->i] == '*')
	{
		tab->precision = (int)(va_arg(tab->args, int));
		if (tab->precision < 0)
			tab->precision = -1;
		tab->i++;
	}
	while (tab->trat[tab->i] >= '0' && tab->trat[tab->i] <= '9')
	{
		tab->precision *= 10;
		tab->precision += (tab->trat[tab->i] - 48);
		tab->i++;
	}
	return (tab);
}
