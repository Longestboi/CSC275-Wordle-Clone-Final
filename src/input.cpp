#include "input.hpp"
#include "termman.hpp"
#include "common.hpp"

input::input(){
    echoOn(false);
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

    echoOn(true);
}

void input::runInputThread(void){

    while (!isThreadStopped.load()){
        // Get char from terminal
        currentChar.store((kbhit() != '\0') ? getchar(): '\0');

        // Only allow a-z, A-Z to be added to the string
        if(
            fWord->length() < WORDLENGTH 
            && (currentChar.load() != '\0' && currentChar.load() != 127) 
            //&& ((currentChar.load() >= 65 && currentChar.load() <= 90)
            //    || (currentChar.load() >= 97 && currentChar.load() <= 122))
        ){
            // push char to string
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

void input::echoOn(bool on){
        // Turn echo on or off in *nix/Linux
        static const int STDIN = 0;
        struct termios terminal;
        tcgetattr(STDIN, &terminal);
        (on == true) ? 
            terminal.c_lflag |= ECHO : 
            terminal.c_lflag &= ~ECHO;
        tcsetattr(STDIN, TCSANOW, &terminal);
        return;
    }

void input::stopThread(void){
    isThreadStopped.store(true);
}