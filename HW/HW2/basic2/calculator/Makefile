CC=gcc
LD=ld
CFLAGS=-g

SRCDIR=src
INCLUDE=inc
OBJDIR=obj

SOURCES=$(wildcard $(SRCDIR)/*.c)
OBJECTS=$(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
BIN=calculate

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	mkdir -p $(@D) # generate the directory
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $(@)

$(BIN): $(OBJECTS)
	$(CC) $(CFLAGS) -I $(INCLUDE) -o $(BIN) $(OBJECTS)

all: $(BIN)

clean:
	rm -rf $(BIN) $(OBJDIR)

.PHONY: all clean
