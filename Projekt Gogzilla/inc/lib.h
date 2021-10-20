#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <ncurses.h>

typedef struct s_vec2D
{
    int x;
    int y;
} t_vec2D;

FILE* open_file(const char *filename);
void open_ascii_image(WINDOW *window, const char *filename);



#endif
