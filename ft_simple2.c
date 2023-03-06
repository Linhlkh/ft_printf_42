/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:14:01 by khle              #+#    #+#             */
/*   Updated: 2022/06/03 21:01:57 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_hex(unsigned int n)
{
	int	i;

	i = 0;
	i = (n == 0);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_putnbr_hex(unsigned int n, char c)
{
	int	i;

	i = ft_len_hex(n);
	if (n >= 16)
	{
		ft_putnbr_hex(n / 16, c);
		ft_putnbr_hex(n % 16, c);
	}
	else if (c == 'x')
		write(1, &"0123456789abcdef"[n], 1);
	else if (c == 'X')
		write(1, &"0123456789ABCDEF"[n], 1);
	return (i);
}

int	ft_len_ui(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_ui(unsigned int n)
{
	int	i;

	i = ft_len_ui(n);
	if (n > 9)
		ft_putnbr_ui(n / 10);
	ft_putchar(n % 10 + '0');
	return (i);
}

int	ft_len_p(unsigned long long n)
{
	int	i;

	i = 0;
	i = (n == 0);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

/*int main()
{
    unsigned long int c;
    c = 0x145abc;
    char s;
    s = 'X';
    //printf("%d\n",ft_len_hex(c));
   ft_putnbr_hex(c, s);
   printf("\n%d",ft_len_hex(c));
   //printf("\n%X", c);
}

int main()
{
    unsigned int n;
    n = 0;
    printf("\n%d", ft_putnbr_ui(n));
}*/