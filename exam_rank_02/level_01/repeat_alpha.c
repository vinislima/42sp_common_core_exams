/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:28:56 by vinda-si          #+#    #+#             */
/*   Updated: 2025/03/30 22:28:17 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int j;
	char *word;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	i = 0;
	j = 1;
	word = argv[1];
	while (word[i] != '\0')
	{
		j = 1;
		if (word[i] >= 'A' && word[i] <= 'Z')
			j = word[i] - 64;
		if (word[i] >= 'a' && word[i] <= 'z')
			j = word[i] - 96;
		while (j >= 1)
		{
			write(1, &word[i], 1);
			j--;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}