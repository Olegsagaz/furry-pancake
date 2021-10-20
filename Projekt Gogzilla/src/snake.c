#define _POSIX_C_SOURCE 199309L

#include <curses.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#include "linked_list.h"

enum dir {
    LEFT, DOWN, UP, RIGHT
};

/* global variables */
int width;
int height;
struct node *snk;
int len;
enum dir dir;
int food_x;
int food_y;
bool gameover;

/* initial setup */
void setup(void)
{
    setlocale(LC_ALL, "");
    initscr(); cbreak(); noecho();
    nonl();
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);
    timeout(0);
    curs_set(0);

    getmaxyx(stdscr, height, width);
    width = (width + 1) / 2;

    snk = new_node(width / 2, 0, NULL);
    len = 1;
    dir = DOWN;

    do {
        food_x = rand() % width;
        food_y = rand() % height;
    } while (snk->x == food_x && snk->y == food_y);

    gameover = false;

    srand(time(0));
}

/* listen for key press */
void input(void)
{
    char c = getch();
    if (c == 'a' && (dir != RIGHT || len == 1))
        dir = LEFT;
    else if (c == 's' && (dir != UP || len == 1))
        dir = DOWN;
    else if (c == 'w' && (dir != DOWN || len == 1))
        dir = UP;
    else if (c == 'd' && (dir != LEFT || len == 1))
        dir = RIGHT;
    else if (c == 'q')
        gameover = true;
}

/* move snake, check for collision, handle food */
void logic(void)
{
    switch (dir) {
    case LEFT:
        snk = new_node(snk->x - 1, snk->y, snk);
        break;
    case DOWN:
        snk = new_node(snk->x, snk->y + 1, snk);
        break;
    case UP:
        snk = new_node(snk->x, snk->y - 1, snk);
        break;
    case RIGHT:
        snk = new_node(snk->x + 1, snk->y, snk);
        break;
    default:
        break;
    }

    if (snk->x < 0)
        snk->x = width - 1;
    else if (snk->x >= width)
        snk->x = 0;
    else if (snk->y < 0)
        snk->y = height - 1;
    else if (snk->y >= height)
        snk->y = 0;

    if (node_exists(snk->next, snk->x, snk->y))
        gameover = true;

    if (snk->x == food_x && snk->y == food_y) {
        do {
            food_x = rand() % width;
            food_y = rand() % height;
        } while (node_exists(snk, food_x, food_y));
        ++len;
    } else {
        delete_last(snk);
    }
}

/* draw the snake and the food */
void draw(void)
{
    clear();
    struct node *cursor = snk;
    while (cursor != NULL) {
        mvprintw(cursor->y, cursor->x * 2, "o");
        cursor = cursor->next;
    }
    mvprintw(food_y, food_x * 2, "+");
    refresh();
}

// int main(void)
// {
//     setup();

//     while (!gameover) {
//         input();
//         logic();
//         draw();

//         struct timespec ts;
//         ts.tv_sec = 0;
//         ts.tv_nsec = 100000000;
//         nanosleep(&ts, &ts);
//     }

//     endwin();
//     return EXIT_SUCCESS;
// }
