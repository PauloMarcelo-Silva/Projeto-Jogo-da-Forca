#ifndef CHOICE_DIFFICULTY_H
#define CHOICE_DIFFICULTY_H

#include "player.h"
#include <vector>
#include <string>

class ChoiceDifficulty : public Players {
public:
    void difficulty();
    void easy();
    void normal();
    void hard();
    void estruture_game(const std::vector<std::string>& palavras, const std::string& nome);
};

#endif // CHOICE_DIFFICULTY_H


