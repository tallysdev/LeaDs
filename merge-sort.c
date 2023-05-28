#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int vetor[], int start, int mid, int end){
    int p = start;
    int q = mid + 1;
    int w [end - start + 1];
    for (int i = 0; i < (end - start + 1); i++)
    {
        if ((q > end) || ((p <= mid) && (vetor[p] < vetor[q])))
        {
            w[i] = vetor[p];
            p +=1;
        } else
        {
            w[i] = vetor[q];
            q +=1;
        }
    }
    for (int j = 0; j < (end - start + 1); j++)
    {
        vetor[start + j] = w[j];
    }
}

void mergeSort(int vetor[], int start, int end){
    if (start < end)
    {
        int mid = ((start+end)/2);
        mergeSort(vetor,start,mid);
        mergeSort(vetor, mid+1,end);
        merge(vetor,start,mid,end);
    }
}

int main(int argc, char const *argv[])
{

struct timespec a, b;
    unsigned int t, tamanho;
    int i, *A;
    tamanho = atoi(argv[1]);
    A = (int *) malloc(tamanho * sizeof(int));
    srand(time(NULL));
    for (i = 0; i < tamanho; i++)
        A[i] = rand();

    clock_gettime(CLOCK_MONOTONIC, &b);
        mergeSort(A, 0, tamanho - 1);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);
    printf("%u\n", t);

    return 0;
}