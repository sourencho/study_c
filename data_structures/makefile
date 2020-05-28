CC = clang
CFLAGS = -Wall -g -fsanitize=address -std=c99

all: stack_test priority_queue_test

stack_test: stack_test.o stack.o
	$(CC) $(CFLAGS) -o stack_test stack_test.o stack.o

stack_test.o: stack_test.c stack.h
	$(CC) $(CFLAGS) -c stack_test.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c


priority_queue_test: priority_queue_test.o priority_queue.o item.o
	$(CC) $(CFLAGS) -o priority_queue_test priority_queue_test.o priority_queue.o item.o

priority_queue_test.o: priority_queue_test.c priority_queue.h
	$(CC) $(CFLAGS) -c priority_queue_test.c

priority_queue.o: priority_queue.c priority_queue.h item.c item.h
	$(CC) $(CFLAGS) -c priority_queue.c

item.o: item.c item.h
	$(CC) $(CFLAGS) -c item.c

clean:
	rm -rf *.o stack_test priority_queue_test
