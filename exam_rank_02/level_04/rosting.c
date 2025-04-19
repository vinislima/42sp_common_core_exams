/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rosting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 22:32:01 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/18 23:49:16 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	char	*s = argv[1];
	int		i = 0;
	int		start, len;
	int		flag = 0;

	while (s[i] == ' ' || s[i] == '\t')
		i++;
	start = i;
	
	while (s[i] && s[i] != ' ' && s[i] != '\t')
		i++;
	len = i - start;

	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while(s[i])
	{
		if (flag)
			write(1, " ", 1);
		while (s[i] && s[i] != ' ' && s[i] != '\t')
			write (1, &s[i++], 1);
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		flag = 1;
	}
	if (flag)
		write(1, " ", 1);
	write(1, s + start, len);
	write (1, "\n", 1);
	return (0);
}