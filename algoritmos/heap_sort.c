#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys\timeb.h>


int pai(int i){
    return (i - 1) / 2;
}

int filho_esq(int i){
    return (2 * i) + 1;
}

int filho_dir(int i){
    return (2 * i) + 2;
}

void inserir_heap_max(int* vet, int n, int num){
    int aux;
    vet[n] = num;
    if(n != 0){
        while (vet[n] > vet[pai(n)])
        {
            aux = vet[n];
            vet[n] = vet[pai(n)];
            vet[pai(n)] = aux;
            n = pai(n);
        }
    }else {
        vet[n] = num;
    }
}

void inserir_heap_min(int* vet, int n, int num){
    int aux;
    vet[n] = num;
    if(n != 0){
        while (vet[n] < vet[pai(n)])
        {
            aux = vet[n];
            vet[n] = vet[pai(n)];
            vet[pai(n)] = aux;
            n = pai(n);
        }
    }else {
        vet[n] = num;
    }
}


void cria_heap(int* vet, int i, int n){
    int maior = i, left = 2 * i + 1, right = 2 * i + 2, aux;

    if (left < n && vet[left] > vet[i])
    {
        maior = left;
    }

    if (right < n && vet[right] > vet[maior])
    {
        maior = right;
    }

    if (maior != i)
    {
        aux = vet[i];
        vet[i] = vet[maior];
        vet[maior] = aux;
        cria_heap(vet, maior, n);
    }
}


void heap_sort(int* vet, int n){
    int aux;

    for (int k = (n/2) - 1; k >= 0 ; k--)
    {
        cria_heap(vet, k, n);
    }

    for (int k = n-1; k >= 1; k--)
    {
        aux = vet[0];
        vet[0] = vet[k];
        vet[k] = aux;
        cria_heap(vet, 0, k);
    }   
}


void print_vet(int* vet, int n){
    int i;
   
    for(i = 0; i < n; i++){
        printf("%d, ", vet[i]);
    }
}

int main(){
    struct timeb start, end;
    int diff;
    int n, i;
    int *vet;

    scanf("%d", &n);

    vet = malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    ftime(&start);

    heap_sort(vet, n);

    ftime(&end);
    diff = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));

    printf("\nGastou %u milisegundos\n", diff);

    return 0;
}

// pai(i) = (i-1)/2
// filho_esq(i) = 2i+1
// filho_dir(i) = 2i+2
