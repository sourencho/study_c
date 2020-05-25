LIBS =
CC = clang
CFLAGS = -Wall -g -fsanitize=address -std=c99

all: stack_test

stack_test: stack_test.o stack.o
	$(CC) $(CFLAGS) $(LIBS) -o stack_test stack_test.o stack.o

stack_test.o: stack_test.c stack.h
	$(CC) $(CFLAGS) -c stack_test.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm -rf *.o stack_test
