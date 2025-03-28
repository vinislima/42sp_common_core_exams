/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:04:41 by vinda-si          #+#    #+#             */
/*   Updated: 2025/03/27 21:44:08 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int temp_a;

	temp_a = *a;
	*a = *b;
	*b = temp_a;
}

// int	main(void)
// {
// 	int	*a;
// 	int	*b;
// 	int	numb_a;
// 	int	numb_b;

// 	numb_a = 10;
// 	numb_b = 100;

// 	a = &numb_a;
// 	b = &numb_b;
	
// 	printf("A = %u, B = %u\n", *a, *b);
// 	ft_swap(a, b);
// 	printf("A = %u, B = %u\n", *a, *b);
// 	return (0);
// }