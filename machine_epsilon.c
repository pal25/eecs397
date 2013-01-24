#include <stdio.h>
 
int main( int argc, char **argv )
{
  float feps = 1.0f;
  double deps = 1.0;
  long double ldeps = 1.0L;
 

  do {
    //printf( "%G\t%.20f\n", feps, (1.0f + feps) );
    feps /= 2.0f;
  }
  while ((float)(1.0 + (feps/2.0)) != 1.0);
  

  do {
    //printf( "%G\t%.20f\n", deps, (1.0 + deps) );
    deps /= 2.0;
  }
  while ((double)(1.0 + (deps/2.0)) != 1.0);
  

  do {
    //printf( "%LG\t%.20Lf\n", ldeps, (1.0L + ldeps) );
    ldeps /= 2.0L;
  }
  while ((long double)(1.0 + (ldeps/2.0)) != 1.0);
 
  printf( "Calculated Machine epsilon (float): %G\n", feps );
  printf( "Calculated Machine epsilon (double): %G\n", deps );
  printf( "Calculated Machine epsilon (long double): %LG\n\n", ldeps );
  return 0;
}
