/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:27:21 by khle              #+#    #+#             */
/*   Updated: 2022/06/03 21:02:20 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_len_dec(int n);
int	ft_putnbr_dec(int n);
int	ft_len_hex(unsigned int n);
int	ft_putnbr_hex(unsigned int n, char c);
int	ft_len_ui(unsigned int n);
int	ft_putnbr_ui(unsigned int n);
int	ft_check_conversion(const char *format, size_t i, va_list ap, size_t k);
int	ft_putpointer(unsigned long long n);
int	ft_len_p(unsigned long long n);
int	ft_putnbr_p(unsigned long long n, char c);

#endif