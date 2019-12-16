/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test-printf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aalleman <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 16:54:40 by aalleman     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/07 17:19:51 by aalleman    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <wchar.h>
#include <locale.h>

int		ft_printf(const char *s, ...);

int		main(int ac, char **av)
{
	int		nb;
	int		count;

	nb = atoi(av[1]);
	count = 0;


	// [A - Tests without options].
	if (nb == count++)
		return(ac == 2 ? printf("") : ft_printf(""));
	if (nb == count++)
		return(ac == 2 ? printf("1") : ft_printf("1"));
	if (nb == count++)
		return(ac == 2 ? printf("%%") : ft_printf("%%"));
	if (nb == count++)
		return(ac == 2 ? printf("%%%%") : ft_printf("%%%%"));
	if (nb == count++)
		return(ac == 2 ? printf("%%%%%%") : ft_printf("%%%%%%"));
	if (nb == count++)
		return(ac == 2 ? printf("%c", '1') : ft_printf("%c", '1'));
	if (nb == count++)
		return(ac == 2 ? printf("%c", -207) : ft_printf("%c", -207));
	if (nb == count++)
		return(ac == 2 ? printf("%c", 256 + 48) : ft_printf("%c", 256 + 48));
	if (nb == count++)
		return(ac == 2 ? printf("%c%%", '3') : ft_printf("%c%%", '3'));
	if (nb == count++)
		return(ac == 2 ? printf("0%c", 0) : ft_printf("0%c", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%c", -129) : ft_printf("%c", -129));
	if (nb == count++)
		return(ac == 2 ? printf("%c", 128) : ft_printf("%c", 128));
	if (nb == count++)
		return(ac == 2 ? printf("%c", 0) : ft_printf("%c", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%s", "Hello") : ft_printf("%s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%s%%", "Hello3") : ft_printf("%s%%", "Hello3"));
	if (nb == count++)
		return(ac == 2 ? printf("%s", "") : ft_printf("%s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%s", "1") : ft_printf("%s", "1"));
	if (nb == count++)
		return(ac == 2 ? printf("%i", 0) : ft_printf("%i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%i", -1) : ft_printf("%i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%i", -42) : ft_printf("%i", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%i", 1) : ft_printf("%i", 1));
	if (nb == count++)
		return(ac == 2 ? printf("%i", 42) : ft_printf("%i", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%i", INT_MAX) : ft_printf("%i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%i", INT_MAX + 1) : ft_printf("%i", INT_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%i", INT_MIN) : ft_printf("%i", INT_MIN));
	if (nb == count++)
		return(ac == 2 ? printf("%i", 1000) : ft_printf("%i", 1000));
	if (nb == count++)
		return(ac == 2 ? printf("%i", -1000) : ft_printf("%i", -1000));
	if (nb == count++)
		return(ac == 2 ? printf("%d", 0) : ft_printf("%d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%d", -1) : ft_printf("%d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%d", -42) : ft_printf("%d", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%d", 1) : ft_printf("%d", 1));
	if (nb == count++)
		return(ac == 2 ? printf("%d", 42) : ft_printf("%d", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%d", INT_MAX) : ft_printf("%d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%d", INT_MAX + 1) : ft_printf("%d", INT_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%d", INT_MIN) : ft_printf("%d", INT_MIN));
	if (nb == count++)
		return(ac == 2 ? printf("%d", 1000) : ft_printf("%d", 1000));
	if (nb == count++)
		return(ac == 2 ? printf("%d", -1000) : ft_printf("%d", -1000));
	if (nb == count++)
		return(ac == 2 ? printf("%u", 0) : ft_printf("%u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%u", -1) : ft_printf("%u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%u", 1) : ft_printf("%u", 1));
	if (nb == count++)
		return(ac == 2 ? printf("%u", 42) : ft_printf("%u", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%u", UINT_MAX) : ft_printf("%u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%u", UINT_MAX + 1) : ft_printf("%u", UINT_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%u", 1000) : ft_printf("%u", 1000));
	if (nb == count++)
		return(ac == 2 ? printf("%x", 0) : ft_printf("%x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%x", -1) : ft_printf("%x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%x", -42) : ft_printf("%x", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%x", 1) : ft_printf("%x", 1));
	if (nb == count++)
		return(ac == 2 ? printf("%x", 42) : ft_printf("%x", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%x", INT_MAX) : ft_printf("%x", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%x", INT_MAX + 1) : ft_printf("%x", INT_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%x", INT_MIN) : ft_printf("%x", INT_MIN));
	if (nb == count++)
		return(ac == 2 ? printf("%x", 1000) : ft_printf("%x", 1000));
	if (nb == count++)
		return(ac == 2 ? printf("%x", -1000) : ft_printf("%x", -1000));
	if (nb == count++)
		return(ac == 2 ? printf("%X", 0) : ft_printf("%X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%X", -1) : ft_printf("%X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%X", -42) : ft_printf("%X", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%X", 1) : ft_printf("%X", 1));
	if (nb == count++)
		return(ac == 2 ? printf("%X", 42) : ft_printf("%X", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%X", INT_MAX) : ft_printf("%X", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%X", INT_MAX + 1) : ft_printf("%X", INT_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%X", INT_MIN) : ft_printf("%X", INT_MIN));
	if (nb == count++)
		return(ac == 2 ? printf("%X", 1000) : ft_printf("%X", 1000));
	if (nb == count++)
		return(ac == 2 ? printf("%X", -1000) : ft_printf("%X", -1000));
	if (nb == count++)
		return(ac == 2 ? printf("%p", (void*)1) : ft_printf("%p", (void*)1));
	if (nb == count++)
		return(ac == 2 ? printf("%p", (void*)-1) : ft_printf("%p", (void*)-1));
	if (nb == count++)
		return(ac == 2 ? printf("%p", (void*)42) : ft_printf("%p", (void*)42));
	if (nb == count++)
		return(ac == 2 ? printf("%p", (void*)1000) : ft_printf("%p", (void*)1000));
	if (nb == count++)
		return(ac == 2 ? printf("%p", (void*)ULONG_MAX) : ft_printf("%p", (void*)ULONG_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%p", (void*)ULONG_MAX + 1) : ft_printf("%p", (void*)ULONG_MAX + 1));

	// [B - Tests with minimum field width].
return (0);
}
