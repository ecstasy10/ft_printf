/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:48:07 by dbalboa-          #+#    #+#             */
/*   Updated: 2019/11/08 20:33:20 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *last;

	last = 0;
	while (*str)
	{
		if (c == *str)
			last = (char *)str;
		str++;
	}
	if (last)
		return (last);
	if (c == '\0')
		return ((char*)str);
	return (0);
}
