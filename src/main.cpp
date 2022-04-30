#include <chrono>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <vector>

#include "gamelogic.hpp"
#include "termman.hpp"

int main(){
    std::cout << termman::enableAltBuffer;
    // Stop cout from syncing with stdio
    std::ios_base::sync_with_stdio(false);

    gameLogic *gl = new gameLogic();
    
    gl->gameInit();

    // I hate to do this but...
    system("clear");

    //std::cout << termman::clearScreen;
    std::cout << termman::disableAltBuffer;
    return 0;
}

void __attribute__((destructor)) atExit(){
    termman::echoOn(true);
    termman::cursorOn(true);
}