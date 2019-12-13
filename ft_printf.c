/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 20:04:02 by dbalboa-          #+#    #+#             */
/*   Updated: 2019/12/13 20:04:02 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

int		escribir(t_tab *tab)
{
	if (strcmp(tab->cpy, "%") == 0)
		return (0);
	while (tab->cpy[tab->i] != '\0')
	{
		if (tab->cpy[tab->i] == '%')
		{
			reiniciar(tab);
			tratar(tab);
		}
		else
		{
			write(1, &tab->cpy[tab->i], 1);
		}
		tab->i++;
	}
	tab->len = tab->i;
	return (tab->len);
}

int		ft_printf(const char *format,...)
{
	t_tab *tab;

	if (!(tab = (t_tab*)malloc(sizeof(t_tab))))
		return (-1);
	tab->format = format;
	iniciar(tab);
	if (format)
	{
		va_start(tab->args, format);
		tab->len = escribir(tab);
		va_end(tab->args);
	}
	free(tab);
	return (tab->len);
}

int		main(void)
{
	int a=10;
	int* ptr = &a;

	//printf("%p\n",ptr);
	//ft_printf("%d", 123);
	ft_printf("%d", *ptr);
	printf("%d", *ptr);
}
