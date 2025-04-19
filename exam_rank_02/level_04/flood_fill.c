/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:31:18 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/19 01:11:30 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_point
{
		int	x;
		int	y;
}		t_point;

static void fill(char **tab, t_point size, int x, int y, char target)
{
	if (x < 0 || x >= size.x || y < 0 || y >= size.y || tab[y][x] != target)
		return;
	tab[y][x] = 'F';
	fill(tab, size, x + 1, y, target);
	fill(tab, size, x - 1, y, target);
	fill(tab, size, x, y + 1, target);
	fill(tab, size, x, y - 1, target);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y)
		return;
	char	target = tab[begin.y][begin.x];
	if (target == 'F')
		return;
	fill(tab, size, begin.x, begin.y, target);

}

#include <stdlib.h>
#include <stdio.h>

char** make_area(char** zone, t_point size) {
	char** new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i) {
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}
	return new;
}

void print_area(char **area, t_point size) {
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
}

int main() {
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};
	char **area = make_area(zone, size);
	t_point begin = {7, 4};

	printf("Antes:\n");
	print_area(area, size);
	flood_fill(area, size, begin);
	printf("\nDepois:\n");
	print_area(area, size);

	for (int i = 0; i < size.y; ++i) free(area[i]);
	free(area);

	return 0;
}