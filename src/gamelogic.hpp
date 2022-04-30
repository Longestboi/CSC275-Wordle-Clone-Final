#ifndef __Game_Logic__
#define __Game_Logic__

#include "input.hpp"
#include "gameboard.hpp"

class gameLogic{
private:
    input* inputHandler;
    gameboard* gameBoard;
    
public:
    gameLogic(void);
    ~gameLogic(void);
    
    void gameInit(void);
    void gameLoop(void);
    char getCurrentChar(void);
};

#endif /* __Game_Logic__ */