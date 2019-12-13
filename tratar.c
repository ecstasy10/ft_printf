
#include "ft_printf.h"

int   tratar(t_tab *tab)
{
    tab->i++;
    searchident(tab);
    select_print(tab);
    return(tab->len);
}
