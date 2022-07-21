#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void quick(int vet[], int esq, int dir){
    int pivo = dir, i,ch,j;         
    for(i=esq+1;i<=dir;i++){        
        j = i;                      
        if(vet[j] < vet[pivo]){     
            ch = vet[j];               
            while(j > pivo){           
                vet[j] = vet[j-1];      
                j--;                    
            }
            vet[j] = ch;               
            pivo++;                    
        }
    }
    if(pivo-1 >= esq){              
        quick(vet,esq,pivo-1);      
    }
    if(pivo+1 <= dir){              
        quick(vet,pivo+1,dir);      
    }
}


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
    clock_t t;
    int n, i;
    int *vet;

    scanf("%d", &n);

    vet = malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    t = clock();

    quick(vet, 0, n-1);

    t = clock() - t;

    printf("Tempo de execucao: %.2lf\n", ((double)t)/((CLOCKS_PER_SEC/1000/1000)));
    print_vet(vet, n);

    return 0;
}