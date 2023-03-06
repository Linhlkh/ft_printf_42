/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:13:39 by khle              #+#    #+#             */
/*   Updated: 2022/06/03 20:59:44 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_p(unsigned long long n, char c)
{
	int	i;

	i = ft_len_p(n);
	if (n >= 16)
	{
		ft_putnbr_p(n / 16, c);
		ft_putnbr_p(n % 16, c);
	}
	else if (c == 'x')
		write(1, &"0123456789abcdef"[n], 1);
	else if (c == 'X')
		write(1, &"0123456789ABCDEF"[n], 1);
	return (i);
}

int	ft_check_conversion(const char *format, size_t i, va_list ap, size_t k)
{
	if (format[i + 1] == 'x' || format[i + 1] == 'X')
		k += ft_putnbr_hex(va_arg(ap, unsigned int), format[i + 1]);
	if (format[i + 1] == 'i' || format[i + 1] == 'd')
		k += ft_putnbr_dec(va_arg(ap, int));
	if (format[i + 1] == '%')
		k += ft_putchar('%');
	if (format[i + 1] == 'p')
		k += ft_putpointer(va_arg(ap, unsigned long long));
	if (format[i + 1] == 'c')
		k += ft_putchar(va_arg(ap, int));
	if (format[i + 1] == 's')
		k += ft_putstr(va_arg(ap, char *));
	if (format[i + 1] == 'u')
		k += ft_putnbr_ui(va_arg(ap, unsigned int));
	return (k);
}
