#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

void init_stdscr();
WINDOW *create_window(int nlines, int ncols, int begin_y, int begin_x);
void endgame(char c);
void draw_borders(WINDOW *screen, const char *c);


#endif
