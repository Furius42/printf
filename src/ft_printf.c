/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:30:50 by vhoracek          #+#    #+#             */
/*   Updated: 2025/04/08 16:05:25 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
			len += write(1, (const void *)str++, 1);
		if (!*str)
			break ;
	}
	va_end(ap);
	return (len);
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
