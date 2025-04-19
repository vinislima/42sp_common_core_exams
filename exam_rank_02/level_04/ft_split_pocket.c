/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pocket.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:03:57 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/18 20:15:14 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define WD_LEN 1000

char	**ft_split(char *str)
{
	char	**array;
	int		i = 0;
	int		j = 0;
	int		k;

	array = malloc(WD_LEN);
	while (str[i])
	{
		if (str[i] > 32)
		{
			k = 0;
			array[j] = malloc(WD_LEN);
			while(str[i] > 32)
				array[j][k++] = str[i++];
			array[j++][k] = '\0';
		}
		else
			i++;
	}
	array[j] = NULL;
	return (array);
}

// #include <stdio.h>

// int	main(int argc, char *argv[])
// {
// 	char	**split;
// 	int		i;

// 	if (argc == 2)
// 	{
// 		split = ft_split(argv[1]);
// 			printf("%s ", split[0]);
// 		i = 1;
// 		while (split[i] != 0)
// 		{
// 			printf("%s ", split[i]);
// 			i++;
// 		}
// 		printf("%s", split[i]);
// 	}
// 	printf("\n");
// 	return (0);
// }