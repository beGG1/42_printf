#include "../includes/ft_printf.h"

int    print_address(void* ptr)
{
    char   *addr;
    char   buffer[18];
    int    pos;
    int    i;

    buffer[0] = '0';
    buffer[1] = 'x';
    addr = ulong_to_hex((unsigned long)ptr, 'a');
    pos = 2;
    i = 0;
    while (addr[i])
        buffer[pos++] = addr[i++];

    buffer[pos] = '\0';
    free(addr);
    return (print_string(buffer));
}