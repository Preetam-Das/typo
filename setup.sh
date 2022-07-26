#!/bin/bash

if [ -x "$(command -v apt-get)" ]; then
	printf "apt package manager detected.\nInstalling packages\n"
	sudo apt-get install gcc make libncurses5-dev libncursesw5-dev -y
elif [ -x "$(command -v pacman)" ]; then
	printf "pacman package manager detected.\nInstalling packages\n"
	sudo pacman -S gcc make ncurses
else
	printf "Package manager not found. Read README.md for installation instructions\n">&2
	exit 1; fi

sudo make install
cp bin/typo .
printf "\nInstallation Complete! Usage: typo <filename>\n"
exit 0
