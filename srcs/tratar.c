/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tratar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:13:31 by dbalboa-          #+#    #+#             */
/*   Updated: 2020/01/28 21:13:44 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		tratar(t_tab *tab)
{
	tab->i++;
	searchflag(tab);
	searchwide(tab);
	searchprecision(tab);
	searchident(tab);
	select_print(tab);
	return (tab->len);
}
