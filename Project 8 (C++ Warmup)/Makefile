CXX = g++
CXXFLAGS = -g --std=c++11

SOURCES += StringPlusPlus.cpp
SOURCES += Proj8Test.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)
BIN = proj8_test

%.o:%.cpp
	echo $(SOURCES)
	$(CXX) $(CXXFLAGS) -c $< -o $(@)

$(BIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(@) $(OBJECTS)

all: #(BIN)

clean:
	rm -f $(BIN)
	rm -f $(OBJECTS)

test: $(BIN)
	./$(BIN)

debug: $(BIN)
	gdb ./$(BIN)

mem: $(BIN)
	valgrind --leak-check=full ./$(BIN)

.PHONY: clean test mem
