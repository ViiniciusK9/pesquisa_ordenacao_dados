#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void ordenar(int* vet, int n){
    int i, j, aux, temp;

    for(i = 1; i < n; i++){
        aux = vet[i];
        for(j = i; j > 0; j--){ 
            if(vet[j-1] > aux){
                vet[j] = vet[j-1];
                if(j-1 == 0){
                    vet[j-1] = aux;
                }
            } else {
                vet[j-1] = aux;
            }
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