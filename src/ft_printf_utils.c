/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:29:48 by vhoracek          #+#    #+#             */
/*   Updated: 2025/04/22 20:29:43 by vhoracek         ###   ########.fr       */
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

int	convert_int(char c_char, va_list ap)
{
	char	*out;
	int		len;

	len = 0;
	if (c_char == 'X')
		out = ft_strupcase(ft_bitoa(va_arg(ap, unsigned int), 16));
	else if (c_char == 'x')
		out = ft_bitoa(va_arg(ap, unsigned int), 16);
	else if (c_char == 'u')
		out = ft_utoa(va_arg(ap, unsigned int));
	else
		out = ft_itoa(va_arg(ap, int));
	if (out == NULL)
		return (0);
	len += write(1, out, ft_strlen(out));
	free(out);
	return (len);
}

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
	if (out == NULL)
		return (0);
	len += write(1, out, ft_strlen(out));
	free(out);
	return (len);
}

int	convert_str(va_list ap)
{
	char	*arg;
	char	*out;
	int		len;

	len = 0;
	arg = va_arg(ap, char *);
	if (arg == NULL)
		out = ft_strdup("(null)");
	else
		out = ft_strdup(arg);
	if (out == NULL)
		return (0);
	len = write(1, out, ft_strlen(out));
	free(out);
	return (len);
}
