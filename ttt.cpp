#include <iostream>
#include <vector>
#include "ttt_hd.hpp"

int main() {
    bool playAgain = true;
    while(playAgain){
        std::vector<std::vector<char>> ticTac;
        int row, column;
        int player = 1;
        int turn = 0;
        bool game = true;
        int cond;
        // System for 2 players
        // Player 1 -> x ::: Player 2-> o'


        ticTac = startingVect();
        welcome();
        while (game){
            if(player == 1 && turn < 9){
                ticTac = getPosition(ticTac, player);
                print_ttt(ticTac);            
            } else if (player ==  2 && turn < 9){
                ticTac = getPosition(ticTac, player);
                print_ttt(ticTac);
            }

            cond = winCondition(ticTac);
            // there is space in the matrix and there is no win condition satisfied
            if (turn <= 9 && cond == 0){ 
                turn++;
                game == true;
                if (player == 1){
                    player = 2;
                }else {
                    player = 1;
                }
            } else if (cond == 1){
                endGame(cond);
                game = false;
            } else if (cond == 2){
                endGame(cond);
                game = false;
            }
        }

        playAgain = restartGame();
    }
    // This will run each turn for each player
    // Chech if vector matches any of the solution vectors
   return 0;
}
