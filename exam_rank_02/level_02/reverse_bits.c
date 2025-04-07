/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:41:10 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/06 19:03:42 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned int	i;
	unsigned char	res = 0;

	i = 8;
	while (i--)
	{
		res = (res << 1) | (octet & 1);
		octet = octet >> 1;
	}
	return (res);
}

// #include <stdio.h>

// void print_bits(unsigned char octet)
// {
// 	for (int i = 7; i >= 0; i--)
// 		printf ("%c", (octet >> i) & 1 ? '1' : '0');
// }

// int	main(void)
// {
// 	unsigned char a = 0b10100011;
// 	printf("Original: 0b");
// 	print_bits(a);
// 	printf(" (%3u)\n", a);
// 	printf("Reversed: 0b");
// 	print_bits(reverse_bits(a));
// 	printf(" (%3u)\n\n", reverse_bits(a));

// 	unsigned char b = 0b11111111;
// 	printf("Original: 0b");
// 	print_bits(b);
// 	printf(" (%3u)\n", b);
// 	printf("Reversed: 0b");
// 	print_bits(reverse_bits(b));
// 	printf(" (%3u)\n\n", reverse_bits(b));

// 	unsigned char c = 0b10101010;
// 	printf("Original: 0b");
// 	print_bits(c);
// 	printf(" (%3u)\n", c);
// 	printf("Reversed: 0b");
// 	print_bits(reverse_bits(c));
// 	printf(" (%3u)\n\n", reverse_bits(c));

// 	return (0);
// }