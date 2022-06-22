#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void print_vet(int* vet, int n){
    int i;
   
    for(i = 0; i < n; i++){
        printf("%d, ", vet[i]);
    }
}

int main(){

    int n, i, aux;
    int *vet;

    scanf("%d", &n);

    vet = malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        scanf("%d", &aux);
        inserir_heap_max(vet, i, aux);
    }

    printf("Vetor_max: ");
    print_vet(vet, n);



    return 0;
}

// pai(i) = (i-1)/2
// filho_esq(i) = 2i+1
// filho_dir(i) = 2i+2