#ifndef GAME_H
#define GAME_H

#include <time.h>

/** gamerunning is 1 when game is running else 0.
ch is the typed input character. start is used for
keeping track of time in the game.
total_time is the total time required to finish the game. **/

extern int gamerunning;
extern int ch;
extern time_t start;
extern double total_time;

// gameloop is the main gameloop. showresults show the results
// at the end of the game. startgame initializes game and is also 
// used for pausing the game.

void gameloop();
void showresults();
void startgame();

// stackoverflow - handling ctrl <key> press
#define ctrl(x) ((x) & 0x1f) 

#endif