#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

template <class GAME>
GAME estrutura_game(GAME lista_palavra[10][25], GAME nome[1][10]);

template <class GAME>
GAME estrutura_hard_game(GAME lista_palavra[10][25]);

class choice_difficulty {
public:
    void difficulty();
};

#endif
