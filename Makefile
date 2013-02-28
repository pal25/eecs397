CFLAGS = -Wall -Werror -std=gnu99

all: main

main: main.o dmap_vector.o
	gcc $(CFLAGS) main.o dmap_vector.o -o main

main.o: main.c dmap_vector.h
	gcc $(CFLAGS) -c  main.c

dmap_vector.o: dmap_vector.c dmap_vector.h
	gcc $(CFLAGS) -c dmap_vector.c
clean:
	rm -f *.o main