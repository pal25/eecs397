CFLAGS = -Wall -Werror -std=gnu99

all: my_string_test

my_string_test: main.o my_string.o
	gcc $(CFLAGS) -o my_string_test main.o my_string.o

main.o: main.c my_string.h
	gcc $(CFLAGS) -c main.c

my_string.o: my_string.c my_string.h
	gcc $(CFLAGS) -c my_string.c

clean:
	rm -f *.o
	rm -f my_st