#include "arquivosh/search_administrator.h"
#include <iostream>
#include <fstream>
using namespace std;

void SearchAdministrator::pesquisarJogador() {
    cout << "Pesquisa de jogador iniciada!" << endl;
    
    ifstream fp("usuarios.txt");
    ifstream fpp("usuarios_pontos.txt");

    string name_search;
    string senha_search;
    string nome_player;
    string nome_pontos;

    // Verifica se os arquivos foram abertos com sucesso
    if (!fp.is_open() || !fpp.is_open()) {
        cout << "Ocorreu um problema ao procurar o jogador!" << endl;
        return;
    }

    cout << "Digite o nome do jogador: ";
    cin >> nome_player;

    bool jogadorEncontrado = false;

    // Lê ambos os arquivos simultaneamente, linha por linha
    while (getline(fp, name_search) && getline(fp, senha_search) && getline(fpp, nome_pontos)) {
        if (nome_player == name_search) {
            // Exibe os dados do jogador encontrado
            cout << "Nome do jogador: " << name_search << endl;
            cout << "Senha do jogador: " << senha_search << endl;
            cout << "Sua pontuação é de: " << nome_pontos << endl;
            cout << "------------------------------------------------------------!" << endl;
            jogadorEncontrado = true;
            break;  // Sai do loop assim que encontrar o jogador
        }
    }

    if (!jogadorEncontrado) {
        cout << "Jogador não encontrado!" << endl;
    }

    fp.close();
    fpp.close();
}

