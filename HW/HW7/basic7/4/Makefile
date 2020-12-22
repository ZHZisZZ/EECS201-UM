CC = gcc
BIN = sum30
SRCDIR = src
# SRCS = $(shell find $(SRCDIR) -name "*.c")
SRCS = $(wildcard $(SRCDIR)/*.c) 

all: $(SRCS)
	$(CC) -o $(BIN) $^

clean:
	rm -rf $(BIN)

.PHONY: all clean