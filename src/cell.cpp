#include "cell.hpp"
#include "termman.hpp"

void cell::setCellColorFromState(cellState state){
    this->currentCellState = state;
    return;
}

template <typename t>
void cell::setCellChar(t c){

    char charBuf;
    
    if(typeid(c) == typeid(char)){
        charBuf = c;
    }else if(typeid(c) == typeid(std::string)){
        charBuf = c.at(0);
    }

    // Change c to uppercase 
    currentCharacter = std::toupper(charBuf);

    // Subtract 'A' from current character to normalize it to 0-25
    int buf = currentCharacter - 'A';
    
    try{
        // If the currentCharacter is out of range throw an error
        if(buf < 0 || buf > 25) throw buf;
    
        box[1] = fullwidthSpace + fullWidthChars[buf] + fullwidthSpace;
    }
    catch(int numOutOfRange){
        std::cerr << 
            "Tried to access an out of range Fullwidth letter, " 
            << buf << "\n";
    }
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

std::vector<int> cell::getCellPosition(void){
    std::vector<int> position;

    position.push_back(posX);
    position.push_back(posY);

    return position;
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
}