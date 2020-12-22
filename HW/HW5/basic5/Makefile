CXX=g++
LD=ld
CXXFLAGS=-g -std=c++11

SRCDIR=src
INCLUDE=inc
OBJDIR=obj

SOURCES=$(wildcard $(SRCDIR)/*.cpp)
OBJECTS=$(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
BIN=memetext

$(OBJDIR)/%.o:$(SRCDIR)/%.cpp
	mkdir -p $(@D) # generate the directory
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) -c $< -o $(@)

$(BIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) -o $(BIN) $(OBJECTS)

all: $(BIN)

clean:
	rm -rf $(BIN) $(OBJDIR)

.PHONY: all clean
