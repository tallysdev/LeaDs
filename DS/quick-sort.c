#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int v[], int i, int j) {
    int aux = v[j];
    v[j] = v[i];
    v[i] = aux;
}

int particion(int vetor[], int start, int end) {
    int pivot = vetor[end];
    int i = start - 1;
    for (int j = start; j <= end - 1; j++) {
        if (vetor[j] <= pivot) {
            i++;
            swap(vetor, i, j);
        }
    }
    swap(vetor, i + 1, end);
    return (i + 1);
}

void quickSort(int vetor[], int start, int end) {
    if (start < end) {
        int p = particion(vetor, start, end);
        quickSort(vetor, start, p - 1);
        quickSort(vetor, p + 1, end);
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
            quickSort(A, 0, tamanho);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);
    printf("%u\n", t);

    return 0;

}