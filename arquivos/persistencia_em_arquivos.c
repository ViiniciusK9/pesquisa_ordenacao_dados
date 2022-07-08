#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef struct {
    int dia;
    int mes;
    int ano;
} Data;


struct matricula{
    char matricula[10];
    char nome[40];
    Data nascimento;
    float nota;
    struct matricula *prox;
};
typedef struct matricula Matricula;


Matricula* alocar_matricula(){
    Matricula *nova_matricula = (Matricula*)malloc(sizeof(Matricula));
    return nova_matricula;
}


Matricula* inserir_matricula_fim(Matricula* Lista, char matricula[10], char nome[40], Data nascimento, float nota){
    Matricula *nova_matricula = alocar_matricula();
    strcpy(nova_matricula->matricula, matricula);
    strcpy(nova_matricula->nome, nome);
    nova_matricula->nascimento = nascimento;
    nova_matricula->nota = nota;
    nova_matricula->prox = NULL;

    if(Lista == NULL){
        Lista = nova_matricula;
    }else {
        Matricula *aux = Lista;

        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = nova_matricula;
    }
    return Lista;
}


Matricula* inserir_matricula_inicio(Matricula* Lista, char matricula[10], char nome[40], Data nascimento, float nota){
    Matricula *nova_matricula = alocar_matricula();
    strcpy(nova_matricula->matricula, matricula);
    strcpy(nova_matricula->nome, nome);
    nova_matricula->nascimento = nascimento;
    nova_matricula->nota = nota;
    nova_matricula->prox = NULL;

    if(Lista == NULL){
        Lista = nova_matricula;
        nova_matricula->prox = NULL;
    }else {
        nova_matricula->prox = Lista;
        Lista = nova_matricula;
    }
    return Lista;

}


Matricula* excluir_matricula(Matricula* Lista, char matricula[10]){
    Matricula *anterior, *atual;

    if(Lista == NULL){
        printf("Lista Vazia!\n");
    }else {
        anterior = Lista;
        atual = Lista;
        while(atual != NULL){
            if (strcmp(atual->matricula, matricula) == 0) {
                if (atual == Lista) {
                    Lista = Lista->prox;
                } else {
                    if (atual->prox == NULL){
                        anterior->prox = NULL;
                    }else {
                        anterior->prox = atual->prox;
                    }
                }
                free(atual);
                atual = anterior;
            } 
            anterior = atual;
            atual = atual->prox;
        }
    }
    return Lista;
}


void imprimir_lista(Matricula* Lista){
    Matricula *aux = Lista;

    if(aux == NULL){
        printf("Lista Vazia!\n");
    } else {
        while(aux != NULL){
            printf("%s, %s, %d/%d/%d, %.2f\n", aux->matricula, aux->nome, aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano, aux->nota);
            aux = aux->prox;
        }
    }
}


void imprimir_lista_reversa(Matricula* Lista){
    Matricula *aux = Lista;
    Matricula *Lista_aux = NULL;
    char matricula_cpy[10], nome_cpy[40];
    Data data_cpy;
    float nota_cpy;

    while(aux != NULL){
        strcpy(matricula_cpy, aux->matricula);
        strcpy(nome_cpy, aux->nome);
        data_cpy.dia = aux->nascimento.dia;
        data_cpy.mes = aux->nascimento.mes;
        data_cpy.ano = aux->nascimento.ano;
        nota_cpy = aux->nota;
        Lista_aux = inserir_matricula_inicio(Lista_aux, matricula_cpy, nome_cpy, data_cpy, nota_cpy);
        aux = aux->prox;
    }
    imprimir_lista(Lista_aux);
}


void contar_elementos(Matricula* Lista){
    Matricula *aux = Lista;
    int c = 0;
    while(aux != NULL){
        c++;
        aux = aux->prox;
    }
    printf("%d\n", c);
}


void limpar_lista(Matricula* Lista){
    Matricula *aux = Lista;
    Matricula *anterior;
    while(aux != NULL){
        anterior = aux;
        aux = aux->prox;
        free(anterior);
        printf("-");
    }
}


void escrever_arquivo(Matricula* Lista){
    FILE *p;
    p = fopen("arquivo.bin", "a+b");

    if (p == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    Matricula *aux = Lista;
    while(aux != NULL){
        fwrite(aux, sizeof(Matricula), 1, p);
        aux = aux->prox;
    }
    fclose(p);
}


void ler_arquivo(){
    FILE *p;
    int i = 0;
    p = fopen("arquivo.bin", "rb");
    if (p == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    while (!feof(p))
    {
        printf("%d\n", i++);

        Matricula *matricula = alocar_matricula();
        fread(matricula, sizeof(Matricula), 1, p);
        printf("%s\n", matricula->nome);
    }
    fclose(p);
    
}


int main(){
    int op = -1;
    char matricula_aux[10], nome_aux[40], data_aux_s[15];
    float nota_aux;
    Data data_aux;
    Matricula *Lista = NULL;

    do{
        scanf("%d", &op);
        switch (op)
        {
            case 1 :
                scanf("%s", matricula_aux);
                scanf("%s", nome_aux);
                scanf("%s", data_aux_s);
                char *aux = strtok(data_aux_s, "/");
                data_aux.dia = atoi(aux);
                aux = strtok(NULL, "/");
                data_aux.mes = atoi(aux);
                aux = strtok(NULL, "/");
                data_aux.ano = atoi(aux);
                scanf("%f", &nota_aux);
                Lista = inserir_matricula_fim(Lista, matricula_aux, nome_aux, data_aux, nota_aux);
                break;
            case 2 :
                scanf("%s", matricula_aux);
                Lista = excluir_matricula(Lista, matricula_aux);
                break;
            case 3 :
                imprimir_lista(Lista);
                break;
            case 4 :
                imprimir_lista_reversa(Lista);
                break;
            case 5 :
                contar_elementos(Lista);
                break;
            case 6:
                escrever_arquivo(Lista);
                break;
            case 7:
                ler_arquivo();
                break;
            case 0 :
                limpar_lista(Lista);
                break;
        }

    }while(op != 0);

    return 0;
}