/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:13:50 by khle              #+#    #+#             */
/*   Updated: 2022/06/30 21:49:09 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t		i;
	size_t		k;
	va_list		ap;

	if (!format)
		return (0);
	va_start(ap, format);
	i = 0;
	k = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			k = ft_check_conversion(format, i, ap, k);
			i++;
		}
		else
			k = k + ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (k);
}
