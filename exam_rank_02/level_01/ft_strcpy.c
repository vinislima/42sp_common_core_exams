/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:52:51 by vinda-si          #+#    #+#             */
/*   Updated: 2025/03/26 19:39:29 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s2);
}

// int	main(void)
// {
// 	char dest[10];
// 	char *src = "teste";
//
// 	printf("%s\n", dest);
// 	ft_strcpy(dest, src);
// 	printf("%s\n", dest);
//
// 	return (0);
// }