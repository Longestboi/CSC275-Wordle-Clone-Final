#include "input.hpp"

input::input(){
    termman::echoOn(false);
    termman::cursorOn(false);
    isThreadStopped.store(false);

    fWord = new std::string();
    fWord->reserve(WORDLENGTH);

    inputThread = new std::thread(&input::runInputThread, this);
}

input::~input(){


    // Allow runInputThread to return;
    stopThread();    
    // Run thread until function return
    inputThread->join();
    termman::cursorOn(true);
    termman::echoOn(true);

    std::cout << std::flush;
}

void input::runInputThread(void){

    while (!isThreadStopped.load()){
        // Get char from terminal
        currentChar.store((kbhit() != '\0') ? getchar(): '\0');

        // Only allow a-z, A-Z to be added to the string
        if(
            fWord->length() < WORDLENGTH 
            // stop NULL and Backspace
            && (currentChar.load() != '\0' && currentChar.load() != 127) 
            && ((currentChar.load() >= 65 && currentChar.load() <= 90)
                || (currentChar.load() >= 97 && currentChar.load() <= 122))
        ){
            // Push char to string
            fWord->push_back(currentChar.load());
        };

        // Remove char from end of string 
        if(fWord->length() > 0 && currentChar.load() == 127){
            fWord->pop_back();
        }

        if(fWord->length() == WORDLENGTH){
            std::cout << std::flush;
        }

    }

    if(isThreadStopped.load()) return;
}

// Adapted from https://stackoverflow.com/a/33201364
int input::kbhit(void) {
    // Determine if a key has been pressed
    static bool initflag = false;
    static const int STDIN = 0;

    if (!initflag) {
        // Use termios to turn off line buffering
        struct termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initflag = true;
    }

    int nbbytes;
    ioctl(STDIN, FIONREAD, &nbbytes);  // 0 is STDIN
    return nbbytes;
}

void input::stopThread(void){
    isThreadStopped.store(true);
}

char input::getCurrentChar(void){
    return currentChar.load();
}