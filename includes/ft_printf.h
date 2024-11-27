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

int		ft_printf(const char *str, ...);
char	*int_to_hex(int num, char a);
char	*ulong_to_hex(unsigned long num, char a);
char	*ft_utoa(unsigned int n);
char	*ft_itoa(int n);
int		in_set(char c, char *set);
int		print_format(char c, va_list args, int pr);
int		len_hex(unsigned long long n);
int		print_hex_arg(int n, char c, int pr);
int		ft_numlen(int n);
int		print_int_arg(int n, int pr);
int		print_ptr_arg(void *ptr, int pr);
int		str_len(char *str);
int		print_string(char *str);
int		print_char(int c);
int		print_str_arg(char *str, int pr);
int		ft_unumlen(unsigned int n);
int		print_uint_arg(int n, int pr);

#endif
