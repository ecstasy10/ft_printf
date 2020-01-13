/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:15:35 by hbarrius          #+#    #+#             */
/*   Updated: 2020/01/13 21:09:15 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void hashtag (int num, char hash, char x)
{
    if (num)
    {
        if (hash == '#' && x == 'x')
            write (1, "0x", 2);
        if (hash == '#' && x == 'X')
            write (1, "0X", 2);
    }
}

static t_tab    *logic_x(t_tab *tab, int num, char *str, int align)
{
    int num_b;
    int num_w;

    if ((num_w = ft_strlen(str)) && tab->flags[4] == '#' && num &&
     tab->flags[2] == '0' && tab->wide)
        num_w += 2;
    else if ((num_w = ft_strlen(str)) && tab->flags[4] == '#' && num)
    {
        tab->wide -= 2;
        tab->len += 2;
    }
    num_b = (num_w <= tab->precision && tab->precision > 0) ? tab->precision : num_w;
    tab->len += (num_b <= tab->wide) ? tab->wide : num_b;
    if(!align)
        print_aux(tab, ' ', tab->wide - num_b, 0);
    hashtag(num, tab->flags[4], tab->flag_ident);
    if (tab->flags[2] == '0' && tab->precision < 0)
        print_aux(tab, '0', tab->wide - num_b, 0);
    else
        print_aux(tab, '0', tab->precision - num_w, 0);
    ft_putstr_fd(str, 1);
    if(align)
        print_aux(tab, ' ', tab->wide - num_b, 0);
    return (tab);
}

/*void hex(unsigned int nbr)
{
    char *base = "0123456789abcdef";

    if (nbr >= 16)
        hex(nbr / 16);
    ft_putchar(base[nbr % 16]);
}*/

t_tab   *print_x(t_tab *tab)
{
    char    *str;
    char    c;
    int     num;
    int     align;

    align = 0;
    num = (int)(va_arg(tab->args, int));

    if (num == 0 && tab->precision == 0)
    {
        print_aux(tab, ' ', tab->wide, 1);
        return (tab);
    }
    c = 'A';
    if (tab->flag_ident == 'x')
        c = 'a';
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
