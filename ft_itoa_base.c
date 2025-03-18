/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:22:57 by vhoracek          #+#    #+#             */
/*   Updated: 2025/03/18 12:22:57 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/* THIS IS THE ORIGINAL ITOA non base !!! MAIN .. MODIFY ACCORDINGLY
#include <stdio.h>

static int	count_digits(int n);
static char	*handle_negative(int n, char *str, int len);
char* ft_bitoa(int n, char* buffer, int base);

int main(void)
{
	char	*result;

	result = ft_itoa(-23042);
	if (result)
	{
		printf("Result: %s\n", result);
		free(result);
	}
	return (0);
}
*/
static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*handle_negative(int n, char *str, int len)
{
	unsigned int	num;

	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	str[len] = '\0';
	while (--len >= 0 && str[len] != '-')
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

char* bitoa(int n, char* buffer, int base)
{
	char	*str;
	int		len;

	len = count_digits(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	return (handle_negative(n, str, len));
}
