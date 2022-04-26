#include <chrono>
#include <iostream>
#include <thread>

#include "termman.hpp"
#include "cell.hpp"


int main(){
    // Stop cout from syncing with stdio
    std::ios_base::sync_with_stdio(false);

    cell testCell;

    std::cout << termman::clearScreen;

    testCell.setCellPosition(10, 5);
    testCell.setBoxChar('c');
    testCell.displayCell();

    std::cout << termman::resetCursorPosition;
    std::cout << termman::clearLine;
    
    std::cout << std::flush;

    std::this_thread::sleep_for(std::chrono::seconds(3));
    //std::cout << termman::clearScreen;

    return 0;
}