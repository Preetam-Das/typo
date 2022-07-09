#include "headers.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{

    // check usage
    if (argc != 2) {
        fputs("Usage ./typetest <file-name>\n", stdout);
        exit(0);
    }


    // initializing ncurses
    initscr();
    curs_set(0);
    noecho();
    keypad(stdscr, 1);
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    
    // create windows and load file
    create_windows();
    loadfile(argv[1]);
    scrollok(promptsub, 1);

    // Game functions
    startgame();
    gameloop();

    // endgame
    refresh();
    endwin();
    showresults();
}
