/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:09:10 by vhoracek          #+#    #+#             */
/*   Updated: 2025/04/14 22:33:18 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// Using ULInt should be ok on 32 an 64 bit systems.
//To be safe I should #include <stdint.h> to use uintptr_t to store pointers
int	convert_p(va_list ap)
{
	char				*out;
	unsigned long int	arg;
	int					len;

	len = 0;
	arg = va_arg(ap, unsigned long int);
	if (arg == 0)
		out = ft_strdup("(nil)");
	else
	{
		len = write(1, "0x", 2);
		out = ft_bitoa(arg, 16);
	}
	len += write(1, out, ft_strlen(out));
	free(out);
	return (len);
}
