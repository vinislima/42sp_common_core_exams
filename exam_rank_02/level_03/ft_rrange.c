/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:34:33 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/17 16:49:58 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	i = 0;
	int	len = (end - start);

	if (len < 0)
		len = ((end - start) * -1) + 1;
	else
		len = (end - start) + 1;

	int	*range = (int *)malloc(len * sizeof(int));

	while (i < len)
	{
		if (end < start)
			range[i] = end++;
		else
			range[i] = end--;
		i++;
	}
	return (range);
}

// #include <stdio.h>

// void print_test_case(int start, int end)
// {
// 	int *arr = ft_rrange(start, end);
// 	if (arr == NULL) {
// 		printf("Memory allocation failed for start=%d, end=%d\n", start, end);
// 		return;
// 	}
// 	int len = abs(end - start) + 1;
// 	printf("Test case: start=%d, end=%d\n", start, end);
// 	printf("Expected length: %d\n", len);
// 	printf("Result: [");
// 	for (int i = 0; i < len; i++) {
// 		printf("%d", arr[i]);
// 		if (i < len - 1) printf(", ");
// 	}
// 	printf("]\n\n");
// 	free(arr);
// }

// int main(int argc, char *argv[])
// {
// 	// Test cases
// 	if (argc != 3)
// 		return (0);
// 	int	start = atoi(argv[1]);
// 	int	end = atoi(argv[2]);
// 	print_test_case(start, end);
// 	// print_test_case(1, 3);	 // start < end
// 	// print_test_case(5, 10);	// start < end (maior intervalo)
// 	// print_test_case(5, 2);	 // start > end
// 	// print_test_case(3, 0);	 // start > end (intervalo negativo)
// 	// print_test_case(7, 7);	 // start == end
// 	// print_test_case(4, 5);	 // start < end (intervalo de 2)
// 	// print_test_case(6, 5);	 // start > end (intervalo de 2)
// 	// print_test_case(-3, 2);	// start negativo, end positivo
// 	// print_test_case(0, 0);
// 	return (0);
// }