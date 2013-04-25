CFLAGS = -Wall -Werror -std=gnu99 -g -I/usr/include/ -L/usr/lib/
LIBS = -lzmq -ljansson

all: publish subscriber

publish: publish.c helper.c
	gcc $(CFLAGS) -o publish publish.c helper.c $(LIBS)

subscriber: subscriber.c helper.c
	gcc $(CFLAGS) -o subscriber subscriber.c helper.c $(LIBS)

helper.o: helper.c helper.h
	gcc $(CFLAGS) -c helper.c

clean:
	rm -f *.o publish subscriber

