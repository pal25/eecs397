#include <stdio.h>


double quadratic(double a, double b, double c, double x)
{
    return (a * x * x) + (b * x) + c;
}
  

int main(int argc, char **argv)
{
    FILE *fout;
    fout = fopen("quadratic.csv", "w");
  
    double a = 1.75;
    double b = -2.0;
    double c = 2.5;

    for(double x=-10.0; x <= 10.0; x += 0.1) {
      fprintf(fout, "%G, %G\n", x, quadratic(a, b, c, x));
    }

    fclose(fout);

    return 0;
}
