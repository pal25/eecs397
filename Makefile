CFLAGS = -Wall -Werror -std=gnu99 -I/usr/include/ -L/usr/lib/
LIBS = -lzmq

all: publish

publish: publish.c helper.c
	gcc $(CFLAGS) -o publish publish.c helper.c $(LIBS)

subscribe: subscribe.c helper.c
	gcc $(CFLAGS) -o subscribe subscribe.c helper.c $(LIBS)

helper.o: helper.c helper.h
	gcc $(CFLAGS) -c helper.c

clean:
	rm -f *.o publish subscribe

