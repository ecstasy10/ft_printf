/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:21:32 by dbalboa-          #+#    #+#             */
/*   Updated: 2020/01/30 19:45:52 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	int ret1, ret2;
	ret1 = printf("   printf:%.s", 42);
	printf("\n");
	ret2 = ft_printf("ft_printf:%.s", 42);

	//return
	printf("\n\n    printf return:%d\n", ret1);
	ft_printf(" ft_printf return:%d", ret2);
}
