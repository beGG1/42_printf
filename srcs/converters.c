/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:33:57 by sshabali          #+#    #+#             */
/*   Updated: 2024/11/24 22:38:53 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	len_hex(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

char	*int_to_hex(int num, char a)
{
	unsigned int	n;
	int				max_digits;
	char			*hex ;
	int				digit;

	n = (unsigned int)num;
	max_digits = len_hex(n);
	hex = malloc(max_digits + 1);
	if (!hex)
		return (NULL);
	hex[max_digits] = '\0';
	while (max_digits > 0)
	{
		max_digits--;
		digit = n % 16;
		if (digit < 10)
			hex[max_digits] = (digit) + '0';
		else
			hex[max_digits] = (digit % 10) + a;
		n /= 16;
	}
	return (hex);
}

char	*ulong_to_hex(unsigned long num, char a)
{
	unsigned long	n;
	int				max_digits;
	char			*hex ;
	int				digit;

	n = (unsigned long)num;
	max_digits = len_hex(n);
	hex = malloc(max_digits + 1);
	if (!hex)
		return (NULL);
	hex[max_digits] = '\0';
	while (max_digits > 0)
	{
		max_digits--;
		digit = n % 16;
		if (digit < 10)
			hex[max_digits] = (digit) + '0';
		else
			hex[max_digits] = (digit % 10) + a;
		n /= 16;
	}
	return (hex);
}
