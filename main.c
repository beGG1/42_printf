# include "includes/ft_printf.h"
# include <stdio.h>
# include <limits.h>

int main() {
    ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
    printf(" %p %p \n", LONG_MIN, LONG_MAX);
}
