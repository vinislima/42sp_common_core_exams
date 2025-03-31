/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:39:14 by vinda-si          #+#    #+#             */
/*   Updated: 2025/03/31 18:53:09 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	n1, n2, res;
	
	n1 = 0;
	n2 = 0;
	res = 0;
	
	if (argc == 4)
	{
		n1 = atoi(argv[1]);
		n2 = atoi(argv[3]);
		if (argv[2][0] == '+')
			res = n1 + n2;
		else if (argv[2][0] == '-')
			res = n1 - n2;
		else if (argv[2][0] == '*')
			res = n1 * n2;
		else if (argv[2][0] == '%')
			res = n1 % n2;
		printf("%d\n", res);
	}
	else
		write(1, "\n", 1);
	return (0);
}