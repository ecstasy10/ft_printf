/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:02:24 by dbalboa-          #+#    #+#             */
/*   Updated: 2019/11/14 21:08:20 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_nb_len(unsigned int nb)
{
	unsigned int	len;

	len = 0;
	while (nb >= 10)
	{
		nb /= 10;
		++len;
	}
	return (len + 1);
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	unsigned int	i;
	unsigned int	len;

	if (n < 0)
		nb = (unsigned int)(n * -1);
	else
		nb = (unsigned int)n;
	len = (unsigned int)get_nb_len(nb);
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	if (n < 0 && (str[i] = '-'))
		len++;
	i = len - 1;
	while (nb >= 10)
	{
		str[i--] = (char)(nb % 10 + 48);
		nb /= 10;
	}
	str[i] = (char)(nb % 10 + 48);
	str[len] = '\0';
	return (str);
}
