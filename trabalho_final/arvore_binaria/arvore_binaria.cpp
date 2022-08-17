/*
    Algoritmo desenvolvido durante o curso de estruturas de dados
    do professor Douglas Maioli. link do curso abaixo:
    https://cursos.professordouglasmaioli.com.br/course/view.php?id=7
*/

#include <iostream>
#include <cstddef>
#include "arvore_binaria.h"

    
using namespace std;

    ArvoreBinaria::ArvoreBinaria()
    {
        raiz = NULL;
    }

    ArvoreBinaria::~ArvoreBinaria()
    {
        deletarArvore(raiz);
    }

    void ArvoreBinaria::deletarArvore(No2* No2atual)
    {
        if(No2atual != NULL){
            deletarArvore(No2atual->filhoesquerda);
            deletarArvore(No2atual->filhodireita);

            delete No2atual;
        }
    }

    No2* ArvoreBinaria::obterRaiz()
    {
        return raiz;
    }

    bool ArvoreBinaria::estavazio()
    {
        return (raiz == NULL);
    }

    bool ArvoreBinaria::estacheio()
    {
        try
        {
            No2* temp = new No2;
            delete temp;
            return false;
        }
        catch(bad_alloc exception)
        {
            return true;
        }
        
    }

    void ArvoreBinaria::inserir(Contact contact)
    {
        if(estacheio()){
            cout << "A arvore esta cheia!\n";
            cout << "Nao foi possivel inserir este elemento!\n";
        } else{
            No2* No2voNo2 = new No2;
            No2voNo2->contact = contact;
            No2voNo2->filhodireita = NULL;
            No2voNo2->filhoesquerda = NULL;
            if (raiz == NULL){
                raiz = No2voNo2;
            } else{
                No2* temp = raiz;
                while (temp != NULL){
                    if (contact.getNome() < temp->contact.getNome()){
                        if (temp->filhoesquerda == NULL){
                            temp->filhoesquerda = No2voNo2;
                            break;
                        } else{
                            temp = temp->filhoesquerda;
                        }
                    } else{
                        if (temp->filhodireita == NULL){
                            temp->filhodireita = No2voNo2;
                            break;
                        } else{
                            temp = temp->filhodireita;
                        }
                    }
                }
            }
        }
    }

    void ArvoreBinaria::remover(Contact contact)
    {
        removerbusca(contact, raiz);
    }

    void ArvoreBinaria::removerbusca(Contact contact, No2*& No2atual)
    {
        if (contact.getNome() < No2atual->contact.getNome()){
            removerbusca(contact, No2atual->filhoesquerda);
        } else if (contact.getNome() > No2atual->contact.getNome()){
            removerbusca(contact, No2atual->filhodireita);
        } else {
            deletarNo2(No2atual);
        }
    }

    void ArvoreBinaria::deletarNo2(No2*& No2atual)
    {
        No2* temp = No2atual;
        if (No2atual->filhoesquerda == NULL){
            No2atual = No2atual->filhodireita;
            delete temp;
        } else if (No2atual->filhodireita == NULL){
            No2atual = No2atual->filhoesquerda;
            delete temp;
        } else {
            Contact ContactSucessor;
            obterSucessor(ContactSucessor, No2atual);
            No2atual->contact = ContactSucessor;
            removerbusca(ContactSucessor, No2atual->filhodireita);
        }
    }

    void ArvoreBinaria::obterSucessor(Contact & ContactSucessor, No2* temp)
    {
        temp = temp->filhodireita;
        while (temp->filhoesquerda != NULL){
            temp = temp->filhoesquerda;
        }
        ContactSucessor = temp->contact;
    }

    void ArvoreBinaria::buscar(Contact& contact, bool& busca)
    {
        busca = false;
        No2* No2atual = raiz;
        while(No2atual != NULL){
            if (contact.getNome() < No2atual->contact.getNome()){
                No2atual = No2atual->filhoesquerda;
            } else if(contact.getNome() > No2atual->contact.getNome()){
                No2atual = No2atual->filhodireita;
            } else{
                busca = true;
                contact = No2atual->contact;
                break;
            }
        }
    }

    void ArvoreBinaria::atualizar(Contact contact, bool& busca)
    {
        busca = false;
        No2* No2atual = raiz;
        while(No2atual != NULL){
            if (contact.getNome() < No2atual->contact.getNome()){
                No2atual = No2atual->filhoesquerda;
            } else if(contact.getNome() > No2atual->contact.getNome()){
                No2atual = No2atual->filhodireita;
            } else{
                busca = true;
                No2atual->contact = contact;
                break;
            }
        }
    }

