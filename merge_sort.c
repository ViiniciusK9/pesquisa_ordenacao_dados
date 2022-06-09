#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void merge_sort(int* vet, int inicio, int fim){


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

    merge_sort(vet, n);

    printf("Vetor ordenado: ");
    print_vet(vet, 0, n);
    printf("\n");   
    return 0;
}