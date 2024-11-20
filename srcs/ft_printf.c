/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 02:22:30 by sshabali          #+#    #+#             */
/*   Updated: 2024/11/20 02:22:31 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"

static int	ft_print(const char *str, va_list args)
{
	size_t		i;
	t_format	*f;

	i = 0;
	f = init_format();
	while (str[i])
	{
		if (str[i] != '%')
		{
			if (write(1, &str[i], 1) < 1)
				return (-1);
		}
		else
		{
			fill_format(&str[++i], f);
			print_format(f, args);
		}
		i++;
	}
}



int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		error;

	va_start(args, str);
	error = ft_print(str, args);
	va_end(args);
	return (error);
}
