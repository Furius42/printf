/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:30:50 by vhoracek          #+#    #+#             */
/*   Updated: 2025/03/26 00:55:34 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
//#include "ftprintf.h"
#include "libft.h"

va_list	ap_c;

int	ft_printf(const char *str, ...);
int	convert(char c_char, va_list ap);

int	main()
{
	char	*str;
	int		num;
	int		chars;
	
	str = "This is number";
	num = 12345678;
	chars = ft_printf("Test %i string: %s", num, str);
	printf("CHARS PRinTED: %i STRING: %s", chars, str);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, str);
	len = 0;
	while (str)
	{
		if (*str == '%')
			len += convert(*++str, ap);
		else
			len += write(1, (const void*)str++, 1);
		++len;
	}
	va_end(ap);
	return (len);
}

int	convert(char c_char, va_list ap)
{
	char	*out;
	int		len;

	len = 0;
	if (c_char == 'c')
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		return (1);
	}
	else if (c_char == 's')
	{
		out = ft_strdup(va_arg(ap, char *));
		return (write(1, out, ft_strlen(out)));
	}
	else if (c_char == 'd' || c_char == 'i' || c_char == 'u')
	{
		if (c_char == 'u')
			out = ft_utoa(va_arg(ap, unsigned int));
		else
			out = ft_itoa(va_arg(ap, int));
		len = write(1, out, ft_strlen(out));
		free(out);
		return (len);
	}
	else if (c_char == 'p' || c_char == 'x' || c_char == 'X')
	{
		if (c_char == 'p')
		{
			len = write(1, "0x", 2);
			out = ft_bitoa(va_arg(ap, long long int), 16);
		}
		else if (c_char == 'X')
			out = ft_strupcase(ft_bitoa(va_arg(ap, long long int), 16));
		else
			out = ft_bitoa(va_arg(ap, long long int), 16);
		return (len + write(1, out, ft_strlen(out)));
	}
	else if (c_char == '%')
		return (write(1, &c_char, 1));
	else
	{
		write(1, &"%", 1);
		return (write(1, &c_char, 1) + 1);
	}
}
