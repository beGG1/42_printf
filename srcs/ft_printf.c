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
	t_format	*f;
	int			a;
	int			out;
	int			temp;

	i = 0;
	f = init_format();
	out = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			if (write(1, &str[i], 1) < 1)
				return (-1);
			out += 1;
		}
		else
		{
			a = fill_format(&str[++i], f);
			if (a < 0)
			{
				reset_format(f);
				if (write(1, "%", 1) < 1)
				{
					free(f);
					return (-1);
				}
				i--;
			}
			else
			{
				temp = print_format(f, args);
				if (temp < 0)
				{
					free(f);
					return (-1);
				}
				out += temp;
				i += a;
				reset_format(f);
			}
		}
		i++;
	}
	free(f);
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
