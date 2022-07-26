#include "headers.h"
#include <stdlib.h>

// declarations
char *buffer = NULL;
unsigned int buffersize = 0;

// load file to prompt window
void loadfile(char *filename)
{
    FILE *file = fopen(filename, "rb");

    char *tempbuffer;
    unsigned int tempbufsize;
    
    // stackoverflow soln to read a file
    fseek(file, 0L, SEEK_END);
    buffersize = ftell(file);
    tempbufsize  = buffersize;
    checkarray = calloc(1, buffersize/__CHAR_BIT__);
    rewind(file);

    if (buffer == NULL)
        buffer = calloc(1, buffersize);

    fread(buffer, 1, tempbufsize, file);
    tempbuffer = buffer;
    fclose(file);

    char ch;
    // load file to promptsub window
    while(tempbufsize-- != 0) {
        ch = *tempbuffer++;
        if (ch == '\n' || ch == '\r' || ch == '\t') {
            ch = ' ';
            *(tempbuffer - 1) = ch;
        }
        waddch(promptsub, ch);
        refresh();
        wrefresh(promptsub);
    }

    // move cursor to the begginning of the window
    wmove(promptsub, 0, 0);
}
