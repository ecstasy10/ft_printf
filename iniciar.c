
#include "ft_printf.h"
#include <string.h>

t_tab   *iniciar(t_tab *tab)
{
    tab->len = 0;
    tab->i = 0;
    tab->cpy = (char*)tab->format;
    tab->trat = (char*)tab->format;
    tab->searchident = "dsxc%";
    return (tab);
}
