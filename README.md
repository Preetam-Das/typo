# typo
A ncurses based simple typing game.

Currently typo is able to read a file and use it as a test file for the user to test his typing speed. Typo shows correctly typed characters in green and wrongly typed characters in red. At the end of the game it shows the total no. of typed characters, the no. of characters typed correctly and the total time taken.

The program should work on on unix and (linux) unix-like based operating systems. It may or may not work on windows (haven't checked it yet) provided that the dependencies are correctly installed.

# Installation
To install:
```
chmod +x setup.sh
./setup.sh
```

To uninstall: ``make uninstall`` or with sudo privileges ``sudo make uninstall``.

To get rid of the compiled file: ``make clean``.

# Running
Usage: ``typo <file-name>``.

# Features to implement
1. Show the words per second(wps) at the output.
2. Highlight the currently typed word in yellow.
3. Show the time passed on the screen.
4. Implement a built-in dictionary feature which will have many most commonly words used so that the user doesn't have to find a test file on his own.
5. Improve UI.
6. Show more statistics at output.
7. Add functionality to disbale backspace.
8. Improve ignoring whitespaces, tabs, and newlines.
9. ...
