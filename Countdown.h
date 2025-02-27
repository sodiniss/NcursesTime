#ifndef COUNTDOWN_H
#define COUNTDOWN_H

class Countdown {
private:
    int seconds;
    bool running;

public:
    Countdown();
    void addTime(int sec);
    void start();
    bool isRunning();
};

#endif
