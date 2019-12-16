/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tratar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrius <hbarrius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:20:31 by hbarrius          #+#    #+#             */
/*   Updated: 2019/12/11 18:50:32 by hbarrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int   tratar(t_tab *tab)
{
    tab->i++;
    searchflag(tab);
    searchwide(tab);
    searchprecision(tab);
    searchident(tab);
    select_print(tab);
    return(tab->len);
}