/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:51:15 by sshabali          #+#    #+#             */
/*   Updated: 2024/11/21 17:21:48 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr(int n, char *base, int base_len)
{
	if (n == -2147483648)
	{
		return ft_putstr("-2147483648");
	}
	else if (n < 0)
	{
		if (write(1, "-", 1) < 1)
			return (-1);
		ft_putnbr(-n, base, base_len);
	}
	else if (n >= base_len)
	{
		ft_putnbr(n / base_len, base, base_len);
		if (write(1, &base[n % base_len], 1) < 1)
			return (-1);
	}
	else
	{
		if (write(1, &base[n], 1) < 1)
			return (-1);
	}
	return (1);
}


int	ft_putnbr_base(int n, char *base)
{
	return (ft_putnbr(n, base, ft_str_len(base)));
}
