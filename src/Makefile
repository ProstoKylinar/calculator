CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 -fsanitize=address
SOURCE_1=functions.c stack_c.c
SOURCE_2=calculation.c stack_n.c
OBJECTS_1 = $(SOURCE_1:.c=.o)
OBJECTS_2 = $(SOURCE_2:.c=.o)
MAIN=graph.o
EXECUTABLE=../build/graph

all: $(EXECUTABLE);

$(EXECUTABLE) : $(OBJECTS_1) $(OBJECTS_2) $(MAIN)
	$(CC) $(CFLAGS) $(OBJECTS_1) $(OBJECTS_2) $(MAIN) -o $@

$(OBJECTS_1) : 
	$(CC) $(CFLAGS) -c functions.c -o functions.o
	$(CC) $(CFLAGS) -c stack_c.c -o stack_c.o

$(OBJECTS_2) : 
	$(CC) $(CFLAGS) -c calculation.c -o calculation.o
	$(CC) $(CFLAGS) -c stack_n.c -o stack_n.o

$(MAIN):
	$(CC) $(CFLAGS) -c graph.c -o $@

clean:
	rm -rf *.o $(EXECUTABLE)

rebuild: clean all;


