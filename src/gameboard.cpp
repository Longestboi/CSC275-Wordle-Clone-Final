#include "gameboard.hpp"

gameboard::gameboard(){
    // Limit how many rows can be made in the vector allRows
    allRows.reserve(6);

    for(int i = 0; i < allRows.capacity(); i++){
        std::vector<cell> tmp;

        tmp.reserve(5);

        // Make gameboard
        for(int j = 0; j < tmp.capacity(); j++){
            cell tempCell;
            tmp.push_back(tempCell);
            
            tempCell.setCellPosition(
                // Position the cells within a grid 
                gameboardPosX + (j + 1) * 7, gameboardPosY + (i + 1) * 4);
            tempCell.displayCell();
        }

        allRows.push_back(tmp);
    }
}

gameboard::~gameboard(){
    
}

static gameboard& GetInstance(){
    static gameboard* gb = new gameboard();
    return *gb;
}