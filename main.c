/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:24:28 by vhoracek          #+#    #+#             */
/*   Updated: 2025/04/22 20:51:06 by vhoracek         ###   ########.fr       */
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

	if (argc != 3)
		return (ft_printf("Give 2 arguments: 1/int 2/str\n"));
	num = ft_atoi(argv[1]);
	str = argv[2];
	chars = ft_printf("U: %u\nI: %i\nD: %d\nS: %s\nC: %c\n%%\np: %p\nx: %x\nX %X\n", num, num, num, str, str[0], &num, num, num);
	ft_printf("CHARS Printed: %i\n\n", chars);
	chars = printf("U: %u\nI: %i\nD: %d\nS: %s\nC: %c\n%%\np: %p\nx: %x\nX %X\n", num, num, num, str, str[0], &num, num, num);
	printf("CHARS PrintF: %i\n\n", chars);
	ft_printf("Test: %p, %s\n", NULL, (char *) NULL);
	printf("Test: %p, %s\n", NULL, (char *) NULL);
	return (0);
}
