/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 21:37:38 by dbalboa-          #+#    #+#             */
/*   Updated: 2019/11/06 18:40:09 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (needle == NULL || ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
