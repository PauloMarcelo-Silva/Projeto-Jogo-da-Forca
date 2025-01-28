#include "arquivosh/login_player.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void LoginPlayer::login() {
    cout << "Login do jogador iniciado!" << endl;
    
    // Abre o arquivo para leitura
    ifstream fp("usuarios.txt");
    choice_difficulty escolha;

    string nome_jogador;
    string senha2;

    if (!fp.is_open()) {
        cout << "Ocorreu um problema ao abrir o arquivo de login!" << endl;
        return;
    }

    // Solicita o nome e senha do jogador
    cout << "Digite seu nome: ";
    getline(cin >> ws, nome);  // Usando getline para capturar o nome corretamente

    cout << "Digite sua senha: ";
    getline(cin, senha);  // Usando getline para capturar a senha corretamente

    bool usuario_encontrado = false;
    
    // Lê o arquivo linha por linha
    while (getline(fp, nome_jogador)) {
        getline(fp, senha2);  // A senha está na linha seguinte ao nome

        if (nome == nome_jogador) {
            if (senha == senha2) {
                cout << "Login bem-sucedido!" << endl;
                escolha.difficulty();
                usuario_encontrado = true;
                break;  // Sai do loop se o login for bem-sucedido
            } else {
                cout << "Senha inválida!" << endl;
                usuario_encontrado = true;
                break;  // Sai do loop se a senha for inválida
            }
        }
    }

    if (!usuario_encontrado) {
        cout << "Usuário não encontrado!" << endl;
    }

    // Fecha o arquivo
    fp.close();
}

