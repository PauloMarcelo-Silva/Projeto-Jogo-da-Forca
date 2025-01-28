#include "arquivosh/list_administrator.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ListAdministrator::listaDeJogadores() {
    cout << "Listagem de jogadores realizada!" << endl;

    // Abrindo arquivos para leitura
    ifstream fp("usuarios.txt");
    ifstream fpp("usuarios_pontos.txt");

    // Verificando se os arquivos foram abertos corretamente
    if (!fp.is_open() || !fpp.is_open()) {
        cout << "Erro ao abrir os arquivos de usuários ou pontuação!" << endl;
        return;
    }

    string admin_nome2, admin_senha2, name_pontos, pontos_name;

    // Lendo os dados dos jogadores e suas pontuações
    while (getline(fp, admin_nome2) && getline(fp, admin_senha2) && getline(fpp, name_pontos) && getline(fpp, pontos_name)) {
        cout << "Nome do jogador: " << admin_nome2 << endl;
        cout << "Senha do jogador: " << admin_senha2 << endl;
        cout << "Sua pontuação é de: " << pontos_name << endl;
        cout << "------------------------------------------------------------!" << endl;
    }

    // Fechando os arquivos
    fp.close();
    fpp.close();

    // Espera para o usuário ver a lista
    cout << "Pressione qualquer tecla para continuar..." << endl;
    cin.get();
}

