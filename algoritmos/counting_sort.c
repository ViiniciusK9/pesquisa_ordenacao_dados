#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys\timeb.h>


void ordenar(int* vet, int n, int k){
    int *aux = calloc(k, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        aux[vet[i]] = + 1;
    }
    //print_vet(aux, k);    

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
    struct timeb start, end;
    int diff;
    int n, i;
    int *vet;
    int k;

    scanf("%d", &n);

    vet = malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    ftime(&start);
    k = maior(vet, n);
    ordenar(vet, n, k+1);

    ftime(&end);
    diff = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));

    printf("\nGastou %u milisegundos\n", diff); 

    return 0;
}