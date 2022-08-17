#include <iostream>
#include "../contact.h"


struct No2{
    Contact contact;
    No2* filhoesquerda;
    No2* filhodireita;
};

class ArvoreBinaria{ //BST = Binary Search Tree
    private:
    No2* raiz;

    public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void deletarArvore(No2* No2atual);
    No2* obterRaiz();
    bool estavazio();
    bool estacheio();
    void inserir(Contact contact);
    void remover(Contact contact);
    void removerbusca(Contact contact, No2*& No2atual);
    void deletarNo2(No2*& No2atual);
    void obterSucessor(Contact& ContactSucessor, No2* temp);
    void buscar(Contact& contact, bool& busca);
    void atualizar(Contact contact, bool& busca);
};