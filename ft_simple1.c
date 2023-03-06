/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:24:37 by khle              #+#    #+#             */
/*   Updated: 2022/06/03 20:43:36 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_len_dec(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_dec(int n)
{
	int	len;

	len = ft_len_dec(n);
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_dec(n / 10);
	ft_putchar(n % 10 + '0');
	return (len);
}

int	ft_putpointer(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		i += ft_putstr("0x");
		i += ft_putnbr_p(n, 'x');
	}
	return (i);
}

/*int main()
{
	long unsigned int i;
	i = 0x145abc;
	ft_putpointer(i);
    return (1);
}*/