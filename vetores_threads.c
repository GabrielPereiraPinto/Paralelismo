#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE_OF_VEC 16
#define NUM_THREADS 4

int A[SIZE_OF_VEC];
int B[SIZE_OF_VEC];
int C[SIZE_OF_VEC];
pthread_t threads[NUM_THREADS];

void PrintVec(char vec, int vector[]){
    printf ( "vector %c: ", vec);

    for (int i=0; i< SIZE_OF_VEC; i++){
        printf("%d ", vector[i]);
    }
}

void *SumVec(int threadId){

    int part = SIZE_OF_VEC / NUM_THREADS;

    for (int i = part * threadId); i < (threadId + 1) * part; i++){
        C[i] = A[i] + B[i];
    }
}
int main (int argc, char *argv[]) 
{
    for (int i = 0; i < SIZE_OF_VEC; i++){
        A[i] = rand();
        B[i] = rand();
        C[i] = 0;
    }

    for (int i = 0; i< NUM_THREADS; i++){
        pthread_create(threads[i], NULL, SumVec, i )
    }

    PrintVec("A", A);
    PrintVec("B", B);
    PrintVec("C", C);

    return 0;
}
