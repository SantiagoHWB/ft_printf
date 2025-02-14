/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhelp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swamp-bl <swamp-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:21:34 by swamp-bl          #+#    #+#             */
/*   Updated: 2025/02/14 13:34:09 by swamp-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i], len);
		i++;
	}
}

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putptr(void *ptr, int *len)
{
	unsigned long	address;

	address = (unsigned long)ptr;
	ft_putstr("0x", len);
	if (address == 0)
		ft_putchar('0', len);
	else
		ft_puthex(address, len);
}
void	ft_puthex(unsigned long num, int *len)
{
	char	*hex_digits;

	*hex_digits = "0123456789abcdef";
	if (num >= 16)
		ft_puthex(num / 16, len);
	ft_putchar(hex_digits[num % 16], len);
}

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', len);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, len);
	}
	ft_putchar((n % 10) + '0', len);
}