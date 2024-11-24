#include "../includes/ft_printf.h"

int print_format(t_format *f, va_list args)
{
	if (f->type == 's')
		return (print_string(va_arg(args, char *), f));
	if (f->type == 'c')
		return (print_char(va_arg(args, int), f));

	return (0);
}