CFLAGS = -Wall -Werror -std=gnu99

all: main

main: main.o dict.o
	gcc $(CFLAGS) main.o dict.o -o main

main.o: main.c dict.h
	gcc $(CFLAGS) -c main.c

dict.o: dict.c dict.h
	gcc $(CFLAGS) -c dict.c

clean:
	rm *.o main

