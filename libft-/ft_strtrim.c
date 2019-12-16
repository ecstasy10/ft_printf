/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:35:25 by dbalboa-          #+#    #+#             */
/*   Updated: 2019/11/16 12:54:54 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	char	*trimed;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]) != NULL)
		start++;
	len = ft_strlen(&s1[start]);
	if (len != 0)
		while (s1[start + len - 1]
		&& ft_strchr(set, s1[start + len - 1]) != NULL)
			len--;
	if ((trimed = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	trimed = ft_strncpy(trimed, &s1[start], len);
	trimed[len] = '\0';
	return (trimed);
}
