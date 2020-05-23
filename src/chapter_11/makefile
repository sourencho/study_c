CC = gcc
CFLAGS = -Wall -std=c99
objects = exercise_8
all: $(objects)

$(objects): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf *.o $(objects)
