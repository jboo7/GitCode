CC=g++
CFLAGS=-c -Wall -std=c++0x
LDFLAGS=
SOURCES=main.cpp file.cpp folder.cpp afsitem.cpp
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