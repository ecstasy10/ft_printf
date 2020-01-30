/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:39:58 by dbalboa-          #+#    #+#             */
/*   Updated: 2020/01/30 20:13:38 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

static int		get_tens(long int num)
{
	int		tens;

	if (num < 0)
		num *= -1;
	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

static char		get_sign(t_tab *tab, int is_neg)
{
	char	*tmp;

	tmp = tab->flags;
	if (is_neg)
		return ('-');
	if (tmp[1] == '+')
		return ('+');
	if (tmp[3] == ' ')
		return (' ');
	return ('\0');
}

static void		ft_putnbrintmax_fd(long int nb, int fd)
{
	long int	nbr;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = (long int)(nb * -1);
	}
	else
		nbr = (long int)nb;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((char)(nbr % 10 + 48), fd);
}

static t_tab	*logic_d(t_tab *tab, long int num, int num_len, int align_left)
{
	int		not_blank;
	char	sign;
	int		is_negative;

	is_negative = (num < 0) ? 1 : 0;
	not_blank = num_len;
	num *= (is_negative) ? -1 : 1;
	sign = get_sign(tab, is_negative);
	if (num_len <= tab->precision && tab->precision >= 0)
		not_blank = tab->precision;
	if (sign)
		not_blank++;
	tab->len += (not_blank <= tab->wide) ? tab->wide : not_blank;
	if (!align_left && (tab->flags[2] != '0' || tab->precision >= 0))
		print_aux(tab, ' ', tab->wide - not_blank, 0);
	if (sign)
		write(1, &sign, 1);
	if (tab->flags[2] == '0' && tab->precision < 0 && tab->flags[0] != '-')
		print_aux(tab, '0', tab->wide - not_blank, 0);
	print_aux(tab, '0', tab->precision - num_len, 0);
	ft_putnbrintmax_fd(num, 1);
	if (align_left)
		print_aux(tab, ' ', tab->wide - not_blank, 0);
	return (tab);
}

t_tab			*print_d(t_tab *tab)
{
	int			num;
	long int	num_len;
	int			align_left;

	num = (long int)(va_arg(tab->args, int));
	if (num == 0 && tab->precision == 0)
	{
		if (tab->flags[1] == '+')
			write(1, "+", 1);
		if (tab->flags[3] == ' ')
			write(1, " ", 1);
		print_aux(tab, ' ', tab->wide, 1);
		return (tab);
	}
	num_len = get_tens(num);
	(num > INT32_MAX) ? num_len++ : num_len;
	align_left = (tab->flags[0] == '-') ? 1 : 0;
	logic_d(tab, num, num_len, align_left);
	return (tab);
}
