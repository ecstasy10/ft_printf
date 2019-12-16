/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:34:18 by dbalboa-          #+#    #+#             */
/*   Updated: 2019/11/11 17:35:27 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*dest;
	const char		*sourc;

	if (src == NULL && dst == NULL)
		return (NULL);
	dest = dst;
	sourc = src;
	i = 0;
	while (i < (unsigned char)n)
	{
		dest[i] = sourc[i];
		i++;
	}
	return (dst);
}
