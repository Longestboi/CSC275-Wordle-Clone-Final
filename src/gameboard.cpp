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

gameboard::~gameboard(void){
    hideGameBoard();
    std::cout << std::flush;
    return;
}

void gameboard::setGameBoardPosition(int x, int y){
    gameboardPosX = x;
    gameboardPosY = y;
    return;
}

void gameboard::displayGameBoard(void){
    std::vector<std::vector<cell>>::iterator i;
    std::vector<cell>::iterator j;
    for(i = allRows.begin(); i < allRows.end(); i++){
        for(j = i->begin(); j < i->end(); j++){
            j->displayCell();
        }
    }
    std::cout << std::flush;
    return;
}

void gameboard::hideGameBoard(void){
    std::vector<std::vector<cell>>::iterator i;
    std::vector<cell>::iterator j;
    for(i = allRows.begin(); i < allRows.end(); i++){
        for(j = i->begin(); j < i->end(); j++){
            j->hideCell();
        }
    }
    std::cout << std::flush;
    return;
}

void updateCellsInRow(int rowNum){

    return;
}

std::vector<std::vector<cell>>& gameboard::getAllRows(void){
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
                ", is out of range of allrows subvector.\n"; 
        }else if(tmp->at(0)){
            std::cerr << oor.what() << ", is out of range of allrows.\n"; 
        }
    }
    std::cout << std::flush;
    return;
}

void gameboard::setColorOfAllCellsFromState(cell::cellState state){
    std::vector<std::vector<cell>>::iterator i;
    std::vector<cell>::iterator j;
    for(i = allRows.begin(); i < allRows.end(); i++){
        for(j = i->begin(); j < i->end(); j++){
            j->setCellColorFromState(state);
        }
    }
    std::cout << std::flush;
    return;
}

void gameboard::setColorOfRowFromState(cell::cellState state, int rowNum){
    try{
        if(rowNum > WORDLENGTH - 1 || rowNum < 0) {
            throw std::out_of_range("rowNum: " + std::to_string(rowNum));
        }
        std::vector<cell>::iterator i;
        for(i = allRows[rowNum].begin(); i < allRows[rowNum].end(); i++){
            i->setCellColorFromState(state);
        }
    }
    catch(std::out_of_range oor){
        std::cerr << oor.what() << ", is out of range of allrows subvector.\n"; 
    }
    std::cout << std::flush;
    return;
}

void gameboard::setCharOfCell(char c, int x, int y){
    try{
        if(x > WORDLENGTH - 1 || x < 0){
            throw std::out_of_range("x: " + std::to_string(x));
        }
        if(y > GUESSES - 1 || y < 0) {
            throw std::out_of_range("y: " + std::to_string(y));
        }

        allRows[y][x].setCellChar(c);
    }
    catch(std::out_of_range oor){
        std::string *tmp = new std::string(oor.what());

        if(tmp->at(0) == 'x'){
            std::cerr << oor.what() << 
                ", is out of range of allrows subvector.\n"; 
        }else if(tmp->at(0)){
            std::cerr << oor.what() << ", is out of range of allrows.\n"; 
        }
    }
    std::cout << std::flush;
    return;
}

void gameboard::setRowCharsFromString(std::string input, int rowNum){
    try{
        if(input.size() > WORDLENGTH || input.size() < 0) {
            throw std::out_of_range(
                "str size: " + std::to_string(input.size())
            );
        }
    }
    catch(std::out_of_range oor){
        std::cerr << oor.what() <<  ", is out of range of allrows.\n";
        return;
    }

    str_toupper(input);

    for(int i = 0; i < WORDLENGTH; i++){

        //setCharOfCell(input[i], i, rowNum);
        if(i < input.size()) setCharOfCell(input[i], i, rowNum);
        if(i >= input.size()) clearCharOfCell(i, rowNum);
        

        allRows[rowNum][i].displayCell();
    }

    std::cout << std::flush;
}

void gameboard::clearCharOfCell(int x, int y){
    try{
        if(x > WORDLENGTH - 1 || x < 0){
            throw std::out_of_range("x: " + std::to_string(x));
        }
        if(y > GUESSES - 1 || y < 0) {
            throw std::out_of_range("y: " + std::to_string(y));
        }

        allRows[y][x].clearCellChar();
    }
    catch(std::out_of_range oor){
        std::cerr << oor.what() << ", is out of range of allrows.\n";
    }
    std::cout << std::flush;
    return;
}

void gameboard::clearRowOfChars(int rowNum){
    try{
        if(rowNum > WORDLENGTH - 1 || rowNum < 0) {
            throw std::out_of_range("rowNum: " + std::to_string(rowNum));
        }

        std::vector<cell>::iterator i;
        for(i = allRows[rowNum].begin(); i < allRows[rowNum].end(); i++){
            i->clearCellChar();
        }
    }
    catch(std::out_of_range oor){
        std::cerr << oor.what() << ", out of range of cell vector.\n";
    }
    std::cout << std::flush;
}

void gameboard::clearAllRowsOfChars(void){
    std::vector<std::vector<cell>>::iterator i;
    std::vector<cell>::iterator j;
    for(i = allRows.begin(); i < allRows.end(); i++){
        for(j = i->begin(); j < i->end(); j++){
            j->clearCellChar();
        }
    }
    std::cout << std::flush;
    return;
}