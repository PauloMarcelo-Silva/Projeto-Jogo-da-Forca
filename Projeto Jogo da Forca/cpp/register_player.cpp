#include "arquivosh/register_player.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void RegisterPlayer::registration() {
    cout << "Registro do jogador iniciado!" << endl;

    ofstream fp("usuarios.txt", ios::app);
    ofstream fpp("usuarios_pontos.txt", ios::app);

    // Verifica se ambos os arquivos foram abertos corretamente
    if (!fp.is_open() || !fpp.is_open()) {
        cerr << "Erro: Não foi possível abrir os arquivos para gravação." << endl;
        return;
    }

    // Solicita e valida o nome do usuário
    cout << "Digite um nome: ";
    getline(cin >> ws, nome); // ws para consumir espaço em branco residual

    // Solicita e valida a senha do usuário
    cout << "Digite uma senha: ";
    getline(cin >> ws, senha);

    // Inicializa os pontos do invocador
    pontos_invocador = 0;

    // Grava as informações nos arquivos
    try {
        fp << nome << endl << senha << endl;
        fpp << nome << endl << pontos_invocador << endl;
        cout << "Cadastro realizado com sucesso!" << endl;
    } catch (const ofstream::failure& e) {
        cerr << "Erro ao gravar nos arquivos: " << e.what() << endl;
    }

    // Fecha os arquivos
    fp.close();
    fpp.close();
}

