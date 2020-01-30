/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:44:38 by hbarrius          #+#    #+#             */
/*   Updated: 2020/01/30 20:09:52 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

static int			get_tens(unsigned int num)
{
	unsigned int tens;

	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

void				ft_putuns_fd(unsigned int nb, int fd)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = (unsigned int)(nb * -1);
	}
	else
		nbr = (unsigned int)nb;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((char)(nbr % 10 + 48), fd);
}

static t_tab		*logic_u(t_tab *tab, unsigned int num, int length, int flag)
{
	int			not_blank;

	not_blank = length;
	if (length <= tab->precision)
		not_blank = tab->precision;
	tab->len += (not_blank <= tab->wide) ? tab->wide : not_blank;
	if (!flag && (tab->flags[2] != '0' || tab->precision >= 0))
		print_aux(tab, ' ', tab->wide - not_blank, 0);
	if (tab->flags[2] == '0' && tab->precision < 0)
		print_aux(tab, '0', tab->wide - not_blank, 0);
	print_aux(tab, '0', tab->precision - length, 0);
	ft_putuns_fd(num, 1);
	if (flag)
		print_aux(tab, ' ', tab->wide - not_blank, 0);
	return (tab);
}

t_tab				*print_u(t_tab *tab)
{
	int				length;
	int				flag;
	unsigned int	num;

	flag = 0;
	num = (unsigned int)(va_arg(tab->args, unsigned int));
	if (num == 0 && tab->precision == 0)
	{
		print_aux(tab, ' ', tab->wide, 1);
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
