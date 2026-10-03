#include "bsq.h"

// cc -Wall -Werror -Wextra bsq.c

static int	bad(char c)
{
	return (c < 32 || c > 126);
}

static int	min(int a, int b)
{
	return (a < b ? a : b);
}

static void	free_map(t_map *m, int n)
{
	while (n--)
		free(m->grid[n]);
	free(m->grid);
}

static int	read_map(FILE *f, t_map *m)
{
	char	s[4], *line = NULL;
	size_t	cap = 0;
	ssize_t	len;
	int		r = 0, ok;

	if (fscanf(f, "%d%c%c%c%c%c%c%c", &m->rows, &s[0], &m->empty, &s[1],
			&m->obst, &s[2], &m->full, &s[3]) != 8
		|| s[0] != ' ' || s[1] != ' ' || s[2] != ' ' || s[3] != '\n'
		|| m->rows <= 0 || bad(m->empty) || bad(m->obst) || bad(m->full)
		|| m->empty == m->obst || m->empty == m->full || m->obst == m->full
		|| !(m->grid = calloc(m->rows, sizeof(char *))))
		return (0);
	while (r < m->rows && (len = getline(&line, &cap, f)) > 1
		&& line[--len] == '\n' && (r == 0 || len == m->cols))
	{
		line[len] = '\0';
		m->cols = len;
		while (len-- && (line[len] == m->empty || line[len] == m->obst))
			;
		if (len >= 0)
			break ;
		m->grid[r++] = line;
		line = NULL;
		cap = 0;
	}
	ok = (r == m->rows && getline(&line, &cap, f) < 0);
	free(line);
	if (!ok)
		free_map(m, r);
	return (ok);
}

static int	solve(t_map *m)
{
	int	*dp = calloc(m->cols + 1, sizeof(int));
	int	best = 0, bi = 0, bj = 0, diag, up;

	if (!dp)
		return (0);
	for (int i = 0; i < m->rows; i++)
	{
		diag = 0;
		for (int j = 1; j <= m->cols; j++)
		{
			up = dp[j];
			dp[j] = (m->grid[i][j - 1] == m->obst) ? 0 : min(min(dp[j - 1], up), diag) + 1;
			if (dp[j] > best)
			{
				best = dp[j];
				bi = i;
				bj = j - 1;
			}
			diag = up;
		}
	}
	free(dp);
	for (int i = bi - best + 1; i <= bi; i++)
		for (int j = bj - best + 1; j <= bj; j++)
			m->grid[i][j] = m->full;
	for (int i = 0; i < m->rows; i++)
		fprintf(stdout, "%s\n", m->grid[i]);
	return (1);
}

static void	process(FILE *f)
{
	t_map	m;
	int		ok = f && read_map(f, &m);

	if (ok)
	{
		ok = solve(&m);
		free_map(&m, m.rows);
	}
	if (!ok)
		fputs("map error\n", stderr);
	if (f && f != stdin)
		fclose(f);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		process(stdin);
	for (int i = 1; i < ac; i++)
	{
		if (i > 1)
			fputs("\n", stdout);
		process(fopen(av[i], "r"));
	}
	return (0);
}
