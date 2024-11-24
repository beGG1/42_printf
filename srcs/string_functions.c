#include "../includes/ft_printf.h"

int str_len(char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

int print_string(char *str)
{
    int     len;
    char    *s;

    if (str == NULL)
        s = "(null)";
    else
        s = str;
    len = str_len(s);
    return (write(1, s, len));
}

int print_char(int c)
{
    unsigned char   ch;

    ch = c;
    if (ch > 127 || ch < 32)
        return (-1);
    return (write(1, &ch, 1));
}
