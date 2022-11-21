#include <vector>

void welcome();
std::vector<std::vector<char>> startingVect();
std::vector<std::vector<char>> getPosition(std::vector<std::vector<char>> ticTac, int player);
void print_ttt(std::vector<std::vector<char>> ticTac);
int winCondition(std::vector<std::vector<char>> ticTac);
bool endGame(int cond);
bool restartGame();
