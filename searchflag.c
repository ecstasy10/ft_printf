/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 20:35:17 by marvin            #+#    #+#             */
/*   Updated: 2019/12/16 17:36:12 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab   *searchflag(t_tab *tab)
{
    size_t  i;

    while (tab->trat[tab->i] == '-' || tab->trat[tab->i] == '+' ||
     tab->trat[tab->i] == '0' || tab->trat[tab->i] == ' ' ||
     tab->trat[tab->i] == '.')
    {
        i = 0;
        while(tab->searchflag[i] != '\0')
        {
            if(tab->searchflag[i] == tab->trat[tab->i])
            {
                tab->flag_aux = tab->searchflag[i];
                selectflag(tab);
            }
            i++;
        }
        tab->i++;
    }
    return (tab);
}

t_tab  *selectflag(t_tab *tab)
{
    const char *flag;

    flag = &tab->flag_aux;
    if(strcmp(flag, "-") == 0)
        tab->flags[0] = 1;
    else if(strcmp(flag, "+") == 0)
        tab->flags[1] = 1;
    else if(strcmp(flag, "0") == 0)
        tab->flags[2] = 1;
    else if(strcmp(flag, " ") == 0)
        tab->flags[3] = 1;
    else if(strcmp(flag,".") == 0)
        tab->flags[4] = 1;
    return (tab);
}
