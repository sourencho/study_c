CC = clang
CFLAGS = -Wall -g -fsanitize=address -std=c99

all: stack_test priority_queue_test vector_test dag_test map_test trie_test circular_buffer_test deque_test bst_test

bst_test: bst_test.o bst.o
	$(CC) $(CFLAGS) -o bst_test bst_test.o bst.o

bst_test.o: bst_test.c bst.h
	$(CC) $(CFLAGS) -c bst_test.c

bst.o: bst.c bst.h
	$(CC) $(CFLAGS) -c bst.c

deque_test: deque_test.o deque.o
	$(CC) $(CFLAGS) -o deque_test deque_test.o deque.o

deque_test.o: deque_test.c deque.h
	$(CC) $(CFLAGS) -c deque_test.c

deque.o: deque.c deque.h
	$(CC) $(CFLAGS) -c deque.c

circular_buffer_test: circular_buffer_test.o circular_buffer.o
	$(CC) $(CFLAGS) -o circular_buffer_test circular_buffer_test.o circular_buffer.o

circular_buffer_test.o: circular_buffer_test.c circular_buffer.h
	$(CC) $(CFLAGS) -c circular_buffer_test.c

circular_buffer.o: circular_buffer.c circular_buffer.h
	$(CC) $(CFLAGS) -c circular_buffer.c

trie_test: trie_test.o trie.o
	$(CC) $(CFLAGS) -o trie_test trie_test.o trie.o

trie_test.o: trie_test.c trie.h
	$(CC) $(CFLAGS) -c trie_test.c

trie.o: trie.c trie.h
	$(CC) $(CFLAGS) -c trie.c

map_test: map_test.o map.o
	$(CC) $(CFLAGS) -o map_test map_test.o map.o

map_test.o: map_test.c map.h
	$(CC) $(CFLAGS) -c map_test.c

map.o: map.c map.h
	$(CC) $(CFLAGS) -c map.c

dag_test: dag_test.o dag.o
	$(CC) $(CFLAGS) -o dag_test dag_test.o dag.o stack.o

dag_test.o: dag_test.c dag.h
	$(CC) $(CFLAGS) -c dag_test.c

dag.o: dag.c dag.h stack.c stack.h
	$(CC) $(CFLAGS) -c dag.c

vector_test: vector_test.o vector.o
	$(CC) $(CFLAGS) -o vector_test vector_test.o vector.o item.o

vector_test.o: vector_test.c vector.h
	$(CC) $(CFLAGS) -c vector_test.c

vector.o: vector.c vector.h item.c item.h
	$(CC) $(CFLAGS) -c vector.c

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
	rm -rf *.o stack_test priority_queue_test vector_test dag_test map_test trie_test circular_buffer_test deque_test bst_test
