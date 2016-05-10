CC=g++
CFLAGS=-c -Wall
LDFLAGS = -std=c++11
SOURCES=vdetect.cpp Arguments.cpp List_strings.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=vdetect
INCLUDE=
all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(LDFLAGS)  $(CFLAGS) $< -o $@
clean:
	$(RM) $(EXECUTABLE) *.o