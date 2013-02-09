all: matrix

matrix: matrix.o matrix_lib.o
	gcc -std=c99 matrix.o matrix_lib.o -o matrix

matrix.o: matrix.c matrix_lib.h
	gcc -c matrix.c

matrix_lib.o: matrix_lib.c matrix_lib.h
	gcc -c matrix_lib.c

clean:
	rm matrix *.o