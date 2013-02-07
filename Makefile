all: stats

stats: main.c
	gcc -std=c99 -o stats main.c -lm

clean:
	rm *.o stats

