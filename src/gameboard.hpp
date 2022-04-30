#ifndef __Game_Board__
#define __Game_Board__
#include <vector>

#include "cell.hpp"
#include "common.hpp"
#include "termman.hpp"

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

    // visualizers

    void displayGameBoard(void);
    void hideGameBoard(void);

    void updateCellsInRow(int rowNum);

    std::vector<std::vector<cell>>& getAllRows(void);

    // Cell color manipulators

    void setColorOfCell(cell::cellState state, int x, int y);
    void setColorOfAllCellsFromState(cell::cellState state);
    void setColorOfRowFromState(cell::cellState state, int rowNum);

    // Cell char manipulators

    void setCharOfCell(char c, int x, int y);
    void setRowCharsFromString(std::string input, int rowNum);
    void clearCharOfCell(int x, int y);
    void clearRowOfChars(int rowNum);
    void clearAllRowsOfChars(void);
};
#endif /* __Game_Board__ */