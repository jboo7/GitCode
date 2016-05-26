CC=g++
CFLAGS=-c -Wall -std=c++0x -g
LDFLAGS=
SOURCES=main.cpp aitem.cpp file.cpp folder.cpp findvisitor.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main.exe

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	del *.exe
	del *.o