#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int particiona(int* vet, int inicio, int fim){
    int k = inicio, i, p = fim, aux;
    for(i = inicio; i < fim; i++){
        if(vet[i] <= vet[p]){
            aux = vet[i];
            vet[i] = vet[k];
            vet[k] = aux;
            k++;
        }
    }

    if (vet[k] > vet[p])
    {
        aux = vet[p];
        vet[p] = vet[k];
        vet[k] = aux;
    }

    return p;
}


void quick_sort(int* vet, int inicio, int fim){
    int pivo;
    
    if(inicio < fim){
        pivo = particiona(vet, inicio, fim);
        quick_sort(vet, inicio, pivo-1);
        quick_sort(vet, pivo+1, fim);
    }
}


void print_vet(int* vet, int n){
    int i;
   
    for(i = 0; i < n; i++){
        printf("%d, ", vet[i]);
    }
}



int main(){
    clock_t t;
    int n, i;
    int *vet;

    scanf("%d", &n);

    vet = malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    t = clock();

    quick_sort(vet, 0, n-1);

    t = clock() - t;

    printf("Tempo de execucao: %.2lf\n", ((double)t)/((CLOCKS_PER_SEC/1000/1000)));

    return 0;
}