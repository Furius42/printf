/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:03:46 by vhoracek          #+#    #+#             */
/*   Updated: 2025/04/14 21:11:11 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	len = write(1, out, ft_strlen(out));
	free(out);
	return (len);
}
