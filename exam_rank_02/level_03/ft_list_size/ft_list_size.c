/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:52:05 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/09 23:13:00 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	int	n = 0;

// 	t_list *c = malloc(sizeof(*c));
// 	c->next = 0;
// 	c->data = &n;

// 	t_list *b = malloc(sizeof(*b));
// 	b->next = c;
// 	b->data = &n;

// 	t_list *a = malloc(sizeof(*a));
// 	a->next = b;
// 	a->data = &n;

// 	printf("%d\n", ft_list_size(a));
// 	return (0);
// }
