#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused"

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "window.h"
#include "menu.h"
#include <locale.h>
#include "godzilla.h"
#include "lib.h"
#include <time.h>
#include "fx.h"

int main()
{
    char c = 'A';

    init_stdscr();
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
 
    WINDOW *title = create_window(9, xMax, 0, 0);

    open_ascii_image(title, "title.txt");
    box(title, 0, 0);
    wgetch(title);
    WINDOW *menu = create_window(yMax - 9, xMax / 2, 9, 0);
    box(menu, 0, 0);
    wgetch(menu);
    WINDOW *art = create_window(yMax - 9, xMax / 2, 9, xMax / 2);
    open_ascii_image(art, "GodzillaA4.txt");
    box(art, 0, 0);
    wgetch(art);
    

    // int menu_ret = 1, menu_ret2 = 1;
    // char alts[][100] = {{"Start Game"},     /* Every menu needs an */
    //                      {"Load Game"},     /* array like these to */
    //                      {"Quit Game"},};   /* hold the entries.   */
    // char alts2[][100] = {{"Slot 1"},
    //                      {"Slot 2"},
    //                      {"Slot 3"},
    //                      {"Return"},};

    // setlocale (LC_CTYPE, "");

    // initscr();                  /* Most of the below initialisers are */
    // noecho();                   /* not necessary for this example.    */
    // keypad (stdscr, TRUE);      /* It's just a template for a         */
    // meta (stdscr, TRUE);        /* hypothetical program that might    */
    // nodelay (stdscr, FALSE);    /* need them.                         */
    // notimeout (stdscr, TRUE);
    // raw();
    // curs_set (0);

    // do  /* This loop terminates when MAIN MENU returns 3, Quit Game.   */
    // {   /* menu_ret is sent as the start value, to make the last entry */
    //     /* highlighted when you return to the main menu.               */
    //     menu_ret = print_menu (2, 5, 3, 15,
    //                             "MAIN MENU", alts, menu_ret);

    //     if (menu_ret == 1)  /* This is just an example program. */
    //     {                   /* You can't start an actual game.  */
    //         system("clear");
    //     }

    //     else if (menu_ret == 2) /* If you select load game, a new    */
    //     {                       /* menu will show up without erasing */
    //         do                  /* the main menu. */
    //         {
    //             menu_ret2 = print_menu (6, 22, 4, 15,
    //                                     "SELECT SLOT", alts2, 1);
    //         }
    //         while (menu_ret2 != 4);
    //     }

    //     erase();    /* When you return from the SELECT SLOT menu,      */
    // }               /* everything will be erased and MAIN MENU will be */
    // while (menu_ret != 3); /* reprinted.                               */

    // endwin();

    // endgame(c);
    return 0;
}
