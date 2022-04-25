#include <iostream>
#include <thread>
#include <chrono>
#include "termman.hpp"


int main(){
    // Stop cout from syncing with stdio
    std::ios_base::sync_with_stdio(false);

    std::cout << termman::moveCursor(10, 15);

    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "test\n";

    std::cout << termman::resetCursorPosition;
    std::cout << termman::clearLine;

    return 0;
}