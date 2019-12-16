/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:17:08 by dbalboa-          #+#    #+#             */
/*   Updated: 2019/11/16 22:14:26 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_numoflines(char const *s1, char c)
{
	int lines;
	int comp;

	lines = 0;
	comp = 0;
	if (*s1 == '\0')
		return ('\0');
	while (*s1)
	{
		if (*s1 == c)
			comp = 0;
		else if (comp == 0)
		{
			comp = 1;
			lines++;
		}
		s1++;
	}
	return (lines);
}

static int		ft_numofchars(char const *s2, char c, int i)
{
	int lenght;

	lenght = 0;
	while (s2[i] != c && s2[i])
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char		**ft_array(char const *s, char **dst, char c, int l)
{
	int i;
	int y;
	int k;

	i = 0;
	y = 0;
	while (s[i] && y < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (!(dst[y] = (char *)malloc(sizeof(char) *
		ft_numofchars(s, c, i) + 1)))
			return (NULL);
		while (s[i] && s[i] != c)
			dst[y][k++] = s[i++];
		dst[y][k] = '\0';
		y++;
	}
	dst[y] = 0;
	return (dst);
}

char			**ft_split(char const *s, char c)
{
	char	**dst;
	int		n;

	if (s == NULL)
		return (NULL);
	n = ft_numoflines(s, c);
	if (!(dst = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	return (ft_array(s, dst, c, n));
}
