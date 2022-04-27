#ifndef __Game_Board__
#define __Game_Board__
#include <vector>

#include "cell.hpp"

class gameboard{
private:
    // vector of all rows
    std::vector<std::vector<cell>> allRows;
    int gameboardPosX = 10; 
    int gameboardPosY = 5;

public:
    gameboard(int posX, int posY);
    ~gameboard();

    void setGameBoardPosition(int x, int y);
    void displayGameBoard();
    void hideGameBoard();
};
#endif /* __Game_Board__ */