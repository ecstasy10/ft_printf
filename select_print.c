
#include "ft_printf.h"
#include <string.h>

t_tab   *select_print(t_tab *tab)
{
    char    flag;

    flag = tab->flag_ident;
    if (flag == 'd')
        print_d(tab);
    else if (flag == 's')
        print_s(tab);
    else if (flag == 'c')
        print_c(tab);
    return (tab);
}
