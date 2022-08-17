#include <iostream>
#include <cstddef>
#include "arvoreAVL.h"
#include <stdio.h>
#include <string>
#include <conio.h>

    
using namespace std;

    ArvoreAVL::ArvoreAVL()
    {
        raiz = NULL;
    }

    ArvoreAVL::~ArvoreAVL()
    {
        deletarArvore(raiz);
    }

    void ArvoreAVL::deletarArvore(No* noAtual)
    {
        if(noAtual != NULL){
            deletarArvore(noAtual->filhoesquerda);
            deletarArvore(noAtual->filhodireita);

            delete noAtual;
        }
    }

    No* ArvoreAVL::getRaiz()
    {
        return raiz;
    }

    bool ArvoreAVL::estaVazio()
    {
        return (raiz == NULL);
    }

    bool ArvoreAVL::estaCheio()
    {
        try
        {
            No* temp = new No;
            delete temp;
            return false;
        }
        catch(bad_alloc exception)
        {
            return true;
        }
        
    }

    void ArvoreAVL::inserir(Contact contact)
    {
        bool cresceu;
        insereRecursivo(raiz, contact, cresceu);
    }

    void ArvoreAVL::insereRecursivo(No*& noAtual, Contact contact, bool& cresceu)
    {
        if(noAtual == NULL){
            noAtual = new No;
            noAtual->filhodireita = NULL;
            noAtual->filhoesquerda = NULL;
            noAtual->contact = contact;
            noAtual->fatorB = 0;
            cresceu = true;
            return;
        }
        if (contact.getNome() < noAtual->contact.getNome()) {
            insereRecursivo(noAtual->filhoesquerda, contact, cresceu);
            if (cresceu) {
                noAtual->fatorB -= 1;
            }
        } else {
            insereRecursivo(noAtual->filhodireita, contact, cresceu);
            if (cresceu) {
                noAtual->fatorB += 1;
            }
        }
        
        realizarRotacao(noAtual);

        if (cresceu && noAtual->fatorB == 0) {
            cresceu = false;
        }
    }

    void ArvoreAVL::remover(Contact contact)
    {
        bool diminuiu;
        removerBusca(contact, raiz, diminuiu);
    }

    void ArvoreAVL::removerBusca(Contact contact, No*& noAtual, bool& diminuiu)
    {
        if (contact.getNome() < noAtual->contact.getNome()){
            removerBusca(contact, noAtual->filhoesquerda, diminuiu);
            if (diminuiu) {
                noAtual->fatorB += 1;
            }
        } else if (contact.getNome() > noAtual->contact.getNome()){
            removerBusca(contact, noAtual->filhodireita, diminuiu);
            if (diminuiu) {
                noAtual->fatorB -= 1;
            }
        } else { 
            deletarNo(noAtual, diminuiu);
        }
        if (noAtual != NULL) {
            realizarRotacao(noAtual);
            if (diminuiu && noAtual->fatorB != 0) {
                diminuiu = false;
            }
        }
    }

    void ArvoreAVL::deletarNo(No*& noAtual, bool& diminuiu)
    {
        No* temp = noAtual;
        if (noAtual->filhoesquerda == NULL){
            noAtual = noAtual->filhodireita;
            diminuiu = true;
            delete temp;
        } else if (noAtual->filhodireita == NULL){
            noAtual = noAtual->filhoesquerda;
            diminuiu = true;
            delete temp;
        } else {
            Contact ContactSucessor;
            obterSucessor(ContactSucessor, noAtual);
            noAtual->contact = ContactSucessor;
            removerBusca(ContactSucessor, noAtual->filhodireita, diminuiu);
            if (diminuiu) {
                noAtual->fatorB -= 1;
            }
        }
    }

    void ArvoreAVL::obterSucessor(Contact& ContactSucessor, No* temp)
    {
        temp = temp->filhodireita;
        while (temp->filhoesquerda != NULL){
            temp = temp->filhoesquerda;
        }
        ContactSucessor = temp->contact;
    }

    void ArvoreAVL::buscar(Contact& contact, bool& busca)
    {
        busca = false;
        No* noAtual = raiz;
        while(noAtual != NULL){
            if (contact.getNome() < noAtual->contact.getNome()){
                noAtual = noAtual->filhoesquerda;
            } else if(contact.getNome() > noAtual->contact.getNome()){
                noAtual = noAtual->filhodireita;
            } else{
                busca = true;
                contact = noAtual->contact;
                break;
            }
        }
    }

    void ArvoreAVL::atualizar(Contact contact, bool& busca)
    {
        busca = false;
        No* noAtual = raiz;
        while(noAtual != NULL){
            if (contact.getNome() < noAtual->contact.getNome()){
                noAtual = noAtual->filhoesquerda;
            } else if(contact.getNome() > noAtual->contact.getNome()){
                noAtual = noAtual->filhodireita;
            } else{
                busca = true;
                noAtual->contact = contact;
                break;
            }
        }
    }

    void ArvoreAVL::imprimirEmOrdem(No* noAtual)
    {
        if(noAtual != NULL){
            imprimirEmOrdem(noAtual->filhoesquerda);

            cout << '\n';
            cout << "Nome: " << noAtual->contact.getNome() << '\n';
            cout << "Data de nascimento: " << noAtual->contact.getDate() << '\n';
            cout << "Email: " << noAtual->contact.getEmail() << '\n';
            cout << "Phone: " << noAtual->contact.getPhone() << '\n';
            
            imprimirEmOrdem(noAtual->filhodireita);
        }
    }
    
    void ArvoreAVL::salvar(No* noAtual)
    {
        FILE *arq;
        arq = fopen("dados.txt", "wt");
        int result = fputs("", arq);
        if (result == EOF)
            printf("Erro na Gravacao\n");
        fclose(arq);
        salvarArvore(noAtual);
    }

    void ArvoreAVL::salvarArvore(No* noAtual)
    {
        if(noAtual != NULL){
            salvarArvore(noAtual->filhoesquerda);

            FILE *arq;
            arq = fopen("dados.txt", "at");
            
            string nome = noAtual->contact.getNome();
            string data = noAtual->contact.getDate();
            string email = noAtual->contact.getEmail();
            string phone = noAtual->contact.getPhone();
            string aux = "";
            aux += nome + "," += data + "," += email + "," += phone += ",\n";
            char const *c = aux.c_str();
            fputs(c, arq);
            fclose(arq);
            salvarArvore(noAtual->filhodireita);
        }
    }
    

