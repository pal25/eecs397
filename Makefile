CFLAGS = -Wall -Werror -g -std=gnu99

all: freq

valgrind: freq
	valgrind --tool=memcheck --leak-check=yes ./freq

freq: freq.o dict.o
	gcc $(CFLAGS) dict.o freq.c -o freq

dict.o: dict.c	
	gcc $(CFLAGS) -c dict.c

clean:
	rm *.o freq

