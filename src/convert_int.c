/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:52:31 by vhoracek          #+#    #+#             */
/*   Updated: 2025/04/08 16:08:32 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	convert_int(char c_char, va_list ap)
{
	char	*out;
	int		len;

	len = 0;
	if (c_char == 'p')
	{
		len = write(1, "0x", 2);
		out = ft_bitoa(va_arg(ap, long long int), 16);
	}
	else if (c_char == 'X')
		out = ft_strupcase(ft_bitoa(va_arg(ap, long long int), 16));
	else if (c_char == 'x')
		out = ft_bitoa(va_arg(ap, long long int), 16);
	else if (c_char == 'u')
		out = ft_utoa(va_arg(ap, unsigned int));
	else
		out = ft_itoa(va_arg(ap, int));
	len = write(1, out, ft_strlen(out));
	free(out);
	return (len);
}
