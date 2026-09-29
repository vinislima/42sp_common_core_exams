#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
}	t_map;

void	free_map(t_map *map, int rows);
int		read_map(FILE *f, t_map *map);
int		solve(t_map *map);
void	process(FILE *f);

#endif
