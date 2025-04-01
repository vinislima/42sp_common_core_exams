/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:02:38 by vinda-si          #+#    #+#             */
/*   Updated: 2025/03/31 22:15:10 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char *tmp;
	int len;
	int i;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
	tmp = malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	while (src[i] != '\0')
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*a;
// 	a = "Hello World";
// 	printf("%s\n", ft_strdup(a));
// 	return (0);
// }