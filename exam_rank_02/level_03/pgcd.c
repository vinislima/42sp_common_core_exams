/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:53:10 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/17 20:27:01 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	pgcd(int a, int b)
{
	int	n = a;

	while (n > 0)
	{
		if (a % n == 0 && b % n == 0)
		{
			printf("%d", n);
			return ;
		}
		n--;
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("\n");
		return (0);
	}
	pgcd(atoi(argv[1]), atoi(argv[2]));
	printf("\n");
	return (0);
}