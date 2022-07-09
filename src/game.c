#include "headers.h"

// globals declarations
int gamerunning = 0;
int ch;
time_t start = -1;
double total_time = 0;

// used for starting and pausing the game
void startgame()
{
    // write start message
    move(LINES - 1, 0);
    clrtoeol();
    printw("Press Enter to start.");
    refresh();

    // if not starting for the first time pause the clock
    if (start != -1)
        total_time += (double) (time(NULL) - start);
    // pause the game
    gamerunning = 0;
    while(!gamerunning) {
        ch = getch();
        if (ch == KEY_RESIZE || ch == ctrl('r')) {
            move(0, 0);
            clrtobot();
            refresh();

            delwin(root);
            delwin(prompt);
            delwin(input);
            delwin(promptsub);
            delwin(inputsub);
            refresh();

            create_windows();
            reloadbuffer();

            move(LINES - 1, 0);
            clrtoeol();
            printw("Press Enter to start.");
            refresh();
        }
        if (ch == KEY_ENTER || ch == '\n' || ch == 10) {
            // start game and write stop message
            gamerunning = 1;
            move(LINES - 1, 0);
            clrtoeol();
            printw("Press ctrl+x to stop.");
            refresh();        
            start = time(NULL);
        }
    }
}

// main gameloop
void gameloop()
{
    while(gamerunning){
        
        // if window too small
        if (root->_maxx <= 50 || root->_maxy <= 20) {

            clear_windows();

            move(LINES/2, COLS/2 - 18);
            printw("Window too small. Resize to continue.");
            refresh();
            wrefresh(root);
        }

        // handle inputs
        switch((ch = getch())) {

            // handle resize
            case ctrl('r'):
            case KEY_RESIZE:
                move(0, 0);
                clrtobot();
                refresh();

                delwin(root);
                delwin(prompt);
                delwin(input);
                delwin(promptsub);
                delwin(inputsub);
                refresh();

                create_windows();
                reloadbuffer();
                startgame();
                break;
            case ctrl('x'):
                gamerunning = 0;
                break;

            // handle backspace
            case KEY_BACKSPACE:
            case '\b':
            case 127:
                backspacehandler();
                break;

            // default show and checkinput
            default:
                if (curpos >= buffersize - 1)
                    break;
                showinput(ch);
                checkinput(ch);
                break;
        }

    }
}

// show result on endgame
void showresults()
{
    // calculate total time
    total_time += (double) (time(NULL) - start);
    // calculate correctly typed characters
    int correct = 0;
    for (unsigned int i = 0; i < buffersize - 1; i++) {
        if ((1 << (i % __CHAR_BIT__)) & checkarray[i/__CHAR_BIT__])
            correct++;
    }

    // print results
    printf("Total typed characters: %d\n", curpos);
    printf("Total correct characters: %d\n", correct);
    printf("Time taken: %.0f seconds.\n", total_time);

}