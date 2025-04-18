/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:01:16 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/18 00:19:59 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	capitalizer(char *s)
{
	int	i = 0;
	
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		if ((s[i] >= 'a' && s[i] <= 'z') && ft_isspace(s[i - 1]))
			s[i] -= 32;
		ft_putchar(s[i++]);
	}
}

int	main(int argc, char *argv[])
{
	int	i = 1;
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (i < argc)
	{
		capitalizer(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}