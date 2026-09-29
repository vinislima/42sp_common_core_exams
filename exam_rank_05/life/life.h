#ifndef LIFE_H
# define LIFE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	draw(char *b, int w, int h);
void	step(char *b, char *next, int w, int h);
void	print_board(char *b, int w, int h);

#endif
