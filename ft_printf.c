/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrius <hbarrius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:58:33 by hbarrius          #+#    #+#             */
/*   Updated: 2019/12/19 19:44:55 by hbarrius         ###   ########.fr       */
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
    tab->len = tab->i;
    return(tab->len);
}

int     ft_printf(const char *format,...)
{
    t_tab *tab;

    if(!(tab = (t_tab*)malloc(sizeof(t_tab))))
        return (-1);
    tab->format = format;
    iniciar(tab);
    if (format)
    {
        va_start(tab->args,format);
        tab->len = escribir(tab);
        va_end(tab->args);
    }
    printf("\nwide: %d \n", tab->wide);
    printf("\npre: %d \n",tab->precision);
    free(tab);
    return(tab->len);
}


int main(void)
{
    printf("####################################\n");
    printf("d:%8dk\n", 2);
    ft_printf("D:%8dk\n\n", 2);

printf("####################################\n");
    printf("d:%8.4dk\n", 2);
    ft_printf("D:%8.4dk\n\n", 2);

printf("####################################\n");
    printf("d:%8.dk\n", 2);
    ft_printf("D:%8.dk\n\n", 2);

printf("####################################\n");
    printf("d:%08.4dk\n", 2);
    ft_printf("D:%08.4dk\n\n", 2);

    printf("####################################\n");
    printf("d:%08dk\n", 2);
    ft_printf("D:%08dk\n\n", 2);

    printf("####################################\n");
    printf("d:%08.dk\n", 2);
    ft_printf("D:%08.dk\n\n", 2);

    return (0);
}
