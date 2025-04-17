/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:20:45 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/17 19:45:03 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nbr)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	char c = nbr % 10 + '0';
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	(void) argv;
	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}
