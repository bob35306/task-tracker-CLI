
CC = g++
CFLAGS = -Wall -Wextra -std=c++17

SOURCES = src/cli.cpp src/main.cpp src/utils.cpp src/exception.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = task-cli

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)