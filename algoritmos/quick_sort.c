#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys\timeb.h>


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

    quick_sort(vet, 0, n-1);

    ftime(&end);
    diff = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));

    printf("\nGastou %u milisegundos\n", diff); 

    return 0;
}