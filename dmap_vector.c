#include "dmap_vector.c"

void double_vector_display(double *d, int length)
{
    int i=0;
    for(i=0; i<length; i++) {
	printf("%s\n", d[i]);
    }
}

void *double_vector_map(double *d, int length, double (*f)(double))
{
    int i;
    for(i=0; i<length; i++) {
	d[i] = f(d[i]);
    }
}

double identity_f(double x)
{
    return x;
}

double negate_f(double x)
{
    return -1.0*x;
}

double invert_f(double x)
{
    return 1.0/x;
}

double mul_2_f(double x)
{
    return 2.0*x;
}

double div_2_f(double x)
{
    return x/2.0;
}
