#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <unistd.h>

#include "cell.hpp"
#include "termman.hpp"
#include "gameboard.hpp"


int main(){
    // Stop cout from syncing with stdio
    std::ios_base::sync_with_stdio(false);

    gameboard *gb = new gameboard();

    // I hate to do this but...
    system("clear");
    //std::cout << termman::clearScreen;


    std::cout << termman::resetCursorPosition;
    std::cout << termman::clearLine;
    
    std::cout << std::flush;

    std::this_thread::sleep_for(std::chrono::seconds(3));
    //while(true) sleep(1);
    //std::cout << termman::clearScreen;

    return 0;
}