#include "bsq.h"

// cc -Wall -Werror -Wextra bsq.c

static int	bad(char c)
{
	return (c < 32 || c > 126);
}

void	free_map(t_map *map, int rows)
{
	while (rows--)
		free(map->grid[rows]);
	free(map->grid);
}

int	read_map(FILE *f, t_map *map)
{
	char	*line = NULL;
	size_t	cap = 0;
	ssize_t	len;
	int		r = 0;
	int		ok;

	map->cols = 0;
	if (fscanf(f, "%d %c %c %c\n", &map->rows, &map->empty, &map->obstacle, &map->full) != 4
		|| map->rows <= 0 || map->empty == map->obstacle || map->empty == map->full
		|| map->obstacle == map->full || bad(map->empty) || bad(map->obstacle) || bad(map->full)
		|| !(map->grid = calloc(map->rows, sizeof(char *))))
		return (0);
	while (r < map->rows && (len = getline(&line, &cap, f)) > 0)
	{
		if (line[len - 1] == '\n')
			line[--len] = '\0';
		if (len == 0 || (r > 0 && len != map->cols))
			break ;
		map->cols = len;
		for (int j = 0; j < map->cols; j++)
			if (line[j] != map->empty && line[j] != map->obstacle)
				len = -1;
		if (len < 0)
			break ;
		map->grid[r++] = line;
		line = NULL;
		cap = 0;
	}
	ok = (r == map->rows && getline(&line, &cap, f) == -1);
	free(line);
	if (!ok)
		free_map(map, r);
	return (ok);
}

int	solve(t_map *map)
{
	int	*dp = calloc(map->cols + 1, sizeof(int));
	int	best = 0, bi = 0, bj = 0, diag, up;

	if (!dp)
		return (0);
	for (int i = 0; i < map->rows; i++)
	{
		diag = 0;
		for (int j = 0; j < map->cols; j++)
		{
			up = dp[j + 1];
			if (map->grid[i][j] == map->obstacle)
				dp[j + 1] = 0;
			else
			{
				dp[j + 1] = (dp[j] < up ? dp[j] : up);
				dp[j + 1] = (diag < dp[j + 1] ? diag : dp[j + 1]) + 1;
			}
			if (dp[j + 1] > best)
			{
				best = dp[j + 1];
				bi = i;
				bj = j;
			}
			diag = up;
		}
	}
	for (int i = bi - best + 1; i <= bi; i++)
		for (int j = bj - best + 1; j <= bj; j++)
			map->grid[i][j] = map->full;
	free(dp);
	return (1);
}

void	process(FILE *f)
{
	t_map	map;

	if (!f || !read_map(f, &map))
	{
		fputs("map error\n", stderr);
		return ;
	}
	if (solve(&map))
		for (int i = 0; i < map.rows; i++)
			fprintf(stdout, "%s\n", map.grid[i]);
	else
		fputs("map error\n", stderr);
	free_map(&map, map.rows);
}

int	main(int ac, char **av)
{
	FILE	*f;

	if (ac < 2)
		process(stdin);
	for (int i = 1; i < ac; i++)
	{
		if (i > 1)
			fputs("\n", stdout);
		f = fopen(av[i], "r");
		process(f);
		if (f)
			fclose(f);
	}
	return (0);
}
