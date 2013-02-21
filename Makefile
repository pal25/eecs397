CFLAGS = -Wall -Werror -std=gnu99

all: my_echo

my_echo: my_echo.c
	gcc $(CFLAGS) -o my_echo my_echo.c

clean:
	rm -f *~ my_echo