/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:41:46 by dbalboa-          #+#    #+#             */
/*   Updated: 2020/01/28 20:42:13 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_tab		*logic_p(t_tab *tab, char *str, int left)
{
	int		not_blank;
	int		length;

	length = ft_strlen(str) + 2;
	not_blank = length;
	tab->len += (not_blank <= tab->wide) ? tab->wide : not_blank;
	if (!left)
		print_aux(tab, ' ', tab->wide - not_blank, 0);
	write(1, "0x", 2);
	print_aux(tab, '0', (tab->precision - length) + 2, 1);
	ft_putstr_fd(str, 1);
	if (left)
		print_aux(tab, ' ', tab->wide - not_blank, 0);
	free(str);
	return (tab);
}

t_tab				*print_p(t_tab *tab)
{
	char		*str;
	long int	num;
	int			left;

	left = 0;
	num = (unsigned long int)(va_arg(tab->args, unsigned long int));
	if (!(str = ft_itoa_base(num, 16, 'a')))
		exit(-1);
	if (tab->flags[0] == '-')
		left = 1;
	if (tab->precision == 0 && num == 0)
		*str = '\0';
	if (tab->flags[2] == '0' && tab->precision == -1 && !tab->flags[0])
	{
		tab->precision = tab->wide - 2;
		tab->wide = 0;
	}
	logic_p(tab, str, left);
	return (tab);
}