// Novos metodos 

    void ArvoreAVL::rotacaoDireita(No*& pai)
    {
        No* novopai = pai->filhoesquerda;
        pai->filhoesquerda = novopai->filhodireita;
        novopai->filhodireita = pai;
        pai = novopai;
    }

    void ArvoreAVL::rotacaoEsquerda(No*& pai)
    {
        No* novopai = pai->filhodireita;
        pai->filhodireita = novopai->filhoesquerda;
        novopai->filhoesquerda = pai;
        pai = novopai;
    }

    void ArvoreAVL::rotacaoEsquerdaDireita(No*& pai)
    {
        No* filho = pai->filhoesquerda;
        rotacaoEsquerda(filho);
        pai->filhoesquerda = filho;
        rotacaoDireita(pai);
    }

    void ArvoreAVL::rotacaoDireitaEsquerda(No*& pai)
    {
        No* filho = pai->filhodireita;
        rotacaoDireita(filho);
        pai->filhodireita = filho;
        rotacaoEsquerda(pai);
    }

    void ArvoreAVL::realizarRotacao(No*& pai)
    {
        No* filho;
        No* neto;

        if (pai->fatorB == -2) { // rotaciona para a direita

            filho = pai->filhoesquerda;

            if (filho->fatorB == -1) { // simples para a direita
                pai->fatorB = 0;
                filho->fatorB = 0;
                rotacaoDireita(pai);
            } else if (filho->fatorB == 0) { // simples para a direita
                pai->fatorB = -1;
                filho->fatorB = 1;
                rotacaoDireita(pai);
            } else if (filho->fatorB == 1) { // rotacao dupla
                neto = filho->filhodireita;
                if (neto->fatorB == -1) {
                    pai->fatorB = 1;
                    filho->fatorB = 0;
                } else if (filho->fatorB == 0) {
                    pai->fatorB = 0;
                    filho->fatorB = 0;
                } else if (filho->fatorB == 1) {
                    pai->fatorB = 0;
                    filho->fatorB = -1;
                }
                neto->fatorB = 0;
                rotacaoEsquerdaDireita(pai);
            }
        } else if (pai->fatorB == 2) { // rotaciona para a esquerda

            filho = pai->filhoesquerda;

            if (filho->fatorB == -1) { // simples para a esquerda
                pai->fatorB = 0;
                filho->fatorB = 0;
                rotacaoEsquerda(pai);
            } else if (filho->fatorB == 0) { // simples para a esquerda
                pai->fatorB = 1;
                filho->fatorB = -1;
                rotacaoEsquerda(pai);
            } else if (filho->fatorB == -1) { // rotacao dupla
                neto = filho->filhodireita;
                if (neto->fatorB == -1) {
                    pai->fatorB = 0;
                    filho->fatorB = 1;
                } else if (filho->fatorB == 0) {
                    pai->fatorB = 0;
                    filho->fatorB = 0;
                } else if (filho->fatorB == 1) {
                    pai->fatorB = 1;
                    filho->fatorB = 0;
                }
                neto->fatorB = 0;
                rotacaoDireitaEsquerda(pai);
            }
        }
    }