all: account

account: main.o number_to_word.o
	gcc main.o number_to_word.o -o account

main.o: main.c number_to_word.h
	gcc -c main.c

number_to_word.o: number_to_word.c number_to_word.h
	gcc -c number_to_word.c

clean:
	rm -rf *o account

