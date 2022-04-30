#ifndef __Input_Handler__
#define __Input_Handler__

#include <atomic>
#include <chrono>
#include <iostream>
#include <sys/ioctl.h>
#include <termios.h>
#include <thread>
#include <unistd.h>

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
    void echoOn(bool on);
    void cursorOn(bool on);
    void stopThread(void);
};

#endif /* __Input_Handler__ */