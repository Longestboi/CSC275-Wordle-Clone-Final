#include "gamelogic.hpp"

gameLogic::gameLogic(void){
    inputHandler = new input();
    gameBoard = new gameboard(5, 4);
}

gameLogic::~gameLogic(void){
    // Delete game board and input handler
    delete gameBoard;
    delete inputHandler;
}

void gameLogic::gameInit(void){


    gameBoard->setColorOfCell(cell::cellState::Correct, 4, 0);
    gameBoard->setColorOfRowFromState(cell::cellState::Misplaced, 1);
    gameBoard->displayGameBoard();
    gameBoard->setRowCharsFromString("tests", 2);
    gameBoard->displayGameBoard();

}

void gameLogic::gameLoop(void){

    // Main gameLoop
    while(true) {
        if(std::tolower(inputHandler->getCurrentChar()) == 'q') {
            delete this;
            break;
        }
    };
}

char gameLogic::getCurrentChar(void){
    return inputHandler->getCurrentChar();
}