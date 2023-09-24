#include "game.h"

#include <bits/stdc++.h>

using namespace std;

Game::Game() {
    this->_points = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            this->_board[i][j] = 0;
        }
    }
    newNumber(0);
    newNumber(3);
}

int Game::getPoints(){
    return _points;
}

int Game::getCell(int row, int column){
    return this->_board[row][column];
}

void Game::newNumber(int modifier) {
    srand(static_cast<unsigned>(std::time(nullptr)));

    int random = std::rand() % 16 + 1;

    int avaiblePositions[16][2];
    int zerosCounter = 0;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (this->_board[i][j] == 0) {
                avaiblePositions[zerosCounter][0] = i;
                avaiblePositions[zerosCounter][1] = j;
                zerosCounter++;
            }
        }
    }

    if (zerosCounter > 0) {
        int randomIndex = rand() % zerosCounter;
        int numberToPlace = 2;

        if((random + modifier) % 6 == 0) {
            numberToPlace = 4;
        }

        int rowIndex = avaiblePositions[randomIndex][0];
        int columnIndex = avaiblePositions[randomIndex][1];

        this->_board[rowIndex][columnIndex] = numberToPlace;
    }
}

void Game::print(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << this->_board[i][j] << " ";
        }
        cout << endl;
    }
}

void Game::left() {
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 3; j >= 1; j--) {
                if (this->_board[i][j - 1] == 0) {
                    this->_board[i][j - 1] = this->_board[i][j];
                    this->_board[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (this->_board[i][j] == this->_board[i][j + 1]) {
                this->_board[i][j] = this->_board[i][j] * 2;
                this->_board[i][j + 1] = 0;
                _points += this->_board[i][j];
            }
        }
    }

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 3; j >= 1; j--) {
                if (this->_board[i][j - 1] == 0) {
                    this->_board[i][j - 1] = this->_board[i][j];
                    this->_board[i][j] = 0;
                }
            }
        }
    }
}

void Game::right() {
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 3; j >= 1; j--) {
                if (this->_board[i][j] == 0) {
                this->_board[i][j] = this->_board[i][j - 1];
                this->_board[i][j - 1] = 0;
                }
            }
        }
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j >= 1; j--) {
            if (this->_board[i][j] == this->_board[i][j - 1]) {
                this->_board[i][j] = this->_board[i][j - 1] * 2;
                this->_board[i][j - 1] = 0;
                _points += this->_board[i][j];

            }
        }
    }

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 3; j >= 1; j--) {
                if (this->_board[i][j] == 0) {
                this->_board[i][j] = this->_board[i][j - 1];
                this->_board[i][j - 1] = 0;
                }
            }
        }
    }
}

void Game::up() {
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (this->_board[j][i] == 0) {
                this->_board[j][i] = this->_board[j + 1][i];
                this->_board[j + 1][i] = 0;
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (this->_board[j][i] == this->_board[j + 1][i]) {
                this->_board[j][i] = this->_board[j + 1][i] * 2;
                this->_board[j + 1][i] = 0;
                _points += this->_board[j][i];
            }
        }
    }

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (this->_board[j][i] == 0) {
                    this->_board[j][i] = this->_board[j + 1][i];
                    this->_board[j + 1][i] = 0;
                }
            }
        }
    }
    }

void Game::down() {
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (this->_board[j + 1][i] == 0) {
                    this->_board[j + 1][i] = this->_board[j][i];
                    this->_board[j][i] = 0;
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 3; j >= 1; j--) {
            if (this->_board[j][i] == this->_board[j - 1][i]) {
                this->_board[j][i] = this->_board[j][i] * 2;
                this->_board[j - 1][i] = 0;
                _points += this->_board[j][i];
            }
        }
    }

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (this->_board[j + 1][i] == 0) {
                this->_board[j + 1][i] = this->_board[j][i];
                this->_board[j][i] = 0;
                }
            }
            }
    }
}

bool Game::isMovePossible(char move) {
    Game copied(*this);
    copied.doMove(move);

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(this->getCell(i, j) != copied.getCell(i, j)){
                return true;
            }
        }
    }
    return false;
}

int Game::howManyZeros(){
    int counter = 0;
    for(int i = 0; i < 4; i++){
        for (int j = 0 ; j < 4; j++){
            if(this->_board[i][j] == 0) counter++;
        }
    }
    return counter;
}

bool Game::isEnd(){
    Game copied(*this);

    bool moveLeft = copied.isMovePossible('L');
    bool moveRight = copied.isMovePossible('R');
    bool moveDown = copied.isMovePossible('D');
    bool moveUp = copied.isMovePossible('U');

    if(!moveLeft && !moveRight && !moveDown && !moveUp){
        return true;
    }

    return false;
}

void Game::doMove(char move) {
    switch (move) {
        case 'U':
            up();
            break;

        case 'L':
            left();
            break;

        case 'D':
            down();
            break;

        case 'R':
            right();
            break;
    }       
}

pair<int, int> Game::isMaxCorner() {
    //
    // result pair is (max number, which corner) 
    //
    // which corner:
    // 0 - inside
    // 1 - upper left
    // 2 - upper right
    // 3 - lower left
    // 4 - lower right
    //

    int whichCorner = 0;
    int max = -1;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(this->_board[i][j] > max) {
                max = this->_board[i][j];
                whichCorner = getCorner(i, j);
            }
            if(max == this->_board[i][j] && whichCorner == 0) {
                whichCorner = getCorner(i, j);
            }
        }
    }
    return make_pair(max, whichCorner);
}

int Game::getCorner(int row, int column){
    int cornerPlace;
    if(row == 0 && column == 0) {
        cornerPlace = 1;
    }
    else if(row == 0 && column == 3) {
        cornerPlace = 2;
    }
    else if(row == 3 && column == 0) {
        cornerPlace = 3;
    }
    else if(row == 3 && column == 3) {
        cornerPlace = 4;
    }
    else {
        cornerPlace = 0;
    }

    return cornerPlace;
}