all:

clean:
	rm -f neko.inc.c nekosay.S nekosay.o nekosay

# generate a C string literal from the "neko.ascii" ascii art file
neko.inc.c:
	echo "static const char *neko =" > neko.inc.c
	sed -e 's/\\/\\\\/g; s/^\(.*\)$$/"\1\\n"/;' neko.ascii >> neko.inc.c
	echo ";" >> neko.inc.c

# generate assembly using the nekosay C source
# note that nekosay.c includes neko.inc.c
nekosay.S: neko.inc.c
	gcc -g -S -o nekosay.S nekosay.c

# generate object code from the assembly code
nekosay.o: nekosay.S
	as -o nekosay.o nekosay.S

# link (using gcc) the object code into a binary
nekosay: nekosay.o
	@# yeah, using ld on its own can be a bit jank
	@#ld -o nekosay /lib/crt1.o /lib/crti.o /lib/crtn.o nekosay.o -lc
	@#ld -o nekosay -dynamic-linker=/lib64/ld-linux-x86-64.so.2 /lib/crt1.o /lib/crti.o /lib/crtn.o nekosay.o -lc
	gcc -o nekosay nekosay.o

.PHONY: all clean
