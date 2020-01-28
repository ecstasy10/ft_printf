/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:11:31 by dbalboa-          #+#    #+#             */
/*   Updated: 2020/01/28 21:11:36 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab		*searchflag(t_tab *tab)
{
	size_t	i;

	i = 0;
	while (tab->searchflag[i] != '\0')
	{
		while (tab->searchflag[i] == tab->trat[tab->i])
		{
			while (tab->trat[tab->i] == '-' && tab->i++)
				tab->flags[0] = '-';
			while (tab->trat[tab->i] == '+' && tab->i++)
				tab->flags[1] = '+';
			while (tab->trat[tab->i] == ' ' && tab->i++)
				tab->flags[3] = ' ';
			while (tab->trat[tab->i] == '0' && tab->i++)
				tab->flags[2] = '0';
			while (tab->trat[tab->i] == '#' && tab->i++)
				tab->flags[4] = '#';
			i = 0;
		}
		i++;
	}
	return (tab);
}
