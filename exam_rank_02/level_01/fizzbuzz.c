/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:16:04 by vinda-si          #+#    #+#             */
/*   Updated: 2025/03/25 21:16:04 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(void)
{
	int number, k, j;

	number = 1;

	while (number <= 100)
	{
		if ((number % 3 == 0) && (number % 5 == 0))
			write(1, "fizzbuzz", 8);
		else if (number % 5 == 0)
			write(1, "buzz", 4);
		else if (number % 3 == 0)
			write(1, "fizz", 4);
		else if (number > 10)
		{
			k = number / 10 + '0';
			j = number % 10 + '0';
			write (1, &k, 1);
			write (1, &j, 1);
		}
		else
		{
			k = number + '0';
			write(1, &k, 1);
		}
		write(1, "\n", 1);
		number++;
	}
	return (0);
}