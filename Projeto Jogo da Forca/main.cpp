#include "arquivosh/login_administrator.h"

#include "arquivosh/login_player.h"

#include <iostream>

using namespace std;

int main() {
    int escolha;
    cout << "=====================================" << endl;
    cout << "    Bem-vindo ao Jogo da Administração" << endl;
    cout << "=====================================" << endl;
    
    cout << "1 - Login como Administrador" << endl;
    cout << "2 - Login como Jogador" << endl;
    cout << "0 - Sair" << endl;
    cout << "Escolha uma opção: ";
    cin >> escolha;
    
    switch (escolha) {
        case 1: {
            LoginAdministrator loginAdmin;
            loginAdmin.loginAdm();
            break;
        }
        case 2: {
            LoginPlayer loginPlayer;
            loginPlayer.loginPlayer();
            break;
        }
        case 0:
            cout << "Saindo do sistema..." << endl;
            return 0;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
            break;
    }
    
    cout << "=====================================" << endl;
    cout << "      Programa finalizado. Obrigado!" << endl;
    cout << "=====================================" << endl;
    
    return 0;
}
