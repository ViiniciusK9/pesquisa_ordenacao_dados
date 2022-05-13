#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void ordenar(int* vet, int n){
    int i, j, aux;

    for(i = 1; i < n; i++){
        for(j = 0; j < n-i; j++){
            if(vet[j] > vet[j+1]){
                aux = vet[j+1];
                vet[j+1] = vet[j];
                vet[j] = aux;
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

// gcc bubble_sort.c -Wall -o prog
// ./prog < in > out