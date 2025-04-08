/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:30:50 by vhoracek          #+#    #+#             */
/*   Updated: 2025/04/02 12:20:09 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
//#include "ftprintf.h"
#include "libft.h"

int	ft_printf(const char *str, ...);
static int	convert(char c_char, va_list ap);

int	main(int argc, char *argv[]) //  u  i  d  s  c  %  p  x  X
{
	char	*str;
	int		num;
	int		chars;
	
	if (argc == 0)
		return(printf("\nGive 2 arguments: 1/String 2/int %s\n", argv[0]) *0 -1);
	str = NULL;
	num = 0;
	chars = printf("U: %u\nI: %i\nD: %d\nS: %s\nC: %c\n%%\np: %p\nx: %x\nX %X\n", num, num, num, str, str[0], &num, num, num);
	printf("CHARS Print_F: %i\n", chars);
	chars = ft_printf("U: %u\nI: %i\nD: %d\nS: %s\nC: %c\n%%\np: %p\nx: %x\nX %X\n", num, num, num, str, str[0], &num, num, num);
	ft_printf("CHARS PRinTED: %i\n", chars);
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
		{
			len += convert(*++str, ap);
			str++;
		}
		else
			len += write(1, (const void*)str++, 1);
		if(!*str)
			break;
	}
	va_end(ap);
	return (len);
}

static int	convert(char c_char, va_list ap)
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
		len = write(1, out, ft_strlen(out));
		free(out);
		return (len);
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
		len += write(1, out, ft_strlen(out));
		free(out);
		return (len);
	}
	else if (c_char == '%')
		return (write(1, &c_char, 1));
	else
	{
		write (1, &"%", 1);
		return (write (1, &c_char, 1) + 1);
	}
}
/*
Check if strupcase and strdncase is fixed (skipping first letter)
Split convert function to fit 25 lines // or make shorter
Makefile
Norminette

Check Edge cases
/ invalid input
/ NULL input
/ out of range
/ memory leaks
/ error management

-Check with Francinette
*/