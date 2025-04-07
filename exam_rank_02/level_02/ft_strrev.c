/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:07:06 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/06 18:38:31 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	temp;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	while (i < (len - 1))
	{
		temp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = temp;
		i++;
		len--;
	}
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char s[] = "Hello World";
// 	printf("%s\n", s);
// 	ft_strrev(s);
// 	printf("%s\n", s);
// 	return (0);
// }