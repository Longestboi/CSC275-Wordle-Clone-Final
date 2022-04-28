#include "gameboard.hpp"

gameboard::gameboard(int posX, int posY){
    // Set the position of the gameboard
    setGameBoardPosition(posX, posY);

    // Limit how many rows can be made in the vector allRows
    allRows.reserve(GUESSES);

    for(int i = 0; i < allRows.capacity(); i++){
        std::vector<cell> tmp;

        // Limit number of cells in a row
        tmp.reserve(WORDLENGTH);

        // Make gameboard
        for(int j = 0; j < tmp.capacity(); j++){
            cell tempCell;
            
            tempCell.setCellPosition(
                // Position the cells within a grid 
                (gameboardPosX + j * tempCell.xSpace), 
                (gameboardPosY + i * tempCell.ySpace));

            /* DEBUG STUFF
            // Move cursor to the cells position 
            std::cout << termman::moveCursor(
                tempCell.getCellPosition('x'),
                tempCell.getCellPosition('y') + 3);

            // Display cell position in terminal
            std::cout << tempCell.getCellPosition('x') << " " << tempCell.getCellPosition('y');
            */
            tmp.push_back(tempCell);
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

std::vector<std::vector<cell>>& gameboard::getAllRows(){
    return allRows;
}

void gameboard::setColorOfCell(cell::cellState state, int x, int y){

    try{
        if(x > WORDLENGTH - 1 || x < 0){
            throw std::out_of_range("x: " + std::to_string(x));
        }
        if(y > GUESSES - 1 || y < 0) {
            throw std::out_of_range("y: " + std::to_string(y));
        }

        allRows[y][x].setCellColorFromState(state);
    }
    catch(std::out_of_range oor){
        std::string *tmp = new std::string(oor.what());

        if(tmp->at(0) == 'x'){
            std::cerr << oor.what() << 
                ", is out of range of allrows sub vector.\n"; 
        }else if(tmp->at(0)){
            std::cerr << oor.what() << ", is out of range of allrows.\n"; 
        }
    }
}

//void gameboard::setCharOfCell(char c){

//}