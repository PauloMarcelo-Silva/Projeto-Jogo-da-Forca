#include "arquivosh/game.h"

// Função para escolher a palavra aleatória e jogar no modo normal
template <class GAME>
GAME estrutura_game(GAME lista_palavra[10][25], GAME nome[1][10])
{
    std::cout << "\n\n===O SEU TEMA E SOBRE " << nome[0] << "===\n\n";

    choice_difficulty escolha;
    int vida = 6, acertos = 0, erros, i, tamanho_palavra;
    char letra[1], lacuna[25] = "_";

    srand((unsigned char)time(NULL));
    int palavra_aleatoria = rand() % 10;
    std::string palavra = lista_palavra[palavra_aleatoria];
    tamanho_palavra = strlen(lista_palavra[palavra_aleatoria]);

    for (i = 0; i < tamanho_palavra; i++)
    {
        lacuna[i] = '-';
    }

    while (vida > 0)
    {
        erros = true;
        std::cout << "\n" << lacuna << "\n";
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
            case 5: // Imagens do enforcado
                std::cout << " _________\n|        |\n|       _|_\n|      /O O\\\n|      \\_V_/\n|\n|\n|\n|\n|\n|\n|\n|";
                break;
            // Outros casos para desenhar o enforcado em diferentes vidas
            }

            if (vida > 0)
            {
                std::cout << "\n voce errou! lhe restam: " << vida << " tentativas" << "\n";
            }
        }
        else
        {
            if (acertos == tamanho_palavra)
            {
                std::cout << "\n\n   VOCE GANHOU!!!\n";
                std::cout << "       ___\n      /O O\\\n      \\_V_/\n        |\n       /|\\\n      / | \\\n        |\n       / \\\n      /   \\\n";
                std::cout << "\n     " << palavra << "  " << std::endl << std::endl;

                typedef struct
                {
                    std::string name;
                    int pontuacao_jogador = 0;
                } jogador_estrutura;
                jogador_estrutura jogador[50];

                std::ifstream fpp("usuarios_pontos.txt");
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
                        std::getline(fpp, jogador[i].name);
                        std::getline(fpp, numero_lido);
                        jogador[i].pontuacao_jogador = std::stoi(numero_lido);
                        i++;
                    }
                }
                fpp.close();
                
                // Atualizando os pontos do jogador
                std::string nome_jogador;
                std::cout << "digite seu nome de login";
                std::cin >> nome_jogador;
                for (int i = 0; i < 50; i++)
                {
                    if (nome_jogador == jogador[i].name)
                    {
                        int pontuacao = 50;
                        jogador[i].pontuacao_jogador += pontuacao;
                    }
                }

                std::ofstream fppp;
                fppp.open("usuarios_pontos.txt", std::ios::out);
                if (!fppp.good())
                {
                    std::cout << ("ocorreu um problema ao adicionar os pontos para o jogador!");
                }
                else
                {
                    for (int i = 0; i < 50; i++)
                    {
                        if (jogador[i].name != "")
                        {
                            fppp << jogador[i].name << std::endl;
                            fppp << jogador[i].pontuacao_jogador << std::endl;
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

    int sim_nao;
    std::cout << "deseja jogar novamente? " << std::endl;
    std::cout << "sim[1]" << std::endl;
    std::cout << "nao[2]" << std::endl;
    std::cin >> sim_nao;

    if (sim_nao == 1)
    {
        escolha.difficulty();
    }
    else
    {
        main();
    }
}

// Função para escolher o modo difícil
template <class GAME>
GAME estrutura_hard_game(GAME lista_palavra[10][25])
{
    std::cout << "\n\n===DIFICULDADE HARD!!! ===\n\n";
    choice_difficulty escolha;
    int vida = 6, acertos = 0, erros, i, tamanho_palavra;
    char letra[1], lacuna[25] = "_";

    srand((unsigned char)time(NULL));
    int palavra_aleatoria = rand() % 10;
    std::string palavra = lista_palavra[palavra_aleatoria];
    tamanho_palavra = strlen(lista_palavra[palavra_aleatoria]);

    for (i = 0; i < tamanho_palavra; i++)
    {
        lacuna[i] = '-';
    }

    while (vida > 0)
    {
        erros = true;
        std::cout << "\n" << lacuna << "\n";
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
            // Outros casos para desenhar o enforcado em diferentes vidas
            }

            if (vida > 0)
            {
                std::cout << "\n voce errou! lhe restam: " << vida << " tentativas" << "\n";
            }
        }
        else
        {
            if (acertos == tamanho_palavra)
            {
                std::cout << "\n\n   VOCE GANHOU!!!\n";
                std::cout << "       ___\n      /O O\\\n      \\_V_/\n        |\n       /|\\\n      / | \\\n        |\n       / \\\n      /   \\\n";
                std::cout << "\n     " << palavra << "  " << std::endl << std::endl;
                break;
            }
            else
            {
                std::cout << ("\n VOCE ACERTOU UMA LETRA!");
            }
        }
    }
    return 0;
}

