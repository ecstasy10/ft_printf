/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:44:38 by hbarrius          #+#    #+#             */
/*   Updated: 2020/01/09 19:08:57 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

static int			get_tens(int num)
{
	int tens;

	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

static t_tab		*logic_u(t_tab *tab, int num, int length, int flag)
{
	int			not_blank;

	not_blank = length;
	if (length <= tab->precision)
		not_blank = tab->precision;
	tab->len += (not_blank <= )
}

t_tab				*print_u(t_tab *tab)
{
	int		length;
	int		flag;
	int		num;

	flag = 0;
	num = (unsigned int)(va_arg(tab->args, unsigned int));
	if (num == 0 && tab->precision == 0)
	{
		display_gap(tab, ' ', tab->wide, 1);
		return (tab);
	}
	length = get_tens(num);
	if (tab->flags[0] == '-')
		flag = 1;
	if (tab->flags[2] == '0' && tab->precision == -1 && !tab->flags[0])
		tab->precision = tab->wide;
	logic_u(tab, num, length, flag);
	return (tab);
}