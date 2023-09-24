#include <bits/stdc++.h>

using namespace std;

class Game {
    int _board[4][4];
    int _points;

    public:
    Game() {
        this->_points = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                this->_board[i][j] = 0;
            }
        }
        newNumber(0);
        newNumber(3);
    }

    int getPoints(){
        return _points;
    }

    int getCell(int row, int column){
        return this->_board[row][column];
    }

    void newNumber(int modifier) {
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

    void print(){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cout << this->_board[i][j] << " ";
            }
            cout << endl;
        }
    }

    void left() {
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

    void right() {
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

    void up() {
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

    void down() {
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

    bool isMovePossible(char move) {
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

    int howManyZeros(){
        int counter = 0;
        for(int i = 0; i < 4; i++){
            for (int j = 0 ; j < 4; j++){
                if(this->_board[i][j] == 0) counter++;
            }
        }
        return counter;
    }

    bool isEnd(){
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

    //
    // functions used in dls algorithm
    //

    void doMove(char move) {
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

    pair<int, int> isMaxCorner() {
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

    int getCorner(int row, int column){
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
};


class Player {
    public:
    int heuristic(Game gameBoard) {
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

    pair<int, char> DLS(Game gameBoard, int depth) {
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
};

int main(){
    int result[18] = {0};

    //
    // test on 1000 number of games
    for(int i = 0; i < 100; i++) {
        Game g;
        Player p;

        //
        // game loop
        //
        while(!g.isEnd()) {
            pair<int,char> move = p.DLS(g, 6);

            if(move.second == 'U') {
                g.up();
            }
            else if(move.second == 'L') {
                g.left();
            }
            else if(move.second == 'D') {
                g.down();
            }
            else if(move.second == 'R') {
                g.right();
            }
            g.newNumber(0);
        }

        int res = log2(g.isMaxCorner().first);
        result[res]++;
    }

    //
    // which numbers "won" game
    //
    for(int i = 0; i < 18; i++) {
        cout << pow(2, i) << " = " << result[i] << endl;
    }

    return 0;
}