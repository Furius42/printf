/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:04:17 by vhoracek          #+#    #+#             */
/*   Updated: 2025/03/25 20:40:12 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
include <stdio.h>

char* ft_strupcase(char* str);

int main(int argc, char* argv[])
{
	if (argc != 2 )
		printf("Usage: Input a string\n");
	printf("Input : %s\n", argv[1]);
	printf("Output: %s\n", ft_strupcase(argv[1]));
	return (0);
}
*/
char	*ft_strupcase(char *str)
{
	char	*start;

	start = str;
	while (*str++)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
	}
	return (start);
}
