all: html

html: html.c
	gcc -std=c99 -o html html.c

clean:
	rm html