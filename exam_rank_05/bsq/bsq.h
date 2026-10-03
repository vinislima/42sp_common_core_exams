#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obst;
	char	full;
	char	**grid;
}	t_map;

#endif
