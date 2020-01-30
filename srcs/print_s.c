/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:42:26 by dbalboa-          #+#    #+#             */
/*   Updated: 2020/01/30 20:08:45 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (!(s2 = ft_strnew(n)))
		return (NULL);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

t_tab		*print_s(t_tab *tab)
{
	char	*str;
	int		i;
	size_t	len;

	str = (char *)va_arg(tab->args, char *);
	i = 0;
	if (tab->precision > -1 && str)
		str = ft_strndup(str, tab->precision);
	else if (tab->precision == -1 && str)
		str = ft_strdup(str);
	else if (tab->precision > -1 && !str)
		str = ft_strndup("(null)", tab->precision);
	else if (tab->precision == -1 && !str)
		str = ft_strdup("(null)");
	len = ft_strlen(str);
	tab->len += len;
	if (tab->flags[2] == '0' && tab->flags[0] != '-')
		print_aux(tab, '0', tab->wide - len, 1);
	else if (tab->flags[0] != '-')
		print_aux(tab, ' ', tab->wide - len, 1);
	ft_putstr_fd(str, 1);
	if (tab->flags[0] == '-')
		print_aux(tab, ' ', tab->wide - len, 1);
	free(str);
	return (tab);
}
