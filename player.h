#ifndef player_h
#define player_h
#include <utility>
#include "game.h"

using namespace std;

class Player {
    public:
    int heuristic(Game);
    pair<int, char> DLS(Game, int);
};

#endif