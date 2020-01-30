/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:10:59 by dbalboa-          #+#    #+#             */
/*   Updated: 2020/01/30 20:10:52 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		hashtag(int num, char hash, char x)
{
	if (num)
	{
		if (hash == '#' && x == 'x')
			write(1, "0x", 2);
		if (hash == '#' && x == 'X')
			write(1, "0X", 2);
	}
}

static int		aux(t_tab *tab, int num, char *str, int num_w)
{
	if ((num_w = ft_strlen(str)) && tab->flags[4] == '#' && num &&
	tab->flags[2] == '0' && tab->wide)
		num_w += 2;
	else if ((num_w = ft_strlen(str)) && tab->flags[4] == '#' && num)
	{
		tab->wide -= 2;
		tab->len += 2;
	}
	return (num_w);
}

static t_tab	*logic_x(t_tab *tab, unsigned int num, char *str, int align)
{
	int num_b;
	int num_w;

	num_w = 0;
	num_w = aux(tab, num, str, num_w);
	num_b = (num_w <= tab->precision && tab->precision > 0)
	? tab->precision : num_w;
	tab->len += (num_b <= tab->wide) ? tab->wide : num_b;
	if (!align && tab->precision != -1)
		print_aux(tab, ' ', tab->wide - num_b, 0);
	else if (tab->flags[2] != '0' && !align)
		print_aux(tab, ' ', tab->wide - num_b, 0);
	hashtag(num, tab->flags[4], tab->flag_ident);
	if (tab->flags[2] == '0' && tab->precision < 0)
		print_aux(tab, '0', tab->wide - num_b, 0);
	else
		print_aux(tab, '0', tab->precision - num_w, 0);
	ft_putstr_fd(str, 1);
	if (align)
		print_aux(tab, ' ', tab->wide - num_b, 0);
	return (tab);
}

t_tab			*print_x(t_tab *tab)
{
	char			*str;
	char			c;
	unsigned int	num;
	int				align;

	align = 0;
	num = (unsigned int)(va_arg(tab->args, unsigned int));
	if (num == 0 && tab->precision == 0)
	{
		print_aux(tab, ' ', tab->wide, 1);
		return (tab);
	}
	c = 'a';
	if (tab->flag_ident == 'X')
		c = 'A';
	if (!(str = ft_itoa_base(num, 16, c)))
		exit(-1);
	if (tab->flags[0] == '-')
		align = 1;
	if (tab->flags[2] == '0' && tab->precision == -1 && !tab->flags[0])
		tab->precision = tab->wide;
	logic_x(tab, num, str, align);
	free(str);
	return (tab);
}
