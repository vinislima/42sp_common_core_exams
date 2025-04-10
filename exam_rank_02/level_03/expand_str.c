/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:44:19 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/09 22:59:18 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	int	i = 0;
	int	space = 0;

	while (is_space(argv[1][i]))
		i++;
	while (argv[1][i])
	{
		if (is_space(argv[1][i]))
			space = 1;
		if (!is_space(argv[1][i]))
		{
			if (space)
				write(1, "   ", 3);
			space = 0;
			ft_putchar(argv[1][i]);
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}