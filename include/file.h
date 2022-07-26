#ifndef FILE_H
#define FILE_H

/** buffer contains the text of the file read.
buffersize is the no. of characters/bytes read. **/

extern char *buffer;
extern unsigned int buffersize;

// load file to prompt window
void loadfile(char *filename);

//check if file exists or if it's empty
void checkfile(char *filename);

#endif
