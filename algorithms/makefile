CC = clang
CFLAGS = -Wall -g -fsanitize=address -std=c99

all: binary_search_test

binary_search_test: binary_search_test.o binary_search.o
	$(CC) $(CFLAGS) -o binary_search_test binary_search_test.o binary_search.o

binary_search_test.o: binary_search_test.c binary_search.h
	$(CC) $(CFLAGS) -c binary_search_test.c

binary_search.o: binary_search.c binary_search.h
	$(CC) $(CFLAGS) -c binary_search.c

clean:
	rm -rf *.o binary_search_test
