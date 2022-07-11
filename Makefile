# Compiler
CC=gcc
CFLAGS=-Wall -Wextra -Wl,--no-as-needed
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
	$(CC) $(CFLAGS) -g $^ -o $(DBG) $(CLINKS) 

# Compile objects to elf
$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(BIN) $(CLINKS) 

# Compile c to objects
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)
# Clean
clean:
	rm -f $(BINDIR)/* $(OBJDIR)/* $(DEBUGDIR)/*
