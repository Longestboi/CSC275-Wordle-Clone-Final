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

    const int xSpace = 7;
    const int ySpace = 4;
    
    // Set the color of the box
    void setCellColorFromState(cellState color);

    // Set the character in the box
    template <class T>
    void setCellChar(T input){
        int buf;

        if(typeid(input) == typeid(char)){
            // Change input to uppercase 
            currentCharacter = std::toupper(input);

            // Subtract 'A' from current character to normalize it to 0-25
            buf = currentCharacter - 'A';
        }
        if(typeid(input) == typeid(int)){
            currentCharacter = input + 'A';

            buf = input;
        }
        
        try{
            // If the currentCharacter is out of range throw an error
            if(buf < 0 || buf > 25) throw std::out_of_range(std::to_string(buf));
        
            box[1] = fullwidthSpace + fullWidthChars[buf] + fullwidthSpace;
        }
        catch(std::out_of_range numOutOfRange){
            std::cerr << 
                "Tried to access an out of range Fullwidth letter, " <<
                    numOutOfRange.what() << "\n";
        }
    }

    // Get the position of the top-left char in the cell 
    std::vector<int> getCellPosition(void);

    // Get the X or Y position of the current cell 
    //
    // p: 'X' or 'Y'
    // Returns: X or Y position of current cell.
    // If p isn't 'x' or 'y', return -1
    int getCellPosition(char p);

    // Set the position of the top-left char in the cell 
    void setCellPosition(int x, int y);

    // Display the cell
    void displayCell();

    // Hide current cell
    void hideCell();
    
private:
    // Cell making stuff
    std::string box[3] = {"⌜　　⌝", "　　　", "⌞　　⌟" };
    std::string fullwidthSpace = "　";
    
    // Cell display stuff
    char currentCharacter;
    cellState currentCellState;
    // the X and Y position of the top-left corner
    int posX, posY ;
};

#endif /* __CELL__ */