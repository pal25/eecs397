FLAGS = -Wall -Werror -std=gnu99
OUTPUT = matrix

all: matrix

matrix: matrix.o matrix_lib.o
	gcc $(FLAGS) matrix.o matrix_lib.o -o $(OUTPUT) -lm
	chmod u+x $(OUTPUT)

matrix.o: matrix.c matrix_lib.h
	gcc $(FLAGS) -c matrix.c

matrix_lib.o: matrix_lib.c matrix_lib.h
	gcc $(FLAGS) -c matrix_lib.c

clean:
	rm $(OUTPUT) *.o