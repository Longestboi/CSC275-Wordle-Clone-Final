#ifndef __Term_Manipulator__
#define __Term_Manipulator__

#include <iostream>

namespace termman{

    const std::string escapeSeq = "\033[";

    enum termColors {
        Black = 30, Red = 31, Green = 32, Yellow = 33,
        Blue = 34, Magenta = 35, Cyan = 36, White = 37,
        DBlack = 130, DRed = 131, DGreen = 132, DYellow = 133,
        DBlue = 134, DMagenta = 135, DCyan = 136, DWhite = 137 
    };

    // Use resetCursorPosition with stdio
    const std::string resetCursorPosition = escapeSeq + "H";
    // Clear the line the cursor is currently on
    const std::string clearLine = escapeSeq + "2K";
    //
    const std::string clearScreen = escapeSeq + "0J";
    // Reset the formatting of the terminal
    const std::string clearFormatting = escapeSeq + "0m";

    static std::string moveCursor(int x, int y){
        return escapeSeq + std::to_string(y) + ";" + std::to_string(x) + "H";
    }

    static std::string setFGColor(termColors color){
        // Check if the color is dimmed
        if (color >= 130 && color <= 137){
            return escapeSeq + "2;" + std::to_string(color - 100) + "m";
        }else{
            return escapeSeq + std::to_string(color) + "m";
        }
    }

    static std::string setBGColor(termColors color){
        // Add 10 to color to get the BG color 
        int buf = color + 10;

        // Check if the color is dimmed
        if (buf >= 140 && buf <= 147){
            return escapeSeq + std::to_string(buf - 100) + "m";
        }else{
            return escapeSeq + std::to_string(buf) + "m";
        }
    }
}

#endif /* __Term_Manipulator__ */