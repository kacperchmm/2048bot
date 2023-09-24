#include "player.h"
#include "game.h"

using namespace std;

int main(){
    int result[18] = {0};

    //
    // test on 1000 number of games
    for(int i = 0; i < 1000; i++) {
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