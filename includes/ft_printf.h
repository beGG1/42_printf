/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 02:16:53 by sshabali          #+#    #+#             */
/*   Updated: 2024/11/21 17:22:33 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_format
{
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		hash;
	int		dot;
	int		width;
	int		perc;
	char	type;
}	t_format;

int			ft_printf(const char *str, ...);
t_format	*init_format(void);
int			reset_format(t_format *f);
int			fill_format(const char *str, t_format *f);
int			print_format(t_format *f, va_list args);
int			ft_str_len(char *str);
int			ft_putstr(char *str);
int			ft_putnbr_base(int i, char *base);

#endif
