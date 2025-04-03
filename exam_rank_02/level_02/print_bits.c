/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:35:35 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/03 21:04:02 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char	bit = 0;

	while(i--)
	{
		bit = (octet >> i & 1) + 48;
		write (1, &bit, 1);
	}
}

// int	main(void)
// {
// 	unsigned char	octet = 10;
// 	print_bits(octet);
// 	write(1, "\n", 1);
//	
// 	return (0);
// }