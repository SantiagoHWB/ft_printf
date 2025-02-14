/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlefrmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swamp-bl <swamp-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:13:29 by swamp-bl          #+#    #+#             */
/*   Updated: 2025/02/14 13:32:59 by swamp-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

void ft_handlefrmt(va_list *args, char c, int *len)
{
	if (c == 's')
		ft_putstr(va_arg(*args, char *), len);
	else if(c == 'c')
		ft_putchar(va_arg(*args, char), len);
	else if(c == 'p')
		ft_putptr(va_arg(*args, void *), len);
	else if(c == 'd' || c == 'i')
		ft_putnbr(va_arg(*args void *), len);
	else if (c == 'u')
		ft_putunbr(va_arg(*args, unsigned int), &len);
	else if (c == 'x')
		ft_puthex(va_arg(*args, unsigned int), &len);
	else if (c == 'X')
		ft_puthexx(va_arg(*args, unsigned int), &len);
	else if (c == '%')
		ft_printpercentage(va_arg(*args, char), len);
}

void ft_putunbr(unsigned int n, int *len)
{
	if (n > 9)
		ft_putunbr(n /10, len);
	ft_putchar((n % 10) + '0', len);
}

void ft_printpercentage(char c, int *len)
{
	if (c == '%')
		ft_putchar('%', len);
}
void	ft_puthexx(unsigned long num, int *len)
{
	char	*hex_digits;

	*hex_digits = "0123456789ABCDEF";
	if (num >= 16)
		ft_puthex(num / 16, len);
	ft_putchar(hex_digits[num % 16], len);
}