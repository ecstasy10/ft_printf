
#include "ft_printf.h"

t_tab   *searchident(t_tab *tab)
{
    size_t  i;

    i = 0;
    while (tab->searchident[i] != '\0')
    {
        //printf("\n%c\n", tab->flag_ident);
        if(tab->searchident[i] == tab->trat[tab->i])
            tab->flag_ident = tab->searchident[i];
        i++;
    }
    //printf("\n%d", tab->i);
    return (tab);
}
