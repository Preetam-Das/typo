# Compiler
CC=gcc
CFLAGS=-Wall -Wextra
LDFLAGS=-Wl,--no-as-needed
CLINKS=-lncurses

# Directories
SRCDIR=src
INCDIR=include
OBJDIR=obj
BINDIR=bin
DEBUGDIR=debug

# Files
SRC=$(wildcard $(SRCDIR)/*.c)
BIN=$(BINDIR)/typo
DBG=$(DEBUGDIR)/typo
OBJ=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# install
install: all
	cp $(BIN) /usr/bin/

# uninstall
uninstall:
	rm /usr/$(BIN)

# all
all: dir $(BIN)
debug: dir $(DBG)

# Directory structure
dir:
	mkdir -p $(SRCDIR) $(INCDIR) $(OBJDIR) $(BINDIR)

# Debug build
$(DBG): $(OBJ)
	mkdir -p $(DEBUGDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -g $^ -o $(DBG) $(CLINKS) 

# Compile objects to elf
$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $(BIN) $(CLINKS) 

# Compile c to objects
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)
# Clean
clean:
	rm -rf $(BINDIR) $(OBJDIR) $(DEBUGDIR)
