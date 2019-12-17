/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrius <hbarrius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:44:38 by hbarrius          #+#    #+#             */
/*   Updated: 2019/12/11 21:02:57 by hbarrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

static void	ft_putnbr(int num)
{
	int count;
	int pot;
	count = num;
	pot = 1;
  if (count < 0)
    count = count - 4294967295;
	while (count > 9)
	{
		count = (count / 10);
		pot = pot * 10;
	}
	while (pot >= 1)
	{
		if(num /pot < 0)
		{
		count = (num / pot) * -1 + '0';
		}
		else
		{
			count = (num / pot) + '0';
		}
			write(1, &count, 1);
			num = (num % pot);
			pot = (pot / 10);
	}
}

t_tab   *print_u(t_tab *tab)
{
    int num;
    
    if (tab->flag_ident == 'u')
        num = (unsigned int)(va_arg(tab->args, unsigned int));
    ft_putnbr(num);
    return (tab);
}