#include "window.h"

void init_stdscr()
{
    initscr();              /* Most of the below initialisers are */
    noecho();               /* not necessary for this example.    */
    keypad(stdscr, TRUE);   /* It's just a template for a         */
    meta(stdscr, TRUE);     /* hypothetical program that might    */
    nodelay(stdscr, FALSE); /* need them.                         */
    notimeout(stdscr, TRUE);
    raw();
    curs_set(0);
}

WINDOW *create_full_window()
{
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    WINDOW *new_win = newwin(yMax / 2, xMax / 2, yMax / 4, xMax / 4);
    return new_win;
}

WINDOW *create_window(int nlines, int ncols, int begin_y, int begin_x)
{
    // int yMax, xMax;
    // getmaxyx(stdscr, yMax, xMax);
    WINDOW *new_win = newwin(nlines, ncols, begin_y, begin_x);
    return new_win;

}


void endgame(char c)
{
    // Loop forever until user enters 'q'
    while ((c = wgetch(stdscr)) && c != 'q')
    {
        endwin();
    }
}

void draw_borders(WINDOW *screen, const char *c)
{
    int x, y, i;
    getmaxyx(screen, y, x); // 4 corners
    mvwprintw(screen, 0, 0, c);
    mvwprintw(screen, y - 1, 0, c);
    mvwprintw(screen, 0, x - 1, c);
    mvwprintw(screen, y - 1, x - 1, c); // sides
    for (i = 1; i < (y - 1); i++)
    {
        mvwprintw(screen, i, 0, c);
        mvwprintw(screen, i, x - 1, c);
    } // top and bottom
    for (i = 1; i < (x - 1); i++)
    {
        mvwprintw(screen, 0, i, c);
        mvwprintw(screen, y - 1, i, c);
    }
}

