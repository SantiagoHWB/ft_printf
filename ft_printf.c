/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swamp-bl <swamp-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:19:50 by swamp-bl          #+#    #+#             */
/*   Updated: 2025/02/14 14:41:36 by swamp-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftprintf.h"

int ft_printf(const char *frmt, ...)
{
	va_list args;
	int len;

	len = 0;
	va_start(args, frmt);
	
    while (*frmt != '\0')
    {
        if (*frmt == '%')
        {
            frmt++;  
            ft_handlefrmt(&args, *frmt, &len);
        }
        else
        {
            ft_putchar(*frmt, &len);
        }
        frmt++; 
    }
	va_end(args);
	return (len);
}