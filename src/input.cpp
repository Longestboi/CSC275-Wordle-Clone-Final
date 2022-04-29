#include "input.hpp"

input::input(){
    inputThread = new std::thread(&input::runInputThread, this);
    isThreadStopped = false;
    //inputThread->detach();
}

input::~input(){
    // Allow runInputThread to return;
    stopThread();    
    // Run thread until function return
    inputThread->join();
}

void input::runInputThread(void){

    std::this_thread::sleep_for(std::chrono::seconds(1));

    if(isThreadStopped) return;
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

int input::getCharFromTerminal(void){

}

void input::stopThread(void){
    isThreadStopped = true;
}