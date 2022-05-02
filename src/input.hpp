#ifndef __Input_Handler__
#define __Input_Handler__

#include <atomic>
#include <chrono>
#include <iostream>
#include <sys/ioctl.h>
#include <thread>
#include <unistd.h>

#include "common.hpp"
#include "termman.hpp"

class input{
private:
    std::thread* inputThread;
    std::atomic<bool> isThreadStopped;
    std::atomic<char> currentChar;
    std::string* fWord;

public:
    input();
    ~input();

    void runInputThread(void);

    int kbhit(void);
    void stopThread(void);
    char getCurrentChar(void);
    std::string getFullWord(void);
    void discardRestOfLine(void);
};

#endif /* __Input_Handler__ */