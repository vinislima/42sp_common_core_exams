/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:04:10 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/09 22:58:58 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_blank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int	isvalid(char c, int base)
{
	char digits_low[17] = "01234567890abcdef";
	char digits_caps[17] = "0123456789ABCDEF";

	while (base--)
		if (digits_low[base] == c || digits_caps[base] == c)
			return (1);
	return (0);
}

int	value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	result;
	int	sign;

	result = 0;
	while (is_blank(*str))
		str++;
	if (*str == '-')
		sign = -1;
	else
		sign = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (isvalid(*str, str_base))
		result = result * str_base + value_of(*str++);
	return (result * sign);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(int argc, char *argv[])
// {
// 	if (argc != 3)
// 	{
// 		printf("\n");
// 		return (0);
// 	}
// 	printf("%d\n", ft_atoi_base(argv[1], atoi(argv[2])));
// 	return (0);
// }