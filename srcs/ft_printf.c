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
	int			i;
	int			out;
	int			temp;
	int			pr;

	i = 0;
	out = 0;
	pr = 1;
	while (str[i])
	{
		temp = 0;
		if (str[i] != '%')
		{
			if (pr)
			{
				if (write(1, &str[i], 1) < 1)
					return (-1);
			}
			out += 1;
		}
		else
		{
			if (in_set(str[i + 1], "idscupxX%%"))
				temp = print_format(str[i + 1], args, pr);
			if (temp < 0)
			{
				if (str[i + 1] != 'c')
					return (-1);
				pr = 0;
				out += 2;
			}
			out += temp;
			i++;
		}
		i++;
	}
	return (out);
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
