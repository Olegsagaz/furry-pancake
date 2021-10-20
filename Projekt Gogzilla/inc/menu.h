#ifndef MENU_H
#define MENU_H

#include <ncurses.h>
#include <string.h>

int print_menu (int sty, int x, int alts, unsigned long width, char title[], char entries[][100], int start);


#endif
