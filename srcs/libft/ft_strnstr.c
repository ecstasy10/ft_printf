/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:19:22 by dbalboa-          #+#    #+#             */
/*   Updated: 2019/11/08 18:19:31 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t e;

	i = 0;
	if (s2[0] == '\0' || s2 == NULL)
		return ((char*)s1);
	while (s1[i] != '\0' && i < n)
	{
		e = 0;
		if (s1[i] == s2[e])
		{
			while (s1[i + e] == s2[e])
			{
				if (!s2[e + 1] && (i + e) < n)
					return ((char*)s1 + i);
				e++;
			}
		}
		i++;
	}
	return (NULL);
}
