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
    std::atomic_bool isThreadStopped;
    std::atomic_char currentChar;

public:
    input();
    ~input();

    void runInputThread(void);

    int kbhit(void);
    int getCharFromTerminal(void); 
    void stopThread(void);
};

#endif /* __Input_Handler__ */