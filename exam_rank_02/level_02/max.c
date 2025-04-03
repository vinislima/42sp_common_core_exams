/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:38:26 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/03 20:17:35 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int* tab, unsigned int len)
{
	unsigned int	count = 0;
	int 			result = 0;
	int 			i = 0;
	
	if (len == 0)
		return (0);
	
	if (len > 0)
	{
		while (count < len)
		{
			if (tab[i] > result)
				result = tab[i];
			i++;
			count++;
		}
		return (result);
	}
	return (0);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	int	int_tab[] = {1, 40, 5, 20, 2};
// 	printf("%d\n", max(int_tab, 5));
//
// 	return (0);
// }