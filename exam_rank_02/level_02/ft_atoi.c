/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:14:13 by vinda-si          #+#    #+#             */
/*   Updated: 2025/03/31 20:16:48 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	count;

	result = 0;
	count = 0;
	sign = 1;

	while (str[count] == ' '
			|| str[count] == '\t' || str[count] == '\n'
			|| str[count] == '\r' || str[count] == '\v'
			|| str[count] == '\f')
					count++;
	if (str[count] == '-')
	{
		sign = -1;
		count++;
	}
	else if (str[count] == '+')
		count++;
	while (str[count] >= '0' && str[count] <= '9')
	{
		result = (result * 10) + (str[count] - '0');
		count++;
	}
	return (sign * result);
}


// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("%d\n", ft_atoi(argv[1]));
// 		return (0);
// 	}
// 	printf("\n");
// 	return (0);
// }