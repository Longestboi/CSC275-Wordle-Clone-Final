#ifndef __Game_Logic__
#define __Game_Logic__

#include "input.hpp"
#include "gameboard.hpp"

class gameLogic{
private:
    input* inputHandler;
    gameboard* gameBoard;
    
public:
    gameLogic();
    ~gameLogic();
    
    void gameInit();
};

#endif /* __Game_Logic__ */