#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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
    aux = vet[p];
    vet[p] = vet[k];
    vet[k] = aux;

    return k;
}


void quick_sort(int* vet, int inicio, int fim){
    int pivo, final = fim;
    
    if(inicio > fim){
        return;
    }
    
    pivo = particiona(vet, inicio, fim);
    quick_sort(vet, inicio, pivo-1);
    quick_sort(vet, pivo+1, final);
}


void print_vet(int* vet, int n){
    int i;
   
    for(i = 0; i < n; i++){
        printf("%d, ", vet[i]);
    }
}



int main(){
    int n, i;
    int *vet;

    scanf("%d", &n);

    vet = malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    printf("Vetor: ");
    print_vet(vet, n);
    printf("\n");

    quick_sort(vet, 0, n-1);

    printf("Vetor ordenado: ");
    print_vet(vet, n);
    printf("\n");


    return 0;
}