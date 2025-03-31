/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:32:42 by vinda-si          #+#    #+#             */
/*   Updated: 2025/03/31 20:45:12 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

// #include <stdlib.h>
// #include <stdio.h>

// int main(int argc, char **argv)
// {
// 	if (argc == 3)
// 		printf("ft_strcmp(\"%s\", \"%s\") = %d\n", argv[1], argv[2], ft_strcmp(argv[1], argv[2]));
// return(0);
// }