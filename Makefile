CFLAGS = -Wall -Werror -g -std=gnu99

all: main

main: main.o dict.o
	gcc $(CFLAGS) dict.o main.c -o main

dict.o: dict.c	
	gcc $(CFLAGS) -c dict.c

clean:
	rm *.o main

