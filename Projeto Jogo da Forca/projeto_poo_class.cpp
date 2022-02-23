#include <iostream>
#include <cstring>
// importe do random
#include <cstdlib>
//------------------
#include <stdlib.h>
#include <string>
#include <ctime>
#include <ctype.h>
//-----------------
#include <fstream>
#include <conio.h>

#include "projeto_poo_class.h"

template <class GAME>
GAME estrutura_game(GAME palavra[10][25], GAME nome[10][10]);
template <class GAME>
GAME estrutura_hard_game(GAME lista_palavra[10][25]);

int main()
{
    while (1)
    {
        introduction selection;

        players player;

        registro_player registro;

        login_player login;

        login_administrador adm;

        std::cout << ("\n\n===BEM VINDO AO JOGO DA FORCA!!!===\n\n");
        std::cout << ("1 - fazer seu cadastro:") << endl;
        std::cout << ("2 - fazer seu login:") << endl;
        std::cout << ("3 - fazer seu acesso ao administrador:") << endl;
        std::cin >> selection.opcao;
        switch (selection.opcao)
        {
        case 1:
            registro.registration();
            break;
        case 2:
            login.login();
            break;
        case 3:
            adm.login_adm();
            break;
        }
    }
}
void players::setnome(string nome)
{
    this->nome = nome;
}
void players::setsenha(string senha)
{
    this->senha = senha;
}
void players::setpontos(int pontos_invocador)
{
    this->pontos_invocador = pontos_invocador;
}
void registro_player::registration()
{
    // chamada da classe q tem as propriedades do invocador
    // invocador propriedades_invocador;

    ofstream fp;
    ofstream fpp;
    // app = sempre escreve no final do arquivo e cria um arquivo caso ele nao exita.
    // out = sempre zera o arquivo e escreve dnv
    fp.open("usuarios.txt", ios::app);
    fpp.open("usuarios_pontos.txt", ios::app);

    if (!fp.is_open())
    {
        std::cout << ("ocorreu um problema ao fazer o seu cadastro!!");
        fp.close();
    }
    else
    {
        fflush(stdin);
        std::cout << "digite um nome: ";
        cin >> nome;

        fflush(stdin);
        std::cout << "digite uma senha: ";
        cin >> senha;
        //---------------------------------------
        pontos_invocador = 0;

        // grava as informaçoes passadas pelo usuario
        fp << nome << endl<< senha << endl;
        fpp << nome << endl<< pontos_invocador << endl;
        fp.close();
        fpp.close();
    }
}
void login_player::login()
{
    // abre o arquivo/ler
    ifstream fp("usuarios.txt");

    choice_difficulty escolha;

    string nome_jogador;
    string senha2;

    if (!fp.good())
    {
        std::cout << ("ocorreu um problema ao fazer o seu login!!");
        return;
    }
    else
    {
        fflush(stdin);
        std::cout << "nome:" << endl;
        std::cin >> nome;

        fflush(stdin);
        std::cout << "senha:" << endl;
        std::cin >> senha;

        while (fp)
        {
            getline(fp, nome_jogador);
            if (nome == nome_jogador)
            {
                getline(fp, senha2);
                if (senha == senha2)
                {
                    escolha.difficulty();
                }
                else
                {
                    std::cout << "senha invalida!";
                }
            }
        }
        fp.close();
    }
}
void choice_difficulty::difficulty()
{
    int dificuldade;

    // parametros recebidas da minha função

    std::cout << ("\n\n\n\n\n\n===Escolha a dificuldade do jogo:===\n\n");

    std::cout << ("\nfacil[1]:\n");
    std::cout << ("normal[2]:\n");
    std::cout << ("dificil[3]:\n\n");

    // escolha da dificuldade do jogo
    std::cin >> dificuldade;

    switch (dificuldade)
    {
    case 1:
        easy();
        break;
    case 2:
        normal();
        break;
    case 3:
        hard();
        break;
    }
}
void choice_difficulty::easy()
{
    /*unsigned int i;
    char name_jogador[nome.length()];
    for(i = 0;i < sizeof(name_jogador);i++){
        name_jogador[i] = nome[i];
    }*/

    std::cout << ("\n\n=== escolha qual tema vc deseja jogar: ===\n\n");
    std::cout << ("\n===animal[1]:===\n");
    std::cout << ("===pais[2]:===\n");
    std::cout << ("===cor[3]:===\n");
    std::cout << ("===fruta[4]:===\n\n");

    char pais[10][25] = {"brasil", "angola", "italia", "mexico", "eua", "canada", "egito", "israel", "russia", "grecia"};
    char fruta[10][25] = {"laranja", "pinha", "goiaba", "ameixa", "morango", "pitaia", "pitomba", "abacaxi", "ackee", "ciriguela"};
    char animal[10][25] = {"lemori", "leopardo", "borboleta", "cachorro", "peixe", "macaco", "ornitorrinco", "gazela", "pavao", "suricato"};
    char cor[10][25] = {"azul", "vermelho", "verde", "amarelo", "rosa", "roxo", "preto", "branco", "laranja", "cinza"};

    char nome1[1][10] = {"ANIMAL"}, nome2[1][10] = {"PAIS"}, nome3[1][10] = {"COR"}, nome4[1][10] = {"FRUTA"};

    int escolha;
    std::cin >> (escolha);

    switch (escolha)
    {
    case 1:
        estrutura_game(animal, nome1);
        break;
    case 2:
        estrutura_game(pais, nome2);
        break;
    case 3:
        estrutura_game(cor, nome3);
        break;
    case 4:
        estrutura_game(fruta, nome4);
        break;
    }
}
void choice_difficulty::normal()
{
    /*unsigned int i;
    char name_jogador[nome.length()];
    for(i = 0;i < sizeof(name_jogador);i++){
        name_jogador[i] = nome[i];
    }*/

    // arrays com as palavras do jogo
    char pais[10][25] = {"alemanha", "inglaterra", "cazaquistao", "indonesia", "armenia", "lituania", "paraguai", "macedonia", "letonia", "zimbabwe"};
    char futebol[10][25] = {"barcelona", "liverpool", "juventus", "flamengo", "independente", "Internazionale", "ferencvaros", "anderlecht", "chelsea", "olympiacos"};
    char animal[10][25] = {"cagado", "avestruz", "borboleta", "camaleao", "chimpanze", "Hipopotamo", "ornitorrinco", "gazela", "jaguatirica", "suricato"};
    char profissao[10][25] = {"frentista", "pianista", "taxista", "programador", "streamer", "pedreiro", "vendedor", "professor", "cientista", "influencer-digital"};

    char nome1[1][10] = {"PAIS"}, nome2[1][10] = {"TIME"}, nome3[1][10] = {"ANIMAL"}, nome4[1][10] = {"PROFISSAO"};

    std::cout << ("\n\n===SEU TEMA SERA SORTEADO!!===\n\n");

    // variavel para escolher aleatoriamente o tema
    srand((unsigned int)time(NULL));
    int escolha = rand() % 4 + 1;

    switch (escolha)
    {
    case 1:
        estrutura_game(pais, nome1);
        break;
    case 2:
        estrutura_game(futebol, nome2);
        break;
    case 3:
        estrutura_game(animal, nome3);
        break;
    case 4:
        estrutura_game(profissao, nome4);
        break;
    }
}
void choice_difficulty::hard()
{
    /*unsigned int i;
    char name_jogador[nome.length()];
    for(i = 0;i < sizeof(name_jogador);i++){
        name_jogador[i] = nome[i];
    }*/

    // arrays com as palavras do jogo
    char biologia[10][25] = {"arteria", "clavicula", "oncologico", "genoma", "polimerase", "nanobiotecnologia", "higienismo", "taxonomia", "protistologia", "limnologia"};
    char historia[10][25] = {"stalingrado", "herotodo", "rankeanismo", "fordismo", "paleolitico", "Internazionale", "ferencvaros", "anderlecht", "chelsea", "olympiacos"};
    char programacao[10][25] = {"cagado", "avestruz", "borboleta", "camaleao", "chimpanze", "Hipopotamo", "ornitorrinco", "gazela", "jaguatirica", "suricato"};
    char ciencia[10][25] = {"frentista", "pianista", "taxista", "programador", "streamer", "pedreiro", "vendedor", "professor", "cientista", "influencer-digital"};
    char diversidade[10][25] = {"frentista", "pianista", "taxista", "programador", "streamer", "pedreiro", "vendedor", "professor", "cientista", "influencer-digital"};

    // variavel para escolher aleatoriamente o tema
    srand((unsigned int)time(NULL));
    int escolha = rand() % 5 + 1;

    switch (escolha)
    {
    case 1:
        estrutura_hard_game(biologia);
        break;
    case 2:
        estrutura_hard_game(historia);
        break;
    case 3:
        estrutura_hard_game(programacao);
        break;
    case 4:
        estrutura_hard_game(ciencia);
        break;
    case 5:
        estrutura_hard_game(diversidade);
        break;
    }
}
template <class GAME>
GAME estrutura_game(GAME lista_palavra[10][25], GAME nome[1][10])
{
    std::cout << "\n\n===O SEU TEMA E SOBRE " << nome[0] << "===\n\n";

    choice_difficulty escolha;

    // contadores
    int vida = 6, acertos = 0, erros, i, tamanho_palavra;
    char letra[1], lacuna[25] = "_";

    // escolher a palavra aleatoria
    srand((unsigned char)time(NULL));
    int palavra_aleatoria = rand() % 10;
    std::string palavra = lista_palavra[palavra_aleatoria];
    tamanho_palavra = strlen(lista_palavra[palavra_aleatoria]);

    // for para determinar o tamanho das lacunas
    for (i = 0; i < tamanho_palavra; i++)
    {
        lacuna[i] = '-';
    }

    while (vida > 0)
    {
        erros = true;
        std::cout << "\n"
                  << lacuna << "\n";
        std::cout << ("\ndigite uma letra: ");
        std::cin >> (letra);

        for (i = 0; i < tamanho_palavra; i++)
        {
            if (letra[0] == palavra[i])
            {
                lacuna[i] = palavra[i];
                acertos++;
                erros = false;
            }
        }
        if (erros == true)
        {
            vida--;

            switch (vida)
            {
            case 5:
                std::cout << " _________\n|        |\n|       _|_\n|      /O O\\\n|      \\_V_/\n|\n|\n|\n|\n|\n|\n|\n|";
                break;

            case 4:
                std::cout << " _________\n|        |\n|       _|_\n|      /O O\\\n|      \\_V_/\n|       ¨|¨\n|        |\n|        |\n|        |\n|\n|\n|\n|";
                break;
            case 3:
                std::cout << " _________\n|        |\n|       _|_\n|      /O O\\\n|      \\_V_/\n|       ¨|¨\n|       /|\n|      / |\n|        |\n|\n|\n|\n|";
                break;
            case 2:
                std::cout << " _________\n|        |\n|       _|_\n|      /O O\\\n|      \\_V_/\n|       ¨|¨\n|       /|\\\n|      / | \\\n|        |\n|\n|\n|\n|";
                break;
            case 1:
                std::cout << " _________\n|        |\n|       _|_\n|      /O O\\\n|      \\_V_/\n|       ¨|¨\n|       /|\\\n|      / | \\\n|        |\n|       /\n|      /\n|\n|";
                break;
            case 0:
                std::cout << " _________\n|        |\n|       _|_\n|      /x x\\\n|      \\_~_/\n|       ¨|¨\n|       /|\\\n|      / | \\\n|        |\n|       / \\\n|      /   \\\n|\n|";
                std::cout << "\n\n VOCE FOI ENFORCADO!";
                std::cout << "\n A PALAVRA ERA: " << palavra << endl
                          << endl;
                break;
            }

            if (vida > 0)
            {
                std::cout << "\n voce errou! lhe restam: " << vida << " tentativas"
                          << "\n";
            }
        }

        else
        {
            if (acertos == tamanho_palavra)
            {
                std::cout << "\n\n   VOCE GANHOU!!!\n";
                std::cout << "       ___\n      /O O\\\n      \\_V_/\n        |\n       /|\\\n      / | \\\n        |\n       / \\\n      /   \\\n";
                std::cout << "\n     " << palavra << "  " << endl
                          << endl;

                // esstrutura para "salvar" o arquivo
                //estrutura do struct
                typedef struct
                {
                    string name;
                    int pontuacao_jogador = 0;
                } jogador_estrutura;
                jogador_estrutura jogador[50];

                //estrutura q passa tudo q esta salvo dentro do meu arquivos_pontos
                // abrindo conta do jogdor para add os seus pontos ganhados pela vitoria.
                ifstream fpp("usuarios_pontos.txt");
                if (!fpp.good())
                {
                    std::cout << ("ocorreu um problema ao adicionar os pontos para o jogador!");
                }
                else
                {
                   int i = 0;
                    std::string numero_lido;
                    while (!fpp.eof() && fpp.peek() != EOF)
                    {
                        getline(fpp, jogador[i].name);
                        getline(fpp, numero_lido);
                        jogador[i].pontuacao_jogador = stoi(numero_lido);
                        i++;
                    }
                }
                fpp.close();
                
                //estrutura q modifica o q o arquivo pontos apresentava 
                string nome_jogador;
                cout << "digite seu nome de login";
                cin >> nome_jogador;
                for (int i = 0; i < 50; i++)
                {
                    if (nome_jogador == jogador[i].name)
                    {
                        int pontuacao = 50;
                        jogador[i].pontuacao_jogador += pontuacao;
                    }
                }
                
                //estrutura q abre o arquivos pontos para salvar nele tudo q foi modificado
                ofstream fppp;
                fppp.open("usuarios_pontos.txt", ios::out);
                if (!fppp.good())
                {
                    std::cout << ("ocorreu um problema ao adicionar os pontos para o jogador!");
                    fppp.close();
                }
                else
                {
                    for (int i = 0; i < 50; i++)
                    {
                        if (jogador[i].name != ""){
                                fppp << jogador[i].name << endl;
                            
                                fppp << jogador[i].pontuacao_jogador << endl;
                        }
                    }
                    fppp.close();
                }
                break;
            }


            else
            {
                std::cout << ("\n VOCE ACERTOU UMA LETRA!");
            }
        }
    }
    //---------------------------------------------------------------------------------------------------
    // escolha para continuar no jogando
    int sim_nao;
    std::cout << "deseja jogar novamente? " << endl;
    std::cout << "sim[1]" << endl;
    std::cout << "nao[2]" << endl;
    cin >> sim_nao;

    if (sim_nao == 1)
    {
        escolha.difficulty();
    }
    else
    {
        main();
    }
}
template <class GAME>
GAME estrutura_hard_game(GAME lista_palavra[10][25])
{
    std::cout << "\n\n===DIFICULDADE HARD!!! ===\n\n";
    choice_difficulty escolha;
    // contadores
    int vida = 6, acertos = 0, erros, i, tamanho_palavra;
    char letra[1], lacuna[25] = "_";

    // escolher a palavra aleatoria
    srand((unsigned char)time(NULL));
    int palavra_aleatoria = rand() % 10;
    std::string palavra = lista_palavra[palavra_aleatoria];
    tamanho_palavra = strlen(lista_palavra[palavra_aleatoria]);

    // for para determinar o tamanho das lacunas
    for (i = 0; i < tamanho_palavra; i++)
    {
        lacuna[i] = '-';
    }

    while (vida > 0)
    {
        erros = true;
        std::cout << "\n"
                  << lacuna << "\n";
        std::cout << ("\ndigite uma letra: ");
        std::cin >> (letra);

        for (i = 0; i < tamanho_palavra; i++)
        {
            if (letra[0] == palavra[i])
            {
                lacuna[i] = palavra[i];
                acertos++;
                erros = false;
            }
        }
        if (erros == true)
        {
            vida--;

            switch (vida)
            {
            case 5:
                std::cout << " _________\n|        |\n|       _|_\n|      /O O\\\n|      \\_V_/\n|\n|\n|\n|\n|\n|\n|\n|";
                break;

            case 4:
                std::cout << " _________\n|        |\n|       _|_\n|      /O O\\\n|      \\_V_/\n|       ¨|¨\n|        |\n|        |\n|        |\n|\n|\n|\n|";
                break;
            case 3:
                std::cout << " _________\n|        |\n|       _|_\n|      /O O\\\n|      \\_V_/\n|       ¨|¨\n|       /|\n|      / |\n|        |\n|\n|\n|\n|";
                break;
            case 2:
                std::cout << " _________\n|        |\n|       _|_\n|      /O O\\\n|      \\_V_/\n|       ¨|¨\n|       /|\\\n|      / | \\\n|        |\n|\n|\n|\n|";
                break;
            case 1:
                std::cout << " _________\n|        |\n|       _|_\n|      /O O\\\n|      \\_V_/\n|       ¨|¨\n|       /|\\\n|      / | \\\n|        |\n|       /\n|      /\n|\n|";
                break;
            case 0:
                std::cout << " _________\n|        |\n|       _|_\n|      /x x\\\n|      \\_~_/\n|       ¨|¨\n|       /|\\\n|      / | \\\n|        |\n|       / \\\n|      /   \\\n|\n|";
                std::cout << "\n\n VOCE FOI ENFORCADO!";
                std::cout << "\n A PALAVRA ERA: " << palavra << endl
                          << endl;
                break;
            }

            if (vida > 0)
            {
                std::cout << "\n voce errou! lhe restam: " << vida << " tentativas"
                          << "\n";
            }
        }

        else
        {
            if (acertos == tamanho_palavra)
            {
                std::cout << "\n\n   VOCE GANHOU!!!\n";
                std::cout << "       ___\n      /O O\\\n      \\_V_/\n        |\n       /|\\\n      / | \\\n        |\n       / \\\n      /   \\\n";
                std::cout << "\n     " << palavra << "  " << endl
                          << endl;
                // esstrutura para "salvar" o arquivo
                typedef struct
                {
                    string name;
                    int pontuacao_jogador = 0;
                } jogador_estrutura;
                jogador_estrutura jogador[50];
                // abrindo conta do jogdor para add os seus pontos ganhados pela vitoria.
                ifstream fpp("usuarios_pontos.txt");
                if (!fpp.good())
                {
                    std::cout << ("ocorreu um problema ao adicionar os pontos para o jogador!");
                }
                else
                {
                    int i = 0;
                    while (!fpp.eof() && fpp.peek() != EOF)
                    {
                        fpp >> jogador[i].pontuacao_jogador;
                        fpp >> jogador[i].pontuacao_jogador;
                        i++;
                    }
                }
                fpp.close();
                string nome_jogador;
                cout << "digite seu nome de login";
                cin >> nome_jogador;
                for (int i = 0; i < 50; i++)
                {
                    if (nome_jogador == jogador[i].name)
                    {
                        int pontuacao = 50;
                        jogador[i].pontuacao_jogador += pontuacao;
                    }
                }
                ofstream fppp;
                fppp.open("usuarios_pontos.txt", ios::out);
                if (!fppp.good())
                {
                    std::cout << ("ocorreu um problema ao adicionar os pontos para o jogador!");
                    fppp.close();
                }
                else
                {
                    for (int i = 0; i < 50; i++)
                    {
                        fppp << jogador[i].name << endl;
                        if (jogador[i].pontuacao_jogador != 0)
                        {
                            fppp << jogador[i].pontuacao_jogador << endl;
                        }
                    }
                    fppp.close();
                }
                break;
            }

            else
            {
                std::cout << ("\n VOCE ACERTOU UMA LETRA!");
            }
        }
    }
    /*//abrindo conta do jogdor para add os seus pontos ganhados pela vitoria.
        ofstream fpp;
        fpp.open("usuarios_pontos.txt",ios::app);
        string name_pontos;
        if (!fpp.good())
        {
            std::cout << ("ocorreu um problema ao adicionar os pontos para o jogador!");
        }
        else{
            fpp << name_jogador << endl << pontos_invocador << endl;
            fpp.close();
        }
    */
    //---------------------------------------------------------------------------------------------------
    // escolha para continuar no jogando
    int sim_nao;
    std::cout << "deseja jogar novamente? " << endl;
    std::cout << "sim[1]" << endl;
    std::cout << "nao[2]" << endl;
    cin >> sim_nao;

    if (sim_nao == 1)
    {
        escolha.difficulty();
    }
    else
    {
        main();
    }
}
void administrador::setnome_admin(string admin)
{
    this->admin = admin;
}
void administrador::setsenha_admin(string senha_admin)
{
    this->senha_admin = senha_admin;
}
void login_administrador::login_adm()
{
    // classes
    lista_administrador lista;
    pesquisar_administrador pesquisar;

    admin = "paulo";
    senha_admin = "projetopoo";

    string x;
    string y;
    std::cout << "digite o nome do adm:";
    std::cin >> x;
    std::cout << "digite a senha do adm:";
    std::cin >> y;
    if (x == admin)
    {
        if (y == senha_admin)
        {
            int escolha_adm;
            std::cout << ("1 - ver lista de jogadores:") << endl;
            std::cout << ("2 - procurar jogador:") << endl;
            std::cin >> escolha_adm;

            switch (escolha_adm)
            {
            case 1:
                lista.lista_de_jogadores();
                break;
            case 2:
                pesquisar.pesquisar_jogador();
                break;
            default:
                break;
            }
        }
    }
}
void lista_administrador::lista_de_jogadores()
{
    ifstream fp("usuarios.txt");
    ifstream fpp("usuarios_pontos.txt");

    string admin_nome2;
    string admin_senha2;
    string name_pontos;
    string pontos_name;
    if (!fp.good())
    {
        std::cout << ("ocorreu um problema ao entrar na lista de registro!!");
        return;
    }
    else
    {
        while(!fp.eof() && fp.peek() != EOF){
            //while(fpp.peek() != EOF){
                getline(fp, admin_nome2);
                getline(fp, admin_senha2);
                getline(fpp, name_pontos);
                getline(fpp, pontos_name);
                
                std::cout << "nome do jogador: " << admin_nome2 << endl;
                std::cout << "senha do jogador: " << admin_senha2 << endl;
                std::cout << "sua pontuação é de :" << pontos_name << endl;
                std::cout << "------------------------------------------------------------!" << endl;
            //}
        }        
        fp.close();
        fpp.close();
        getch();
    }
}  
void pesquisar_administrador::pesquisar_jogador()
{
    ifstream fp("usuarios.txt");
    ifstream fpp("usuarios_pontos.txt");
    string name_search;
    string senha_search;
    string nome_player;
    string pontos;
    string nome_pontos;

    if (!fp.good())
    {
        std::cout << ("ocorreu um problema ao procurar um player!");
    }
    else
    {
        fflush(stdin);
        std::cout << "digite o nome do jogador" << endl;
        std::cin >> nome_player;

        while (fp)
        {
            while (fpp)
            {
                getline(fp, name_search);
                getline(fp, senha_search);
                getline(fpp, nome_pontos);
                getline(fpp, nome_pontos);
                if (nome_player == name_search)
                {
                    std::cout << "nome do jogador: " << name_search << endl;
                    std::cout << "senha do jogador: " << senha_search << endl;
                    std::cout << "sua pontuação é de :" << nome_pontos << endl;
                    std::cout << "------------------------------------------------------------!" << endl;
                }
            }
        }
    }
    fp.close();
    fpp.close();
    getch();
}