#include "arquivosh/player.h"

void Players::setNome(const string& nome) { 
    this->nome = nome;
}

void Players::setSenha(const string& senha) {
    this->senha = senha;
}

void Players::setPontos(int pontosInvocador) {
    this->pontos_invocador = pontosInvocador;
}
