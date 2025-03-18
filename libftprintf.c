/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:15:27 by vhoracek          #+#    #+#             */
/*   Updated: 2025/03/11 19:15:27 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include <stdarg.h>

int	convert(char c_char, va_list ap); //remove

int ft_printf(const char *str, ...);

int	main(int argc, char* argv[])
{
	ft_printf(argv[1]);
	printf(argv[1]);
	return (0);
}

int ft_printf(const char *str, ...)
{
	va_list ap;
	int		len;

	va_start(ap, str);
	len = 0;
	while (str)
	{
		if (*str == '%')
			len += convert(*++str,ap);
		else
			len += write(1, *str++, 1);
		++len;
	}
	va_end(ap);
	return (len);
}


/*
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.

*/