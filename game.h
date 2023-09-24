#ifndef game_h
#define game_h
#include <utility>
#include <iostream>
#include <math.h>
using namespace std;


class Game {
    int _board[4][4];
    int _points;

    public:
    Game();

    int getPoints();
    int getCell(int, int);
    void newNumber(int);
    void print();
    void left();
    void right();
    void up();
    void down();
    bool isMovePossible(char);
    int howManyZeros();
    //
    // functions used in dls algorithm
    //
    void doMove(char);
    bool isEnd();
    pair<int, int> isMaxCorner();
    int getCorner(int, int);
};

#endif