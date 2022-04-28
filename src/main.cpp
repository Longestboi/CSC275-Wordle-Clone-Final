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

    gameboard *gb = new gameboard(5, 4);

    // I hate to do this but...
    system("clear");
    //std::cout << termman::clearScreen;
    
    std::cout << std::flush;

    cell tets;

    tets.setCellPosition(5, 5);

    gb->setColorOfCell(cell::cellState::Correct, 4, 0);

    tets.setCellChar(0);
    tets.displayCell();

    //gb->displayGameBoard();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    //gb->hideGameBoard();
    //std::this_thread::sleep_for(std::chrono::seconds(3));
    //gb->displayGameBoard();
    //while(true) sleep(1);
    //std::cout << termman::clearScreen;

    std::cout << termman::resetCursorPosition;
    std::cout << termman::clearLine;

    return 0;
}