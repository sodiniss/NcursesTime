#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <string>
class Countdown {
private:
    int seconds;
    bool running;
    bool complete;

public:
    Countdown();
    void addTime(int sec);
    void start();
    void pause();
    void reset();
    bool isRunning();
    bool isComplete();
    int getSeconds();

    void refreshTime();
    std::string secondsToString();
};

#endif
