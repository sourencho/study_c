CC = gcc
CFLAGS = -Wall
objects = exercise_1 exercise_4 exercise_6 exercise_15
all: $(objects)

$(objects): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf *.o $(objects)
