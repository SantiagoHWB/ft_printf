/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swamp-bl <swamp-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:26:29 by swamp-bl          #+#    #+#             */
/*   Updated: 2025/02/14 13:41:02 by swamp-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

void	ft_handlefrmt(va_list *args, char c, int *len);
int		ft_printf(const char *frmt, ...);
void	ft_putstr(char *str, int *len);
void	ft_putchar(char c, int *len);
void	ft_putptr(void *ptr, int *len);
void	ft_puthex(unsigned long num, int *len);
void	ft_puthexx(unsigned long num, int *len);
void	ft_putnbr(int n, int *len);
void	ft_printpercentage(int *len);
void 	ft_putunbr(unsigned int n, int *len);

#endif