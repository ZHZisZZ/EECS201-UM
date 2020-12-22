CXX = g++
CXXFLAGS = -g -Iinc -std=c++11

lib/libmat.so: libsrc/matrix.cpp
	mkdir -p lib
	gcc -c -fPIC -o libsrc/matrix.o $< -I ./inc
	gcc -shared -fPIC -o lib/libmylib.so libsrc/matrix.o
	@# TODO build the dynamic library: take note of the target

lib/libmat.a: libsrc/matrix.cpp 
	mkdir -p lib
	gcc -c -o libsrc/matrix.o $< -I ./inc 
	ar rcs lib/libmatrix.a libsrc/matrix.o
	@# TODO build the static library: take note of the target

app-dynamic: main.cpp lib/libmat.so
	@# TODO: link by modifying the command below
	$(CXX) $(CXXFLAGS) -o $@ main.cpp -Llib -lmatrix

app-static: main.cpp lib/libmat.a
	@# TODO: link by modifying the command below
	$(CXX) $(CXXFLAGS) -o $@ main.cpp -Llib -l:libmatrix.a

run-dynamic: app-dynamic
	@LD_LIBRARY_PATH=./lib ./app-dynamic

clean:
	rm -f $(shell find . -name "*.o")
	rm -rf lib
	rm -f app-dynamic
	rm -f app-static

.PHONY: clean run-dynamic
