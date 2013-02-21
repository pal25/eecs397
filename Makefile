CFLAGS = -Wall -Werror -std=gnu99

all: stack_overflow

my_echo: stack_overflow.c
	gcc $(CFLAGS) -o stack_overflow stack_overflow.c

clean:
	rm -f *~ stack_overflow