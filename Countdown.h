#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <string>
class Countdown {
private:
    int seconds;
    bool running;

public:
    Countdown();
    void addTime(int sec);
    void start();
    bool isRunning();
    std::string secondsToString();
};

#endif
