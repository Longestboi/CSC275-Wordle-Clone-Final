#include "cell.hpp"
#include "termman.hpp"

void cell::setCellColorFromState(cellState state){
    this->currentCellState = state;
    return;
}

std::vector<int> cell::getCellPosition(void){
    std::vector<int> position;

    position.push_back(posX);
    position.push_back(posY);

    return position;
}

int cell::getCellPosition(char p){

    switch(std::tolower(p)){
    case 'x':
        return posX;
    case 'y':
        return posY;
    default:
        return -1;
    }
}

void cell::setCellPosition(int x, int y){
    posX = x;
    posY = y;
    return;
}

void cell::displayCell(){

    termman::termColors currentFGColor;
    termman::termColors currentBGColor;

    switch (currentCellState){
        case cellState::Correct:
            currentBGColor = termman::termColors::Green;
            currentFGColor = termman::termColors::DGreen;
            break;

        case cellState::Misplaced:
            currentBGColor = termman::termColors::Yellow;
            currentFGColor = termman::termColors::DYellow;
            break;

        // Case covers wrong, unguessed, and errors
        case 0: default:
            currentBGColor = termman::termColors::Black;
            currentFGColor = termman::termColors::DBlack;
            break;
    }

    auto position = getCellPosition();

    std::cout << termman::setBGColor(currentBGColor);
    std::cout << termman::setFGColor(currentFGColor);
    std::cout << termman::moveCursor(position[0], position[1]) << box[0];

    std::cout << termman::clearFormatting;
    std::cout << termman::setBGColor(currentBGColor);
    std::cout << termman::setFGColor(termman::termColors::White);
    std::cout << termman::moveCursor(position[0], position[1] + 1) << box[1];
    
    std::cout << termman::setFGColor(currentFGColor);
    std::cout << termman::moveCursor(position[0], position[1] + 2) << box[2];
    std::cout << termman::clearFormatting;

    std::cout << std::flush;
}

void cell::hideCell(){
    for(int i = 0; i < ySpace - 1; i++){
        std::cout << termman::moveCursor(posX, posY + i);
        for(int i = 0; i < xSpace; i++) {
            std::cout << termman::clearFormatting << " ";
        }
    }
    std::cout << std::flush;
}