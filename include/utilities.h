#ifndef UTILITEIS_H
#define UTILITIES_H

#include <time.h>

/** curpos keeps track of the current typed character.
checkarray is a bitfield which tracks the correctly
typed characters. Initially checkarray is all 0's.
A bit gets updated to 1 if the corresponding character 
is typed correctly. **/

extern unsigned int curpos;
extern char *checkarray;


/** checkinput checks the input and paints the window accordingly.
It also updates the checkarray if a correct character is typed.
showinput shows the input character typed in the input window.
reloadbuffer reloads the promptsub window if the window is resized
or resize signal is sent. backspacehandler handles the input if it
is a backspace. **/

void checkinput();
void showinput();
void reloadbuffer();
void backspacehandler();

#endif