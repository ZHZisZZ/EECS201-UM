CC = gcc
CFLAGS = -g -Wall -std=c99
LIBPLUGINS = $(shell ls | egrep "plugin.*.c" | sed -E -e "s@.c@.so@")

all: runner 

test: runner $(LIBPLUGINS)
	LD_LIBRARY_PATH=./ ./runner $(LIBPLUGINS)

runner: runner.c
	$(CC) $(CFLAGS) -o $@ runner.c -ldl

# pattern rule to turn any source code file that's plugin*.c into plugin*.so
# e.g. $ make plugin1.so
plugin%.so: plugin%.c
	$(CC) $(CFLAGS) -shared -fPIC -o $@ $<

clean:
	rm -f *.so runner

.PHONY: all clean
