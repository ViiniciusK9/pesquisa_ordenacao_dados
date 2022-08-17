#include <iostream>
#include "./arvore_avl/arvoreAVL.h"
#include "./arvore_binaria/arvore_binaria.h"
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <fstream>

using namespace std;

// função responsavel por formatar a data de (dia,mes,ano) para (dia/mes/ano)
string data_feia_to_data_bonita(string data)
{
    string aux = data + ",";
    string aux_r = "";
    string space_delimiter = ",";
    vector<string> words{};

    size_t pos = 0;
    while ((pos = aux.find(space_delimiter)) != string::npos) {
        words.push_back(aux.substr(0, pos));
        aux.erase(0, pos + space_delimiter.length());
    }

    aux_r += words[0] + "/";
    aux_r += words[1] + "/";
    aux_r += words[2];
       
    return aux_r;
}


int main(){
    ArvoreAVL TreeContatcAVL;
    ArvoreBinaria TreeContatcB;

    // variaveis auxiliares
    int opcao;
    string name, phone, email;
    int day, month, year;


    // carregar dados iniciar do arquivo dados.txt

    ifstream arquivo;
    string aux;
    const int MAX = 300;
    char c[MAX];
    
    arquivo.open("dados.txt", ios::in);
    if (!arquivo) {
        cout << "Unable to open file";
    }
    
    while (arquivo) {
        arquivo.getline(c, MAX);
        aux = c;
        string space_delimiter = ",";
        vector<string> words{};

        size_t pos = 0;
        while ((pos = aux.find(space_delimiter)) != string::npos) {
            words.push_back(aux.substr(0, pos));
            aux.erase(0, pos + space_delimiter.length());
        }
        
        if (arquivo.eof())
        {
            break;
        }
        
        name = words[0];
        day = stoi(words[1]);
        month = stoi(words[2]);
        year = stoi(words[3]);
        email = words[4];
        phone = words[5];
        //cout << name << day << month << year << email << phone << '\n';

        Date date(day, month, year);
        Date date2(day, month, year);
        Contact contact(name, date, email, phone);
        Contact contact2(name, date2, email, phone);
                  
        TreeContatcAVL.inserir(contact);
        TreeContatcB.inserir(contact2);
        if(arquivo.eof()){
            break;
        }
    }
    
    arquivo.close();

    do{
        cout << '\n';
        cout << "Digite 1 para inserir um contato!\n";
        cout << "Digite 2 para deletar um contato!\n";
        cout << "Digite 3 para listar os contatos!\n";
        cout << "Digite 4 para consultar um contato!\n";
        cout << "Digite 5 para atualizar os campos de um contato!\n";
        cout << "Digite 6 para armazenar os dados em um arquivo!\n";
        cout << "Digite 10 para parar o programa!\n";
        cin >> opcao;
        bool busca = false;

        switch (opcao)
        {
        case 1:
        {
            cout << "Digite o nome do contato:\n";
            cin >> name;
            cout << "Digite o dia do nascimento:\n";
            cin >> day;
            cout << "Digite o mes do nascimento:\n";
            cin >> month;
            cout << "Digite o ano do nascimento:\n";
            cin >> year;
            cout << "Digite o email do contato:\n";
            cin >> email;
            cout << "Digite o phone do contato:\n";
            cin >> phone;

            Date date(day, month, year);
            Contact contact(name, date, email, phone);
            Contact contact2(name, date, email, phone);
            if (TreeContatcAVL.estaCheio()){
                cout << "A Árvore esta cheia!\n";
                cout << "Nao foi possivel inserir o contato+!\n";
            } else{            
                TreeContatcAVL.inserir(contact);
                TreeContatcB.inserir(contact2);
                cout << "\nContato foi inserido com sucesso!\n";
            }
            break;
        }

        case 2:
        {
            cout << "Digite o nome do contato a ser removido!\n";
            cin >> name;
            email = "";
            phone = "";
            Date date(1, 1, 1);
            Contact contact(name, date, email, phone);
            Contact contact2(name, date, email, phone);
            TreeContatcAVL.remover(contact);
            TreeContatcB.remover(contact2);
            cout << "\nContato " << name << " removido com sucesso!\n";
            break;
        }
        case 3:
        {
            cout << "\nLista de contatos:\n";
            TreeContatcAVL.imprimirEmOrdem(TreeContatcAVL.getRaiz());
            break;   
        }     
        case 4:
        {
            cout << "Digite o nome do contato a ser buscado!\n";
            cin >> name;
            email = "";
            phone = "";
            Date date(1, 1, 1);
            Contact contact(name, date, email, phone);
            TreeContatcB.buscar(contact, busca);
            if (busca){
                cout << "\nContato encontrado!\n";
                cout << "Nome: " << contact.getNome() << endl;
                cout << "Data de nascimento: " << data_feia_to_data_bonita(contact.getDate()) << endl;
                cout << "Email: " << contact.getEmail() << endl;
                cout << "Phone: " << contact.getPhone() << endl;
            } else{
                cout << "\nContato nao encontrado!\n";
            }     
            break;
        }
        case 5:
        {
            cout << "Digite o nome do contato:\n";
            cin >> name;
            cout << "Digite o dia do nascimento:\n";
            cin >> day;
            cout << "Digite o mes do nascimento:\n";
            cin >> month;
            cout << "Digite o ano do nascimento:\n";
            cin >> year;
            cout << "Digite o email do contato:\n";
            cin >> email;
            cout << "Digite o phone do contato:\n";
            cin >> phone;

            Date date(day, month, year);
            Contact contact(name, date, email, phone);
            Contact contact2(name, date, email, phone);

            TreeContatcB.atualizar(contact, busca);
            TreeContatcAVL.atualizar(contact2, busca);
            if (busca)
            {
                cout << "\nContato atualizado com sucesso!\n";
            } else {
                cout << "\nContato não encontrado\n";
            }
            
            break;
        }

        case 6:
        {
            TreeContatcAVL.salvar(TreeContatcAVL.getRaiz());
            cout << "\nOs dados foram salvos com sucesso!\n";
            break;
        }
        default:
            if(opcao != 10){
                cout << "Opcao invalida!\n";
            }
            break;
        }
    } while (opcao != 10);

    return 0;
}

// g++ date.cpp contact.cpp ./arvore_binaria/arvore_binaria.cpp ./arvore_avl/arvoreAVL.cpp main.cpp -o teste