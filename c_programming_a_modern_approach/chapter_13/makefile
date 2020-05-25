CC = gcc
CFLAGS = -Wall
objects = exercise_16 project_4
all: $(objects)

$(objects): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf *.o $(objects)
