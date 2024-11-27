#include "../includes/ft_printf.h"

int	print_int(int n)
{
    char    *nbr;
    int     temp;

    nbr = ft_itoa(n);
    if (!nbr)
        return (-1);
    temp = print_string(nbr);
    free(nbr);
    return (temp);
}

int	print_uint(unsigned int n)
{
    char    *nbr;
    int     temp;

    nbr = ft_utoa(n);
    if (!nbr)
        return (-1);
    temp = print_string(nbr);
    free(nbr);
    return (temp);
}

int	print_hex(int n, char a)
{
	char    *nbr;
    int     temp;

    nbr = int_to_hex(n, a);
    if (!nbr)
        return (-1);
    temp = print_string(nbr);
    free(nbr);
    return (temp);
}