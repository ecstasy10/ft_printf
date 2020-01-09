/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:52:37 by dbalboa-          #+#    #+#             */
/*   Updated: 2019/11/11 18:51:01 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*result;
	size_t	i;

	i = 0;
	result = malloc(size * nitems);
	if (result == NULL)
		return (NULL);
	result = ft_memset(result, '\0', (size * nitems));
	return (result);
}
