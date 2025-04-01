/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:51:13 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/01 18:31:44 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	k;
	char	*s1;
	char	*s2;

	i = 0;
	j = 0;
	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];
		while (s1[i] != '\0')
		{
			k = 0;
			while (s2[k] != '\0')
			{
				if (s1[i] == s2[k])
				{
					j = 0;
					while (s1[j] != s1[i])
						j++;
					if (j == i)
					{
						j = 0;
						while (s2[j] != s2[k])
							j++;
						if (j == k)
							write(1, &s1[i], 1);
					}
				}
				k++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}