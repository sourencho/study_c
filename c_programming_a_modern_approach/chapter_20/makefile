CC = gcc
CFLAGS = -Wall
objects = exercise_2 exercise_4 exercise_6
all: $(objects)

$(objects): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf *.o $(objects)
