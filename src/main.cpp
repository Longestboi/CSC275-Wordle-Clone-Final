#include <chrono>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <vector>

#include "cell.hpp"
#include "gameboard.hpp"
#include "termman.hpp"
#include "input.hpp"


int main(){
    // Stop cout from syncing with stdio
    std::ios_base::sync_with_stdio(false);

    gameboard *gb = new gameboard(5, 4);
    input *in = new input();

    // I hate to do this but...
    system("clear");
    
    std::cout << std::flush;

    gb->setColorOfCell(cell::cellState::Correct, 4, 0);

    gb->setColorOfRowFromState(cell::cellState::Misplaced, 1);

    gb->displayGameBoard();

    gb->setRowCharsFromString("tests", 2);

    gb->displayGameBoard();

    std::this_thread::sleep_for(std::chrono::seconds(3));
    //gb->hideGameBoard();
    
    gb->clearCharOfCell(0, 0);
    //std::this_thread::sleep_for(std::chrono::seconds(3));
    //gb->displayGameBoard();
    while(true) std::this_thread::sleep_for(std::chrono::milliseconds(50));
    //std::cout << termman::clearScreen;
    std::cout << termman::resetCursorPosition;
    std::cout << termman::clearLine;
    return 0;
}