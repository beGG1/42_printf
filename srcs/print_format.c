#include "../includes/ft_printf.h"

int print_format(char c, va_list args, int pr)
{
    char    *str;
    int     nbr;

    if (c == 'c' && pr)
        return (print_char(va_arg(args, int)));
    if (c == 's')
    {
        str = va_arg(args, char *);
        if (pr)
            return (print_string(str));
        return str_len(str);
    }
    if (c == '%' && pr)
        return (write(1, "%", 1));
    if (c == 'i' || c == 'd')
    {
        nbr = va_arg(args, int);
        if (pr)
            return print_int(nbr);
        return (ft_numlen(nbr));
    }
    if (c == 'u')
    {
        nbr = va_arg(args, int);
        
        if (pr)
            return print_uint((unsigned int)nbr);
        return (ft_unumlen((unsigned int)nbr));
    }
    return (1);
}