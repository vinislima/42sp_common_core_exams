/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:28:56 by vinda-si          #+#    #+#             */
/*   Updated: 2025/03/28 17:43:05 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(void)
{
	int	i;
	int dif;
	int calc;
	char word[] = "teste";

	i = 0;
	while (word[i] != '\0')
	{
		dif = 0;
		calc = 0;
		if (word[i] >= 'a' && word[i]<= 'z')
		{
			dif = word[i] - 66;
			while (dif >= )
		}
	}
}