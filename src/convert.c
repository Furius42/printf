/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:53:08 by vhoracek          #+#    #+#             */
/*   Updated: 2025/04/14 22:16:06 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	convert(char c_char, va_list ap)
{
	int		len;

	len = 0;
	if (ft_strchr("diuxX", c_char))
		return (convert_int(c_char, ap));
	if (c_char == 'c')
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		return (1);
	}
	else if (c_char == 'p')
		return (convert_p(ap));
	else if (c_char == 's')
		return (convert_str(ap));
	else if (c_char == '%')
		return (write(1, &c_char, 1));
	else
		return (write(1, "%", 1) + write(1, &c_char, 1) + 1);
}
