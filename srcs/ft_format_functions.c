/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:25:21 by sshabali          #+#    #+#             */
/*   Updated: 2024/11/20 20:31:09 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_format	*init_format(void)
{
	t_format	*f;

	f = (t_format *)malloc(sizeof(t_format));
	if (!f)
		return (NULL);
	f->dot = 0;
	f->hash = 0;
	f->perc = 0;
	f->plus = 0;
	f->type = 0;
	f->zero = 0;
	f->minus = 0;
	f->space = 0;
	f->width = 0;
	return (f);
}

int	reset_format(t_format *f)
{
	if (!f)
		return (0);
	f->dot = 0;
	f->hash = 0;
	f->perc = 0;
	f->plus = 0;
	f->type = 0;
	f->zero = 0;
	f->minus = 0;
	f->space = 0;
	f->width = 0;
	return (1);
}

int	fill_format(const char *str, t_format *f)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'd')
		{
			f->type = 'd';
			break;
		}
		if (str[i] == '%')
		{
			f->type = '%';
			break;
		}
		if (str[i] == 'c')
		{
			f->type = 'c';
			break;
		}
		i++;
	}
	return (i);
}

int	print_format(t_format *f, va_list args)
{
	int	arg;

	arg = va_arg(args, int);
	if (f->type == 'c')
		return (write(1, &arg, 1));
	if (f->type == '%')
		return (write(1, "%", 1));
}
