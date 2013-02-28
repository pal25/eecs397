#ifndef DMAP_VECTOR_H
#define DMAP_VECTOR_H

void double_vector_display(double *d, int length);

void double_vector_map(double *d, int length, double (*f)(double));

double identity_f(double x);
double negate_f(double x);
double invert_f(double x);
double mul_2_f(double x);
double div_2_f(double x);

#endif
