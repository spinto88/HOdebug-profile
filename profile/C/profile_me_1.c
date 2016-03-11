#include <stdlib.h>
#include <math.h>

#define SIZE 5000

void first_assign(int i1, int i2, double * a, double * b, double * c )
{  
  a[i2*SIZE+i1] = a[i2*SIZE+i1] + b[i2*SIZE+i1] + c[i2*SIZE+i1];
}

void second_assign(int i1, int i2, double * a, double * b, double * c )
{  
  a[i1*SIZE+i2] = a[i1*SIZE+i2] + b[i1*SIZE+i2] + c[i1*SIZE+i2];
}

int main( int argc, char * argv[] )
{

  int i , j;
  double *a, *b, *c;

  a = (double *)malloc(sizeof(double) * SIZE * SIZE);
  b = (double *)malloc(sizeof(double) * SIZE * SIZE);
  c = (double *)malloc(sizeof(double) * SIZE * SIZE);
 
  for( i = 0; i < SIZE; i++ ){
    for( j = 0; j < SIZE; j++ ){

      a[i * SIZE + j] = 1.0;
      b[i * SIZE + j] = 2.0;
      c[i * SIZE + j] = 3.0;
    }
  }

   for( i = 0; i < SIZE; i++ ){
    for( j = 0; j < SIZE; j++ ){
      first_assign(i, j, a, b, c);
    }
  }

  for( i = 0; i < SIZE; i++ ){
    for( j = 0; j < SIZE; j++ ){
      second_assign(i, j, a, b, c);
    }
  }

  return 0;
}
