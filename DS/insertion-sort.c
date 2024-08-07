#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int v[], int i) {
    int aux = v[i-1];
    v[i-1] = v[i];
    v[i] = aux;
}

void insertionSort(int v[], int n) {
    for (int e = 2; e < n; e++) {
        int i = e;
        while (i > 0 && v[i-1] > v[i]) {
            swap(v, i);
            i -= 1;
        }
    }
}

int main(int argc, char const *argv[]) {

    struct timespec a, b;
    unsigned int t, tamanho;
    int i, *A;
    tamanho = atoi(argv[1]);
    A = (int *) malloc(tamanho * sizeof(int));
    srand(time(NULL));
    for (i = 0; i < tamanho; i++)
        A[i] = rand();

    clock_gettime(CLOCK_MONOTONIC, &b);
        insertionSort(A, tamanho);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);
    printf("%u\n", t);

    return 0;
}