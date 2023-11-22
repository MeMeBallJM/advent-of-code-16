CC=clang

CFLAGS=-Wall
OBJECTS = main.o

all: prog

prog: $(OBJECTS)
	$(CC) $(OBJECTS) -o program
%.o: %.cpp
	$(CC) $(CFLAGS); mv *.o obj/
clean:
	rm -rf *.o
