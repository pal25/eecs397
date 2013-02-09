#include <stdio.h>
#include "matrix_lib.h"

void mul_3x3_by_3x1(double r[3][3], double x[3], double y[3])
{
    for(int j=0; j<NUM_ROWS; j++) {
	double sum = 0;
	for(int i=0; i<NUM_ROWS; i++) {
	    sum += r[j][i]*x[i];
	}

	y[j] = sum;
    }
}

void display_matrix(double a[3][3])
{
    for(int j=0; j<NUM_ROWS; j++) {
	for(int i=0; i<NUM_ROWS; i++) {
	    printf("%+#7.3f", a[j][i]);
	}
	printf("\n");
    }
}

void display_vector(double a[3])
{
    for(int i=0; i<NUM_ROWS; i++) {
	printf("%+#7.3f\n", a[i]);
    }
}
