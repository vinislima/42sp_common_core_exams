/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:58:34 by vinda-si          #+#    #+#             */
/*   Updated: 2025/03/27 20:43:45 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(void)
{
	int i = 0;
	char *str = "tEsTe";

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			i -= 'a';
			write()
		}	
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'A';
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}