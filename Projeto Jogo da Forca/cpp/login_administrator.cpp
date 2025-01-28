#include "arquivosh/login_administrator.h"
#include <iostream>
#include <string>
using namespace std;

void LoginAdministrator::loginAdm() {
    cout << "Login do administrador iniciado!" << endl;

    // Definindo as credenciais do administrador (exemplo)
    const string admin = "paulo"; // Isso pode ser carregado de um arquivo de configuração
    const string senha_admin = "projetopoo"; // Também pode ser carregado de uma fonte segura

    string x, y;
    
    // Solicitando o nome de usuário e senha
    cout << "Digite o nome do administrador: ";
    getline(cin, x);  // Usando getline para capturar todo o nome, incluindo espaços
    cout << "Digite a senha do administrador: ";
    getline(cin, y);  // Usando getline para capturar a senha

    // Validando as credenciais
    if (x == admin && y == senha_admin) {
        int escolha_adm;

        // Exibindo opções para o administrador
        cout << "\nEscolha uma opção:" << endl;
        cout << "1 - Ver lista de jogadores" << endl;
        cout << "2 - Procurar jogador" << endl;
        cout << "Digite a opção desejada: ";
        cin >> escolha_adm;

        // Tratamento da escolha do administrador
        switch (escolha_adm) {
        case 1:
            lista.lista_de_jogadores(); // Mostra lista de jogadores
            break;
        case 2:
            pesquisar.pesquisar_jogador(); // Busca por jogador
            break;
        default:
            cout << "Opção inválida!" << endl;
            break;
        }
    } else {
        cout << "Credenciais inválidas!" << endl; // Mensagem caso as credenciais não sejam corretas
    }
}

