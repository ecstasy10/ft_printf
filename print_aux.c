/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:55:09 by dbalboa-          #+#    #+#             */
/*   Updated: 2019/12/17 19:38:26 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft-/libft.h"

void	print_aux(t_tab *tab, char c, int len, int update_len)
{
	char	*str;

	if (len > 0)
	{
		if (update_len)
			tab->len += len;
		if (!(str = ft_strnew(len)))
			exit(-1);
		ft_memset(str, c, len);
		write(1, str, len);
		free(str);
	}
}
