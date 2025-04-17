/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:00:22 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/17 12:28:20 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	size;
	int	*res;
	int	i;

	size = 0;
	if (end > start)
		size = end - start;
	else
		size = start - end;
	size += 1;

	res = malloc(size * sizeof(int));
	if (!res)
		return (NULL);
	
	i = 0;
	if (start < end)
	{
		while (start <= end)
		{
			res[i] = start;
			start++;
			i++;
		}
	}
	else
	{
		while (start >= end)
		{
			res[i] = start;
			start--;
			i++;
		}
	}
	return (res);
}

// int	main(int argc, char *argv[])
// {
// 	int	start;
// 	int end;
// 	int *range;
// 	int i;
// 	int size;

// 	if (argc != 3)
// 	{
// 		printf("\n");
// 		return(1);
// 	}

// 	start = atoi(argv[1]);
// 	end = atoi(argv[2]);

// 	if (end > start)
// 		size = end - start + 1;
// 	else
// 		size = start - end + 1;
	
// 	range = ft_range(start, end);
// 	if (!range)
// 	{
// 		printf ("\n");
// 		return (1);
// 	}

// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d", range[i]);
// 		if (i < size - 1)
// 			printf(", ");
// 		i++;
// 	}
// 	printf("\n");
	
// 	free(range);
// 	return (0);
// }