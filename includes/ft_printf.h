/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:35:44 by vhoracek          #+#    #+#             */
/*   Updated: 2025/04/14 22:12:21 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	convert(char c_char, va_list ap);
int	convert_int(char c_char, va_list ap);
int	convert_p(va_list ap);
int	convert_str(va_list ap);

#endif
