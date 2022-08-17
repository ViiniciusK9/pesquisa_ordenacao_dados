/*
    Algoritmo desenvolvido durante o curso de estruturas de dados
    do professor douglas maioli. link do curso abaixo:
    https://cursos.professordouglasmaioli.com.br/course/view.php?id=7
*/

#include <iostream>
#include "../contact.h"

struct No{
    Contact contact;
    No* filhoesquerda;
    No* filhodireita;

    int fatorB; 
};

class ArvoreAVL{
    private:
    No* raiz;

    public:
    ArvoreAVL();
    ~ArvoreAVL();
    void deletarArvore(No* noAtual);
    No* getRaiz();
    bool estaVazio();
    bool estaCheio();
    void inserir(Contact contact);
    void remover(Contact contact);
    void removerBusca(Contact contact, No*& noAtual, bool& diminuiu);
    void deletarNo(No*& noAtual, bool& busca);
    void obterSucessor(Contact& contactSucessor, No* temp);
    void buscar(Contact& contact, bool& busca);
    void atualizar(Contact contact, bool& busca);
    void imprimirEmOrdem(No* noAtual);
    
    // auxiliares
    void salvar(No* noAtual);
    void salvarArvore(No* noAtual);
    
    // rotações
    void rotacaoDireita(No*& tree);
    void rotacaoEsquerda(No*& tree);
    void rotacaoEsquerdaDireita(No*& tree);
    void rotacaoDireitaEsquerda(No*& tree);
    void realizarRotacao(No*& tree);
    void insereRecursivo(No*& noAtual, Contact contact, bool& cresceu);
};