#include "windows.h"
#include <ncurses.h>
#include <stdlib.h>

// windows definition
WINDOW *root;
WINDOW *prompt;
WINDOW *input;
WINDOW *promptsub;
WINDOW *inputsub;

// creates windows
void create_windows()
{
    // root window params
    int rx, ry, rh, rw;
    rh = LINES - 2;
    rw = COLS - 2;
    rx = 1; 
    ry = 1;

    // create root
    root = newwin(rh, rw, ry, rx);
    // box(root, 0, 0);
    refresh();
    wrefresh(root);

    // prompt window params
    int px, py, ph, pw;
    ph = root->_maxy - 4;
    pw = root->_maxx - 2;
    px = 1;
    py = 1;

    // create prompt
    prompt = derwin(root, ph, pw, py, px);
    box(prompt, 0, 0);
    mvwprintw(prompt, 0, 1, "[ %s ]", "Propmt");
    refresh();
    wrefresh(prompt);

    // input window params
    int ix, iy, ih, iw;
    ih = 3;
    iw = 30;
    iy = prompt->_maxy + 2;
    ix = root->_maxx/2 - iw/2;

    // create input
    input = derwin(root, ih, iw, iy, ix);
    box(input, 0, 0);
    mvwprintw(input, 0, 1, "[ %s ]", "Input");
    refresh();
    wrefresh(input);

    // create promptsub
    promptsub = derwin(prompt, ph - 2, pw - 2, 1, 1);
    // box(promptsub, 0, 0);
    refresh();
    wrefresh(promptsub);

    // create inputsub
    inputsub = derwin(input, ih - 2, iw - 2, 1, 1);
    // box(inputsub, 0, 0);
    refresh();
    wrefresh(inputsub);

}

// clear windows
void clear_windows()
{
    wclear(root);
    wclear(prompt);
    wclear(input);
    refresh();
    wrefresh(root);
    wrefresh(prompt);
    wrefresh(input);
    wrefresh(promptsub);
    wrefresh(inputsub);
}