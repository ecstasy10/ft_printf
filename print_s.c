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

char	*ft_strndup(const char *s1, size_t n)
{
	char		*str_copy;
	size_t		i;

	str_copy = malloc(sizeof(*str_copy) * (n + 1));
	if (!str_copy)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		str_copy[i] = s1[i];
		i++;
	}
	str_copy[i] = '\0';
	return (str_copy);
}

t_tab   *print_s(t_tab *tab)
{
    char    *str;
    int     i;
    size_t  len;

    str = va_arg(tab->args, char *);
    i = 0;
    if (tab->precision > -1 && str)
        ft_strndup(str, tab->precision);
    else if (tab->precision == -1 && str)
        ft_strdup(str);
    else if (tab->precision > -1 && !str)
        ft_strndup('\0', tab->precision);
    else if (tab->precision == -1 && !str)
        ft_strdup('\0');
    len = ft_strlen(str);
    tab->len += len;
    if (tab->flags[2] == '0' && tab->flags[0] != '-')
        print_aux(tab, '0', tab->wide - len, 1);
    else if (tab->flags[0] != '-')
        print_aux(tab, ' ', tah->wide - len, 1);
    ft_putstr(str);
    if (tab-> flags[0] == '-')
        print_aux(tab, ' ', tab->wide - len, 1);
    free(str);
    return (tab);
}