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
    void pause();
    void reset();
    bool isRunning();
    void refreshTime();
    std::string secondsToString();
};

#endif
