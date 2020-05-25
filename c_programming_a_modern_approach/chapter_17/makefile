CC = clang
CFLAGS = -Wall -g -fsanitize=address -std=c99
objects = exercise_2
all: $(objects) exercise_8

$(objects): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

exercise_8: exercise_8.o ../../data_structures/stack.o
	$(CC) $(CFLAGS) -o exercise_8 exercise_8.o ../../data_structures/stack.o

clean:
	rm -rf *.o $(objects) exercise_8 `find . -name "*.dSYM"`
