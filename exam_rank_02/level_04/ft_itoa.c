/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:52:48 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/18 19:33:59 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>


int	absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	get_len(int nbr)
{
	int	len = 0;
	if (nbr <= 0)
		++len;
	while (nbr != 0)
	{
		++len;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char	*result;
	int		len;

	len = get_len(nbr);
	result = malloc(sizeof(char) * (len + 1));
	result[len] = '\0';

	if (nbr < 0)
		result[0] = '-';
	else if (nbr == 0)
		result[0] = '0';
	
	while (nbr != 0)
	{
		--len;
		result[len] = absolute_value(nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (result);
}

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	int	i = INT_MIN;
// 	char *str = ft_itoa(i);
// 	printf("%d = %s\n", i, str);
// 	free(str);

// 	i = -13;
// 	str = ft_itoa(i);
// 	printf("%d = %s\n", i, str);
// 	free(str);

// 	i = 0;
// 	str = ft_itoa(i);
// 	printf("%d = %s\n", i, str);
// 	free(str);

// 	i = 5;
// 	str = ft_itoa(i);
// 	printf("%d = %s\n", i, str);
// 	free(str);

// 	i = INT_MAX;
// 	str = ft_itoa(i);
// 	printf("%d = %s\n", i, str);
// 	free(str);

// 	return(0);
// }