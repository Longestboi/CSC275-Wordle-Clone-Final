#include "gamelogic.hpp"

gameLogic::gameLogic(){
    inputHandler = new input();
    gameBoard = new gameboard(5, 4);
}

gameLogic::~gameLogic(){
    // Delete game board and input handler
    delete gameBoard;
    delete inputHandler;
}

void gameLogic::gameInit(){
    
}