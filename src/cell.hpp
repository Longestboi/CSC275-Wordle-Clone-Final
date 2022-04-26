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
    enum colors{Blank, Green, Yellow};
    
    // Set the color of the box
    void setBoxColor(colors color);
    // Set the character in the box
    void setBoxChar(char c);
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
    colors currentColor;
    // the X and Y position of the top-left corner
    int posX, posY;
};

#endif /* __CELL__ */