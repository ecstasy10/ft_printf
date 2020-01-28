/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:13:13 by dbalboa-          #+#    #+#             */
/*   Updated: 2020/01/28 23:07:49 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab		*select_print(t_tab *tab)
{
	char	ident;

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
		tab->flag_ident = '%';
		print_c(tab);
	}
	return (tab);
}
