#ifndef __CELL__
#define __CELL__

#include <iostream>
#include <string>
#include <vector>

const std::string fullWidthChars[26] {
    "Ａ", "Ｂ", "Ｃ", "Ｄ", "Ｅ", "Ｆ", "Ｇ", "Ｈ", "Ｉ",
    "Ｊ", "Ｋ", "Ｌ", "Ｍ", "Ｎ", "Ｏ", "Ｐ", "Ｑ", "Ｒ",
    "Ｓ", "Ｔ", "Ｕ", "Ｖ", "Ｗ", "Ｘ", "Ｙ", "Ｚ"
};

class cell{
public:
    enum cellState{Wrong = 0, Unguessed = 0, Correct = 1, Misplaced = 2};
    
    // Set the color of the box
    void setCellColorFromState(cellState color);

    // Set the character in the box
    template <typename t>
    void setCellChar(t input);

    // Get the X or Y position of the current cell 
    //
    // p: 'X' or 'Y'
    // Returns: X or Y position of current cell.
    // If p isn't 'x' or 'y', return -1
    int getCellPosition(char p);

    // Get the position of the top-left char in the cell 
    std::vector<int> getCellPosition(void);

    // Set the position of the top-left char in the cell 
    void setCellPosition(int x, int y);

    // Display the cell
    void displayCell();

    
private:
    // Cell making stuff
    std::string box[3] = {"⌜　　⌝", "　　　", "⌞　　⌟" };
    std::string fullwidthSpace = "　";
    
    // Cell display stuff
    char currentCharacter;
    cellState currentCellState;
    // the X and Y position of the top-left corner
    int posX, posY;
};

#endif /* __CELL__ */