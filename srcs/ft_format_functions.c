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

t_format	*init_format()
{
	t_format	*f;

	f = (t_format *)malloc(sizeof(f));
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

