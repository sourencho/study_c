CC = gcc
CFLAGS = -Wall
objects = exercise_14
all: $(objects)

$(objects): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf *.o $(objects)
