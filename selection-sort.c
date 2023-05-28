#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void selection_sort(int A[], int tamanho) {
    int min;
    int aux;

    for (int i = 0; i < (tamanho - 1); i++) {
        min = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        aux = A[i];
        A[i] = A[min];
        A[min] = aux;
        
    }
}

int main(int argc, char **argv) {

    struct timespec a, b;
    unsigned int t, tamanho;
    int i, *A;
    tamanho = atoi(argv[1]);
    A = (int *) malloc(tamanho * sizeof(int));
    srand(time(NULL));
    for (i = 0; i < tamanho; i++)
        A[i] = rand();

    clock_gettime(CLOCK_MONOTONIC, &b);
        selection_sort(A, tamanho);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);
    printf("%u\n", t);


    return 0;
}