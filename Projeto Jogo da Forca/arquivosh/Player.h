#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Players {
protected:
    string nome;
    string senha;
    int pontos_invocador;

public:
    void setNome(const string& nome);
    void setSenha(const string& senha);
    void setPontos(int pontosInvocador);
};

#endif // PLAYER_H

