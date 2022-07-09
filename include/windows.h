#ifndef WINDOWS_H
#define WINDOWS_H

#include <ncurses.h>

/** Declaration of various windows and related functions.
Root is the main invisible window whose size changes
according to the terminal size.
promp and input are derived windows of root. the '-sub'
windows are the windows containing actual text which are
derived from their respective parent window. **/

extern WINDOW *root;
extern WINDOW *prompt;
extern WINDOW *input;
extern WINDOW *promptsub;
extern WINDOW *inputsub;

// create_windows creates the respective windows.
// clear_windows clears the contents of all the windows.

void create_windows();
void clear_windows();

#endif