#include "headers.h"
#include <time.h>

// declarations
unsigned int curpos = 0;
char *checkarray;

// show input to inputsub
void showinput(int ch)
{
    // ignore escape sequences
    if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r')
        wclear(inputsub);
    else
        waddch(inputsub, ch);
    refresh();
    wrefresh(inputsub);
}

// paints window and updates checkarray according to input
void checkinput(int ch)
{
    wattron(promptsub, A_UNDERLINE);
    // if correctly typed
    if (ch == buffer[curpos]) {
        wattron(promptsub, COLOR_PAIR(1));
        checkarray[curpos/__CHAR_BIT__] |= 1 << (curpos % __CHAR_BIT__); 
    }
    // if backspace (not required)
    else if (ch == KEY_BACKSPACE || ch == '\b' || ch == 127) {
        backspacehandler();
    }
    // if typed wrong
    else { 
        wattron(promptsub, COLOR_PAIR(2));
    }

    // disable outputs
    waddch(promptsub, buffer[curpos]);
    wattroff(promptsub, COLOR_PAIR(1));
    wattroff(promptsub, COLOR_PAIR(2));
    wattroff(promptsub, A_UNDERLINE);
    refresh();
    wrefresh(promptsub);
    // update curpos
    curpos++;
}

// reload buffer on resize
void reloadbuffer()
{
    // clear prompt window
    wclear(promptsub);
    refresh();
    wrefresh(promptsub);

    wmove(promptsub, 0, 0);

    // reloading buffer according to the checkarray 
    wattron(promptsub, A_UNDERLINE);
    unsigned long i = 0;
    for (i = 0; i < curpos && i < buffersize; i++) {
        // if the bit is set then color green else color red
        if ((1 << (i % __CHAR_BIT__)) & checkarray[i/__CHAR_BIT__]) {
            wattroff(promptsub, COLOR_PAIR(2));
            wattron(promptsub, COLOR_PAIR(1));
        }
        else {
            wattroff(promptsub, COLOR_PAIR(1));
            wattron(promptsub, COLOR_PAIR(2));
        }
        waddch(promptsub, buffer[i]);
    }

    int cury = 0, curx = 0;

    // get the curosor position
    getyx(promptsub, cury, curx);
    wattroff(promptsub, A_UNDERLINE);
    wattroff(promptsub, COLOR_PAIR(1));
    wattroff(promptsub, COLOR_PAIR(2));

    // printing remaining characters
    while (i < buffersize) {
        waddch(promptsub, buffer[i++]);
        refresh();
        wrefresh(promptsub);
    }

    // move to last typed position
    wmove(promptsub, cury, curx);
    // resetting scroll
    scrollok(promptsub, TRUE);
}

// handle backspace
void backspacehandler()
{
    wattroff(promptsub, A_UNDERLINE);
    int x, y, backchar;
    // moving cursor
    getyx(promptsub, y, x);
    // if at the starting pos do nothing
    if (x == 0 && y == 0)
        return;
    // if at first col move to last line
    if (x == 0) {
        wmove(promptsub, y - 1, promptsub->_maxx);
        getyx(promptsub, y, x);
        backchar = winch(promptsub) & A_CHARTEXT;
        waddch(promptsub, backchar);
        wmove(promptsub, y, x);
        refresh();
        wrefresh(promptsub);
    }
    else {
        waddch(promptsub, '\b');
        backchar = winch(promptsub) & A_CHARTEXT;
        waddch(promptsub, backchar);
        waddch(promptsub, '\b');
        refresh();
        wrefresh(promptsub);
    }

    // for input window
    getyx(inputsub, y, x);
    wmove(inputsub, y, x - 1);
    waddch(inputsub, ' ');
    wmove(inputsub, y, x - 1);
    refresh();
    wrefresh(inputsub);

    // update curpos and checkarray
    curpos--;
    checkarray[curpos/__CHAR_BIT__] &= ~(1 << (curpos % __CHAR_BIT__)); 
}
