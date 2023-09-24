#include "player.h"
#include "game.h"
#include <bits/stdc++.h>

using namespace std;

int Player::heuristic(Game gameBoard) {
    //
    // 1. highest number in corner
    // 2. highest number on board
    // 3. earned points
    // 4. end of game
    // 

    int result = 0;
    int pointsOnMove = gameBoard.getPoints();
    pair<int, int> max_corner = gameBoard.isMaxCorner();

    // 1.
    if(max_corner.second != 0){
        result += 100000 * pointsOnMove;
    }
    // 2.
    result += max_corner.first * 500;

    // 3.
    result += pointsOnMove * 100;

    // 4. 
    if(gameBoard.isEnd()) {
        result -= 10000 * pointsOnMove;
    }

    return result;
}

pair<int, char> Player::DLS(Game gameBoard, int depth) {
    char bestMove = 0;

    if (depth == 0) {
        int result = heuristic(gameBoard);
        return make_pair(result, bestMove);
    }

    //
    // moves:
    // U - move up
    // D - move down
    // R - move right
    // L - move left
    //

    string moves = "UDLR";
    int value = -INT_MAX;

    for(int i = 0; i < 4; i++) {
        Game copy(gameBoard);
        char currentMove = moves[i];

        if (gameBoard.isMovePossible(currentMove)) {
            copy.doMove(currentMove);
            pair<int, char> newValue_move;
            newValue_move = DLS(copy, depth - 1);

            if(newValue_move.first > value) {
                value = newValue_move.first;
                bestMove = currentMove;
            }
        }
    }
    return make_pair(value, bestMove);
}