CXX = g++
CXXFLAGS = -g --std=c++11 -Wall -Wextra -fpermissive

SOURCES += EvilHangmanGame.cpp
SOURCES += RunEvilHangman.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)

BIN = evil_hangman

DICT = dictionary.txt
LENGTH = 4
GUESSES = 5

%.o:%.cpp
	echo $(SOURCES)
	$(CXX) $(CXXFLAGS) -c $< -o $(@)

$(BIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(@) $(OBJECTS)

all: $(BIN)

clean:
	rm -f $(BIN)
	rm -f $(OBJECTS)

test: $(BIN)
	./$(BIN) $(DICT) $(LENGTH) $(GUESSES)

debug: $(BIN)
	gdb --args ./$(BIN) $(DICT) $(LENGTH) $(GUESSES)

mem: $(BIN)
	valgrind --leak-check=full ./$(BIN) $(DICT) $(LENGTH) $(GUESSES)

.PHONY: clean test debug mem
