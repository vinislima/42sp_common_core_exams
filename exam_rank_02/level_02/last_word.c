/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:41:20 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/03 19:22:11 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main (int argc, char *argv[])
{
	int	i;
	
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	i = 0;
	while (argv[1][i] != '\0')
		i++;
	i--;
	while ((argv[1][i] == ' ' || argv[1][i] == '\t') && i != 0)
		i--;
	while ((argv[1][i] != ' ' && argv[1][i] != '\t') && i != 0)
		i--;
	if (argv[1][i] == ' ' || argv[1][i] == '\t')
		i++;
	while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')
	{
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
}