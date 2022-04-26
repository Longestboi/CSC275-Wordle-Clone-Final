#include "cell.hpp"
#include "termman.hpp"

void cell::setBoxColor(colors color){
    this->currentColor = color;
    return;
}

void cell::setBoxChar(char c){
    currentCharacter = std::toupper(c);

    int buf = currentCharacter - 65;

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

    auto position = getCellPosition();

    std::cout << termman::setBGColor(termman::termColors::Green);
    std::cout << termman::setFGColor(termman::termColors::DGreen);
    std::cout << termman::moveCursor(position[0], position[1]) << box[0];

    std::cout << termman::clearFormatting;
    std::cout << termman::setBGColor(termman::termColors::Green);
    std::cout << termman::setFGColor(termman::termColors::White);
    std::cout << termman::moveCursor(position[0], position[1] + 1) << box[1];
    
    std::cout << termman::setFGColor(termman::termColors::DGreen);
    std::cout << termman::moveCursor(position[0], position[1] + 2) << box[2];
    std::cout << termman::clearFormatting;
}