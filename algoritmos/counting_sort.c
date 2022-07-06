#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void ordenar(int* vet, int n, int k){
    int *aux = calloc(k, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        aux[vet[i]] = + 1;
    }    

    int index = 0;
    for (int i = 0; i < k; i++)
    {
        if(aux[i] != 0){
            while (aux[i] != 0)
            {
                vet[index] = i;
                aux[i]--;
                index++;
            }
            
        }
    }
    
}


int maior(int* vet, int n){
    int aux_maior = 0; 
    for (int i = 0; i < n; i++)
    {
        if(vet[i] > aux_maior){
            aux_maior = vet[i];
        }
    }
    return aux_maior;
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
    int k;

    scanf("%d", &n);

    vet = malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }
    
    k = maior(vet, n);
    t = clock();
    
    ordenar(vet, n, k+1);

    t = clock() - t;

    printf("Tempo de execucao: %.2lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

    return 0;
}