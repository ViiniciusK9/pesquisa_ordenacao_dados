#include <stdio.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

int main(){
    clock_t t; //variável para armazenar tempo
    t = clock(); //armazena tempo
    
    t = clock() - t; //tempo final - tempo inicial
    //imprime o tempo na tela
    printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double
}