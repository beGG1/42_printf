/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:42:53 by sshabali          #+#    #+#             */
/*   Updated: 2024/11/24 22:44:58 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	print_string(char *str)
{
	int		len;
	char	*s;

	if (str == NULL)
		s = "(null)";
	else
		s = str;
	len = str_len(s);
	return (write(1, s, len));
}

int	print_char(int c)
{
	unsigned char	ch;

	ch = c;
	return (write(1, &ch, 1));
}

int	print_str_arg(char *str, int pr)
{
	if (pr)
		return (print_string(str));
	return (str_len(str));
}
