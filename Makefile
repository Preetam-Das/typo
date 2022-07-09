# Compiler
CC=gcc
CFLAGS=-Wall -Wextra
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
DBG=$(DEBUGDIR)/main
OBJ=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# Directory structure
dir:
	mkdir -p $(SRCDIR) $(INCDIR) $(OBJDIR) $(BINDIR) $(DEBUGDIR)

# all
all: dir $(BIN)
debug: $(DBG)

# Debug build
$(DBG): $(OBJ)
	$(CC) $(CFLAGS) $(CLINKS) -g $^ -o $(DBG)

# Compile objects to elf
$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(CLINKS) $^ -o $(BIN)

# Compile c to objects
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)
# Clean
clean:
	rm -f $(BINDIR)/* $(OBJDIR)/* $(DEBUGDIR)/*
