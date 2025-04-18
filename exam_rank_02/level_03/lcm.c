/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:38:48 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/17 22:06:17 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);
	
	unsigned int	n;
	if (a > b)
		n = a;
	else
		n = b;
	
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		n++;
	}
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(int argc, char *argv[])
// {
// 	if (argc != 3)
// 		return (0);

// 	unsigned int m = lcm(atoi(argv[1]), atoi(argv[2]));
// 	printf("LCM = %u\n", m);
// 	return (0);
// }