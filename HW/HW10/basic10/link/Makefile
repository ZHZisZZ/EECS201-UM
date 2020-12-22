dynamic:
	@# TODO: link by modifying the command below
	gcc -o $@ main.c -L. -lthingy

static:
	@# TODO: link by modifying the command below
	gcc -o $@ main.c -L. -l:libthingy.a

run-dynamic: dynamic
	@LD_LIBRARY_PATH=./ ./dynamic

clean:
	rm -f dynamic static

.PHONY: all clean run-dynamic
