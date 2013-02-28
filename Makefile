CFLAGS = -Wall -Werror -std=gnu99

all: maincopy

my_echo: maincopy.c
	gcc $(CFLAGS) -o maincopy maincopy.c

clean:
	rm -f *~ maincopy