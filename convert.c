/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:41:25 by vhoracek          #+#    #+#             */
/*   Updated: 2025/03/18 12:20:55 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

va_list ap_c;

int	convert(char c_char, va_list ap)
{
	unsigned char*	out;
	int				len;

	if (c_char == 'c') //char - int argument is converted to an unsigned char, and the resulting character is written.
	{	
		out[0] = va_arg(ap, int);
		return (write(1, &out[0], 1));
	}
		else if  (c_char == 's')
	{
		out = ft_strdup(va_arg(ap, char*));
		return (write(1, out, ft_strlen(out)));
	}
	else if  (c_char == 'd' || c_char == 'i' || c_char == 'u') // decimal - int argument is converted to signed decimal notation.
	{
		if (c_char == 'u')
			out = ft_utoa(va_arg(ap, unsigned int));
		else
			out = ft_itoa(va_arg(ap, int));
		len = write(1, out, ft_strlen(out));
		free(out);
		return (len);
	}
	else if  (c_char == 'p' || c_char == 'x' || c_char == 'X') // ptr - void * pointer argument is printed in hexadecimal // as 'x'
	{
		
	}
	else if  (c_char == '%')
		return (write(1, '%', 1));
	else
	{
		write(1, '%', 1);
		return (write(1, &c_char, 1) + 1);
	}
}
