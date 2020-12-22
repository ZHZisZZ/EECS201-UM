CXX = g++
BIN = app
INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj
SOURCES = $(shell find $(SRC_DIR) -name "*.cpp")
# src/*.cpp -> obj/*.o
OBJECTS := $(subst src,obj,$(SOURCES:%.cpp=%.o)) 
# obj/path/*.o -> obj/path
OBJ_PATH = $(dir $(OBJECTS))

all: gendir $(OBJECTS) 
	$(CXX) -o $(BIN) $(OBJECTS)

# implicit rules 
obj/%.o: src/%.cpp
	$(CXX) -c -o $@ $< -I $(INC_DIR)

# generate object file directory
gendir:
	mkdir -p $(OBJ_PATH)

# clean
clean:
	rm -rf $(OBJ_DIR) $(BIN)

.PHONY: all clean



