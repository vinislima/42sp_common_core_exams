/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:12:02 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/06 21:46:14 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	int	i = 0;
	int	lookup[256] = {0};

	while (argv[1][i])
		lookup[(int)argv[1][i++]] = 1;
	i = 0;
	while (argv[2][i])
		lookup[(int)argv[2][i++]] = 1;
	i = 0;
	while (argv[1][i])
	{
		if (lookup[(int)argv[1][i]])
		{
			write(1, &argv[1][i], 1);
			lookup[(int)argv[1][i]] = 0;
		}
		i++;
	}
	i = 0;
	while (argv[2][i])
	{
		if (lookup[(int)argv[2][i]])
		{
			write(1, &argv[2][i], 1);
			lookup[(int)argv[2][i]] = 0;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}