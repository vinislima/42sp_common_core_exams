/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:58:34 by vinda-si          #+#    #+#             */
/*   Updated: 2025/03/27 23:32:56 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	
	int i = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
		{
			argv[1][i] = argv[1][i] - 32;
			write(1, &argv[1][i], 1);
		}
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			argv[1][i] = argv[1][i] + 32;
			write(1, &argv[1][i], 1);
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}