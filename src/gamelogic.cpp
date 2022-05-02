#include "gamelogic.hpp"

gameLogic::gameLogic(void){
    inputHandler = new input();
    gameBoard = new gameboard(5, 4);

}

gameLogic::~gameLogic(void){
    //std::cout << guess;
    // Delete game board and input handler
    delete gameBoard;
    delete inputHandler;
}

void gameLogic::gameInit(void){

    gameBoard->setColorOfCell(cell::cellState::Correct, 4, 0);
    gameBoard->setColorOfRowFromState(cell::cellState::Misplaced, 1);
    gameBoard->displayGameBoard();
    gameBoard->setRowCharsFromString("tests", 2);

    gameBoard->clearCharOfCell(3, 2);
    gameBoard->displayGameBoard();
    gameLoop();
}

void gameLogic::gameLoop(void){
    
    // Main gameLoop
    while(true) {
        guess = inputHandler->getFullWord();

        char handler = std::tolower(inputHandler->getCurrentChar());
        
        gameBoard->setRowCharsFromString(guess, 0);
        
        switch (handler){
        case 27:
            exit(0);
            break;
        default:
            break;
        }
    };
}

void gameLogic::resetBoard(void){
    gameBoard->setColorOfAllCellsFromState(cell::cellState::Unguessed);
    gameBoard->clearAllRowsOfChars();
}