/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchident.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:11:56 by dbalboa-          #+#    #+#             */
/*   Updated: 2020/01/28 21:12:19 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab			*searchident(t_tab *tab)
{
	size_t		i;

	i = 0;
	while (tab->searchident[i] != '\0')
	{
		if (tab->searchident[i] == tab->trat[tab->i])
			tab->flag_ident = tab->searchident[i];
		i++;
	}
	return (tab);
}
