#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE_OF_VEC 5

void PrintVec(char vec, int vector[]){
  printf ( "vector %c: ", vec);

  for (int i=0; i< SIZE_OF_VEC; i++){
  printf("%d ", vector[i]);
  }
}

int main (int argc, char *argv[]) 
{
  int id;
  int A[SIZE_OF_VEC];
  int B[SIZE_OF_VEC];
  int C[SIZE_OF_VEC];
  int *result = &C;
  for (int i = 0; i < SIZE_OF_VEC; i++){
    A[i] = rand();
    B[i] = rand();
    C[i] = 0;
  }
  #pragma omp parallel for
  for (int i = 0; i < SIZE_OF_VEC; i ++)
  {
    C[i] = A[i] + B[i];
    id = omp_get_thread_num();
    printf("i value: %d Thread ID %d, value %d\n", i, id, C[i]);
  }

  PrintVec("A", A);
  PrintVec("B", B);
  PrintVec("C", C);
    return 0;
}
