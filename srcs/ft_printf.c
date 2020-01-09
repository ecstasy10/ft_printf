/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:58:33 by hbarrius          #+#    #+#             */
/*   Updated: 2020/01/09 20:50:41 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

int escribir(t_tab *tab)
{
    if(strcmp(tab->cpy, "%") == 0)
        return(0);
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
            tab->len++;
        }
        tab->i++;
    }
    return(tab->len);
}

int     ft_printf(const char *format, ...)
{
    t_tab *tab;

    if(!(tab = (t_tab*)malloc(sizeof(t_tab))))
        return (-1);
    tab->format = format;
    iniciar(tab);
    if (format)
    {
        va_start(tab->args, format);
        tab->len = escribir(tab);
        va_end(tab->args);
    }
    //printf("\nwide: %d \n", tab->wide);
    //printf("\npre: %d \n",tab->precision);
    free(tab);
    return(tab->len);
}

/*
 * Lo que llevamos hecho:
 *
 * %c = HECHO
 * %s = HECHO
 * %p =
 * %d = HECHO
 * %i = HECHO
 * %u = HECHO
 * %x =
 * %X =
 *
 */

/*
int main(void)
{
    printf("####################################\n");
    printf("hello, %s.\n", NULL);
    ft_printf("HELLO, %s.\n", NULL);

    return (0);
}
*/
