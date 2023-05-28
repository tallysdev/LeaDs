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

void mergesort(int vetor[], int start, int end){
    if (start < end)
    {
        int mid = ((start+end)/2);
        mergesort(vetor,start,mid);
        mergesort(vetor, mid+1,end);
        merge(vetor,start,mid,end);
    }
}

int main(int argc, char const *argv[])
{
    int v [] = {8,7,6,5,4,3,2,1};
    int tamanho = sizeof(v) / sizeof(v[0]);
    mergesort(v,0,tamanho - 1);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}
