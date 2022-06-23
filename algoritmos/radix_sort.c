#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys\timeb.h>


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


void counting_sort(int* vet, int n, int pos){
    int* count = calloc(10, sizeof(int));
    int* aux = calloc(n, sizeof(int));
    int digito;

    for (int i = 0; i < n; i++){
        digito = (vet[i] / pos) % 10;
        count[digito]++;
    }
    
    for (int i = 1; i < 10; i++){
        count[i] = count[i] + count[i-1];
    }
    
    for (int i = n-1; i >= 0; i--){
        digito = (vet[i] / pos) % 10;
        count[digito]--;
        aux[count[digito]] = vet[i];
    }
    

    for (int i = 0; i < n; i++)
    {
        vet[i] = aux[i];
    }
    

}


void radix_sort(int* vet, int n){
    int max = maior(vet, n);
    for (int pos = 1; max / pos > 0; pos *= 10){
        counting_sort(vet, n, pos);
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
    radix_sort(vet, n);

    ftime(&end);
    diff = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));

    printf("\nGastou %u milisegundos\n", diff); 

    printf("Vetor ordenado: ");
    print_vet(vet, n);

    return 0;
} 