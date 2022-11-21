#include <iostream>
#include <vector>

void welcome(){
    std::cout << "Welcome to Tic Tac Toe!\n";
    std::cout << "Have a great time :)\n";
}

std::vector<std::vector<char>> startingVect(){
    std::vector<std::vector<char>> ticTac {
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'}
    };
    return ticTac;
}

std::vector<std::vector<char>> getPosition(std::vector<std::vector<char>> ticTac, int player){
    int row, column;
    std::cout << "\nInsert row and column ";

    if (player == 1){
        std::cout << "For X: ";
        std::cin >> row;
        std::cin >> column;
        while(ticTac[row][column] != '-' ){
            std::cout << "\nEnter an empty spot.\n";
            std::cout << "For X: ";
            std::cin >> row;
            std::cin >> column;
        }
        ticTac[row][column] = 'X';
        
    } else if (player == 2){
        std::cout << "For O: ";
        std::cin >> row;
        std::cin >> column;
        while(ticTac[row][column] != '-' ){
            std::cout << "\nEnter an empty spot.\n";
            std::cout << "For O: ";
            std::cin >> row;
            std::cin >> column;
        }
        ticTac[row][column] = 'O'; 

    } 
    return ticTac;
}

void print_ttt(std::vector<std::vector<char>> ticTac){
        for (int i = 0; i < ticTac.size(); i++) {
        for (int j = 0; j < ticTac[i].size(); j++)
        std::cout << ticTac[i][j] << " ";
        std::cout << "\n";
    }
}

// Algorithm to check what is the win condition from the options
int winCondition(std::vector<std::vector<char>> ticTac){
    // X Win conditions
    // Check for win condition agains the inputs of the players 
    if (ticTac[0][0] == 'X'){ // conditions 1, 4, 7
        if(ticTac[0][1] == 'X'){
            if (ticTac[0][2] == 'X'){
                // condition 1 is correct and X wins
                return 1;
            }
            // Condition almost met
            
        } else if (ticTac[2][0] == 'X'){
            if(ticTac[1][0] == 'X'){
                // condition 4 is met
                return 1;
            }
            // Condition almost met
            
        } else if (ticTac[1][1] == 'X'){
            if(ticTac[2][2] == 'X'){
                // Condition 7 is met
                return 1;
            }
            // Condition almost met
            
        }
        
    // do conditions 2, 4, 7
    } else if (ticTac[1][1] == 'X'){  
        if(ticTac[1][0] == 'X'){
            if(ticTac[1][2] == 'X'){
                // WIN CONDITION 2 MET
                return 1;
            }
            // CONDITION ALMOST MET
           
        } else if (ticTac[0][1] == 'X'){
            if(ticTac[2][1] == 'X'){
                //win condition 5 met
                return 1;
            }
            
        } else if (ticTac[0][2] == 'X'){
            if (ticTac[2][0] == 'X'){
                // win condition 8 met
                return 1;
            }
            
        }
        
    // win conditions 3 & 6
    } else if (ticTac[2][2] == 'X'){
        if(ticTac[2][1] == 'X'){
            if(ticTac[2][0] == 'X'){
                // win condition 3 is met
                return 1;
            }
            
        } else if (ticTac[1][2] == 'X'){
            if(ticTac[0][2] == 'X'){
                // win condition 6 is met
                return 1;
            }
            
        }
        
    }

    // O Win conditions
    // Check for win condition agains the inputs of the players 
    if (ticTac[0][0] == 'O'){ // conditions 1, 4, 7
        if(ticTac[0][1] == 'O'){
            if (ticTac[0][2] == 'O'){
                // condition 1 is correct and X wins
                return 2;
            }
            // Condition almost met
            return 0;
        } else if (ticTac[2][0] == 'O'){
            if(ticTac[1][0] == 'O'){
                // condition 4 is met
                return 2;
            }
            // Condition almost met
            return 0;
        } else if (ticTac[1][1] == 'O'){
            if(ticTac[2][2] == 'O'){
                // Condition 7 is met
                return 2;
            }
            // Condition almost met
            
        }

    // do conditions 2, 4, 7
    } else if (ticTac[1][1] == 'O'){  
        if(ticTac[1][0] == 'O'){
            if(ticTac[1][2] == 'O'){
                // WIN CONDITION 2 MET
                return 2;
            }
            // CONDITION ALMOST MET
            
        } else if (ticTac[0][1] == 'O'){
            if(ticTac[2][1] == 'O'){
                //win condition 5 met
                return 2;
            }
            
        } else if (ticTac[0][2] == 'O'){
            if (ticTac[2][0] == 'O'){
                // win condition 8 met
                return 2;
            }
        }

    // win conditions 3 & 6
    } else if (ticTac[2][2] == 'O'){
        if(ticTac[2][1] == 'O'){
            if(ticTac[2][0] == 'O'){
                // win condition 3 is met
                return 2;
            }
        } else if (ticTac[1][2] == 'O'){
            if(ticTac[0][2] == 'O'){
                // win condition 6 is met
                return 2;
            }
        }
    }
    
    return 0;
}


bool endGame(int cond){
    if (cond == 1){
        std::cout << "X wins\n";
        return true;
    } if (cond == 2){
        std::cout << "O wins!\n";
        return true;
    }
    return false;
}

// TODO 
// Here, we should check for a repeated input 
// If the input is repeated then ask for a new input
bool restartGame(){
    char a;
    std::cout << "Do you want to play again?(y/n)\n";
    std::cin >> a;

    if(a == 'y' || a == 'Y'){
        return true;
    } else {
        return false;
    } 
    
    return false;
}
