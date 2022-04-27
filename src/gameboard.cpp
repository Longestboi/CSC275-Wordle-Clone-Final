#include "gameboard.hpp"

gameboard::gameboard(int posX, int posY){
    // Set the position of the gameboard
    setGameBoardPosition(posX, posY);

    // Limit how many rows can be made in the vector allRows
    allRows.reserve(6);

    for(int i = 0; i < allRows.capacity(); i++){
        std::vector<cell> tmp;

        // Limit number of cells in a row
        tmp.reserve(5);

        // Make gameboard
        for(int j = 0; j < tmp.capacity(); j++){
            cell tempCell;
            tmp.push_back(tempCell);
            
            tempCell.setCellPosition(
                // Position the cells within a grid 
                gameboardPosX + (j + 1) * 7, gameboardPosY + (i + 1) * 4);
        }

        allRows.push_back(tmp);
    }
}

gameboard::~gameboard(){
    
}

void gameboard::setGameBoardPosition(int x, int y){
    gameboardPosX = x;
    gameboardPosY = y;
}

void gameboard::displayGameBoard(){
    std::vector<std::vector<cell>>::iterator i;
    std::vector<cell>::iterator j;
    for(i = allRows.begin(); i < allRows.end(); i++){
        for(j = i->begin(); j < i->end(); j++){
            j->displayCell();
        }
    }
}

void gameboard::hideGameBoard(){
    std::vector<std::vector<cell>>::iterator i;
    std::vector<cell>::iterator j;
    for(i = allRows.begin(); i < allRows.end(); i++){
        for(j = i->begin(); j < i->end(); j++){
            j->hideCell();
        }
    }
}