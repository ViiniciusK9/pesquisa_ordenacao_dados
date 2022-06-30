#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys\timeb.h>


void intercala(int* vet, int inicio, int meio, int fim);


void merge_sort(int* vet, int inicio, int fim){
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;
        merge_sort(vet, inicio, meio);
        merge_sort(vet, meio + 1, fim);
        intercala(vet, inicio, meio, fim);
    }    
}


void intercala(int* vet, int inicio, int meio, int fim){
    int *aux = malloc((fim - inicio + 1) * sizeof(int));
    int i = inicio , j = meio + 1, k = 0;

    while (i <= meio && j <= fim)   
    {
        if (vet[i] <= vet[j])
        {
            aux[k] = vet[i];
            i++;
        } else {
            aux[k] = vet[j];
            j++;
        }
        k++;
    }
    
    while (i <= meio)
    {
        aux[k] = vet[i];
        k++;
        i++;
    }
    
    while (j <= fim)
    {
        aux[k] = vet[j];
        k++;
        j++;
    }
    
    for (k = inicio; k <= fim; k++)
    {
        vet[k] = aux[k - inicio];
    }
    
    free(aux);
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

    merge_sort(vet, 0, n-1);

    ftime(&end);
    diff = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));

    printf("\nGastou %u milisegundos\n", diff); 
     
    return 0;
}