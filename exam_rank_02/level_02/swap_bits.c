/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:46:04 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/06 21:03:10 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4 | octet << 4));
}

// #include <stdio.h>
// #include <stdlib.h>

// unsigned char swap_bits(unsigned char octet);

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 	{
// 		printf("Uso: %s <valor_entre_0_e_255>\n", argv[0]);
// 		return (1);
// 	}

// 	unsigned char octet = (unsigned char)atoi(argv[1]);

// 	unsigned char result = swap_bits(octet);

// 	printf("Original: %3u → 0b", octet);
// 	for (int i = 7; i >= 0; i--) printf("%d", (octet >> i) & 1);
// 	printf("\nResultado: %3u → 0b", result);
// 	for (int i = 7; i >= 0; i--) printf("%d", (result >> i) & 1);
// 	printf("\n");

// 	return (0);
// }