/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:28:39 by dbalboa-          #+#    #+#             */
/*   Updated: 2019/11/09 14:42:53 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		c;
	size_t		size1;
	char		*str;

	c = -1;
	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	if (!(str = (char *)malloc((size1 + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	while (s1[++c])
		str[c] = s1[c];
	c = -1;
	while (s2[++c])
		str[c + size1] = s2[c];
	str[size1 + c] = '\0';
	return (str);
}
