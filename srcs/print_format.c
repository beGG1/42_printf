#include "../includes/ft_printf.h"

int print_format(char c, va_list args, int pr)
{
    char    *str;
    int     nbr;
    void    *ptr;

    if (c == 'c' && pr)
        return (print_char(va_arg(args, int)));
    if (c == 's')
		print_str_arg(va_arg(args, char *), pr);
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
    if (c == 'x')
    {
        nbr = va_arg(args, int);
        
        if (pr)
            return print_hex(nbr, 'a');
        return (len_hex((unsigned int)nbr));
    }
    if (c == 'X')
    {
        nbr = va_arg(args, int);
        
        if (pr)
            return print_hex(nbr, 'A');
        return (len_hex((unsigned int)nbr));
    }
    if (c == 'p')
    {
        ptr = va_arg(args, void *);

        if (ptr == NULL)
        {
            if (pr)
                return (print_string("(nil)"));
            return str_len("(nil)");
        }
        
        if (pr)
            return print_address(ptr);
        return (17);
    }
    return (1);
}