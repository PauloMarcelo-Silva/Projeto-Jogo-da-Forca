#ifndef PROJETO_POO_CLASS_H_INCLUDED
#define PROJETO_POO_CLASS_H_INCLUDED

#include <string>
using namespace std;

//classes do jogo

class introduction{       
    public:
        int opcao;
};
class players : public introduction{
    protected:
        string nome;
        string senha;
        int pontos_invocador;
        
    public:
        void setnome(string nome);
        void setsenha(string senha);
        void setpontos(int pontos_invocador);
};
class registro_player : public players{
    public:
        void registration();

};
class login_player : public players{
    public:
        void login();

};
class choice_difficulty  : public players{
    public:
        void difficulty();
        void easy();
        void normal();
        void hard();
};
class administrador{
    protected:
        string admin;
        string senha_admin;
    public:
        void setnome_admin(string admin);
        void setsenha_admin(string setsenha_admin);
};
class login_administrador : public administrador{
    public:
        void login_adm();
};
class lista_administrador : public login_administrador{
    public:
        void lista_de_jogadores();

};
class pesquisar_administrador : public login_administrador{
    public:
        void pesquisar_jogador();
};

#endif // PROJETO_POO_CLASS_H_INCLUDED      