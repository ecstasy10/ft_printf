/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iniciar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:15:14 by dbalboa-          #+#    #+#             */
/*   Updated: 2020/01/30 16:02:56 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

t_tab	*iniciar(t_tab *tab)
{
	tab->len = 0;
	tab->i = 0;
	tab->precision = -1;
	tab->wide = 0;
	tab->cpy = (char*)tab->format;
	tab->trat = (char*)tab->format;
	tab->searchident = "dsciuxXp%";
	tab->searchflag = "0-+ ";
	tab->flag_ident = 'q';
	tab->flags[0] = 'a';
	tab->flags[1] = 'a';
	tab->flags[2] = 'a';
	tab->flags[3] = 'a';
	tab->flags[4] = 'a';
	return (tab);
}
