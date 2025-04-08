/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:24:28 by vhoracek          #+#    #+#             */
/*   Updated: 2025/04/08 16:05:15 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

int	ft_printf(const char *str, ...);
int	convert(char c_char, va_list ap);

int	main(int argc, char *argv[])
{
	char	*str;
	int		num;
	int		chars;

	if (argc == 0)
		return (printf("\nGive 2 arguments: 1/String 2/int %s\n", argv[0]) * 0 - 1);
	str = NULL;
	num = 0;
	chars = printf("U: %u\nI: %i\nD: %d\nS: %s\nC: %c\n%%\np: %p\nx: %x\nX %X\n", num, num, num, str, str[0], &num, num, num);
	printf("CHARS Print_F: %i\n", chars);
	chars = ft_printf("U: %u\nI: %i\nD: %d\nS: %s\nC: %c\n%%\np: %p\nx: %x\nX %X\n", num, num, num, str, str[0], &num, num, num);
	ft_printf("CHARS PRinTED: %i\n", chars);
	return (0);
}
