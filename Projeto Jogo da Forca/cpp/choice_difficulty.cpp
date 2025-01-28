#include "arquivosh/choice_difficulty.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void ChoiceDifficulty::difficulty() {
    cout << "Escolha de dificuldade iniciada!" << endl;
    int dificuldade;

    std::cout << ("\n\n\n\n\n\n===Escolha a dificuldade do jogo:===\n\n");

    std::cout << ("\nfacil[1]:\n");
    std::cout << ("normal[2]:\n");
    std::cout << ("dificil[3]:\n\n");

    std::cin >> dificuldade;

    switch (dificuldade) {
    case 1:
        easy();
        break;
    case 2:
        normal();
        break;
    case 3:
        hard();
        break;
    default:
        cout << "Escolha inválida!" << endl;
    }
}

void ChoiceDifficulty::easy() {
    cout << "Modo fácil selecionado!" << endl;

    // Vetores de palavras
    std::vector<std::string> pais = {"brasil", "angola", "italia", "mexico", "eua", "canada", "egito", "israel", "russia", "grecia"};
    std::vector<std::string> fruta = {"laranja", "pinha", "goiaba", "ameixa", "morango", "pitaia", "pitomba", "abacaxi", "ackee", "ciriguela"};
    std::vector<std::string> animal = {"lemori", "leopardo", "borboleta", "cachorro", "peixe", "macaco", "ornitorrinco", "gazela", "pavao", "suricato"};
    std::vector<std::string> cor = {"azul", "vermelho", "verde", "amarelo", "rosa", "roxo", "preto", "branco", "laranja", "cinza"};

    int escolha;
    std::cout << "\n\n=== escolha qual tema vc deseja jogar: ===\n\n";
    std::cout << "\n===animal[1]:===\n";
    std::cout << "===pais[2]:===\n";
    std::cout << "===cor[3]:===\n";
    std::cout << "===fruta[4]:===\n\n";

    std::cin >> escolha;

    switch (escolha) {
    case 1:
        estruture_game(animal, "ANIMAL");
        break;
    case 2:
        estruture_game(pais, "PAIS");
        break;
    case 3:
        estruture_game(cor, "COR");
        break;
    case 4:
        estruture_game(fruta, "FRUTA");
        break;
    default:
        cout << "Escolha inválida!" << endl;
    }
}

void ChoiceDifficulty::normal() {
    cout << "Modo normal selecionado!" << endl;

    // Vetores de palavras
    std::vector<std::string> pais = {"alemanha", "inglaterra", "cazaquistao", "indonesia", "armenia", "lituania", "paraguai", "macedonia", "letonia", "zimbabwe"};
    std::vector<std::string> futebol = {"barcelona", "liverpool", "juventus", "flamengo", "independente", "Internazionale", "ferencvaros", "anderlecht", "chelsea", "olympiacos"};
    std::vector<std::string> animal = {"cagado", "avestruz", "borboleta", "camaleao", "chimpanze", "Hipopotamo", "ornitorrinco", "gazela", "jaguatirica", "suricato"};
    std::vector<std::string> profissao = {"frentista", "pianista", "taxista", "programador", "streamer", "pedreiro", "vendedor", "professor", "cientista", "influencer-digital"};

    srand((unsigned int)time(NULL));
    int escolha = rand() % 4 + 1;

    switch (escolha) {
    case 1:
        estruture_game(pais, "PAIS");
        break;
    case 2:
        estruture_game(futebol, "TIME");
        break;
    case 3:
        estruture_game(animal, "ANIMAL");
        break;
    case 4:
        estruture_game(profissao, "PROFISSAO");
        break;
    }
}

void ChoiceDifficulty::hard() {
    cout << "Modo difícil selecionado!" << endl;

    // Vetores de palavras
    std::vector<std::string> biologia = {"arteria", "clavicula", "oncologico", "genoma", "polimerase", "nanobiotecnologia", "higienismo", "taxonomia", "protistologia", "limnologia"};
    std::vector<std::string> historia = {"stalingrado", "herotodo", "rankeanismo", "fordismo", "paleolitico", "internacional", "ferencvaros", "anderlecht", "chelsea", "olympiacos"};
    std::vector<std::string> programacao = {"cagado", "avestruz", "borboleta", "camaleao", "chimpanze", "Hipopotamo", "ornitorrinco", "gazela", "jaguatirica", "suricato"};
    std::vector<std::string> ciencia = {"frentista", "pianista", "taxista", "programador", "streamer", "pedreiro", "vendedor", "professor", "cientista", "influencer-digital"};
    std::vector<std::string> diversidade = {"frentista", "pianista", "taxista", "programador", "streamer", "pedreiro", "vendedor", "professor", "cientista", "influencer-digital"};

    srand((unsigned int)time(NULL));
    int escolha = rand() % 5 + 1;

    switch (escolha) {
    case 1:
        estruture_game(biologia, "BIOLOGIA");
        break;
    case 2:
        estruture_game(historia, "HISTORIA");
        break;
    case 3:
        estruture_game(programacao, "PROGRAMACAO");
        break;
    case 4:
        estruture_game(ciencia, "CIENCIA");
        break;
    case 5:
        estruture_game(diversidade, "DIVERSIDADE");
        break;
    }
}

void ChoiceDifficulty::estruture_game(const std::vector<std::string>& palavras, const std::string& nome) {
    // A lógica do jogo para manipular palavras e nome vai aqui
    cout << "Iniciando o jogo com o tema " << nome << "!" << endl;
    // Aqui você poderia embaralhar as palavras, etc.
}
