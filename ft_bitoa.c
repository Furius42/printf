/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:28:13 by vhoracek          #+#    #+#             */
/*   Updated: 2025/03/18 12:28:13 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char* ft_bitoa(int n, int base);

int main(int argc, char* argv[])
{
	if (argc != 3)
		printf("Usage: Input 2 parameters:\n1) Number to convert\n2) The base to convert to\n");
	char	*result;

	result = ft_bitoa(atoi(argv[1]), atoi(argv[2]));
	if (result)
	{
		printf("Result: %s\n", result);
		free(result);
	}
	return (0);
}

static int	count_digits(int n, int base)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

static char	*decimal(int n, char *str, int len)
{
	unsigned int	num;

	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	num = n;
	str[len] = '\0';
	while (--len >= 0 && str[len] != '-')
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
static char *convert(int n, char *str, int len, int base)
{
	unsigned int	num;
	static char*	chars;

	chars = "0123456789abcdefghijklmnopqrstuvwxyz";
	num = n;
	str[len] = '\0';
	while (--len >= 0 )
	{
		str[len] = chars[(num % base)];
		num /= base;
	}
	return (str);
}

char* ft_bitoa(int n, int base)
{
	char	*str;
	int		len;

	len = count_digits(n, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str || base > 36 || base < 2)
		return (NULL);
	if (base == 10)
		return (decimal(n, str, len));
	else
		return (convert(n, str, len, base));
}
