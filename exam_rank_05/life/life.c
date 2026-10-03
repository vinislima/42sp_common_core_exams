#include "life.h"

// cc -Wall -Werror -Wextra life.c

static void	draw(char *b, int w, int h)
{
	int		x = 0, y = 0, pen = 0;
	char	c;

	while (read(0, &c, 1) > 0)
	{
		if (c == 'x')
			pen = !pen;
		else if (c == 'w' && y > 0)
			y--;
		else if (c == 's' && y < h - 1)
			y++;
		else if (c == 'a' && x > 0)
			x--;
		else if (c == 'd' && x < w - 1)
			x++;
		if (pen)
			b[y * w + x] = 1;
	}
}

// n conta o bloco 3x3 inteiro, incluindo a propria celula:
// viva com 2 ou 3 vizinhas -> n == 3 ou 4; morta com 3 vizinhas -> n == 3
static void	step(char *b, char *next, int w, int h)
{
	int	n;

	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
		{
			n = 0;
			for (int i = y - 1; i <= y + 1; i++)
				for (int j = x - 1; j <= x + 1; j++)
					if (i >= 0 && i < h && j >= 0 && j < w)
						n += b[i * w + j];
			next[y * w + x] = (n == 3 || (n == 4 && b[y * w + x]));
		}
}

int	main(int ac, char **av)
{
	int		w, h, it;
	char	*b, *next, *tmp;

	if (ac != 4 || (w = atoi(av[1])) <= 0 || (h = atoi(av[2])) <= 0
		|| (it = atoi(av[3])) < 0 || h > 2147483647 / w)
		return (1);
	b = calloc(w * h, 1);
	next = calloc(w * h, 1);
	if (!b || !next)
		return (free(b), free(next), 1);
	draw(b, w, h);
	while (it--)
	{
		step(b, next, w, h);
		tmp = b;
		b = next;
		next = tmp;
	}
	for (int i = 0; i < w * h; i++)
	{
		putchar(b[i] ? '0' : ' ');
		if (i % w == w - 1)
			putchar('\n');
	}
	free(b);
	free(next);
	return (0);
}
