#ifndef __Term_Manipulator__
#define __Term_Manipulator__

#include <iostream>

namespace termman{
    // Use resetCursorPosition with stdio
    const std::string resetCursorPosition = "\033[H";
    // Use clearLine with 
    const std::string clearLine = "\033[2K";

    inline std::string moveCursor(int x, int y){
        return "\033[" + std::to_string(x) + ";" + std::to_string(y) + "H";
    }
}

#endif /* __Term_Manipulator__ */