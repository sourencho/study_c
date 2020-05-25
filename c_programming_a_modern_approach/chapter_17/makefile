CC = gcc
CFLAGS = -Wall
objects = exercise_2
all: $(objects)

$(objects): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf *.o $(objects)
