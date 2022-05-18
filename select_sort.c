#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void troca(int maior, int i, int* vet){
    int aux;
    aux = vet[maior];
    vet[maior] = vet[i];
    vet[i] = aux;
}


void ordenar(int* vet, int n){
    int i, j, maior;
    for(i = 0; i < n-1; i++){
        maior = i;
        for(j = i; j < n; j++){
            if(vet[maior] > vet[j]){
                maior = j;
            }
        }
        if(maior != i){
            troca(maior, i, vet);
        }
    }
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

    ordenar(vet, n);

    printf("Vetor ordenado: ");
    print_vet(vet, n);
    printf("\n");

    return 0;
}