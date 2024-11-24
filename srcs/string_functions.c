#include "../includes/ft_printf.h"

int str_len(char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

int print_padding_space(t_format *f, int len)
{
    int n;

    n = f->width - len;
    while (n > 0)
    {
        if (write(1, " ", 1) < 1)
            return (-1);
        n--;
    }
    return (1);
}

int print_string(char *str, t_format *f)
{
    int     len;
    char    *s;

    if (str == NULL)
        s = "(null)";
    else
        s = str;
    len = str_len(s);
    if (f->minus == 0 && f->plus == 0 && f->space != 0)
    {
        if (write(1, " ", 1) < 1)
            return (-1);
    }
    else if (f->minus != 0)
    {
        if (write(1, s, len) < 1)
            return (-1);
        if (print_padding_space(f, len) < 0)
            return (-1);
        return (1);
    }
    else if (f->minus == 0)
    {
        if (print_padding_space(f, len) < 0)
            return (-1);
    }
    return (write(1, s, len));
}

int print_char(int c, t_format *f)
{
    if (c > 127 || c < 32)
        return (-1);
    if (f->minus == 0 && f->plus == 0 && f->space != 0)
    {
        if (write(1, " ", 1) < 1)
            return (-1);
    }
    else if (f->minus != 0)
    {
        if (write(1, &c, 1) < 1)
            return (-1);
        if (print_padding_space(f, 1) < 0)
            return (-1);
        return (1);
    }
    else if (f->minus == 0)
    {
        if (print_padding_space(f, 1) < 0)
            return (-1);
    }
    return (write(1, &c, 1));
}
