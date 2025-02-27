#include "Countdown.h"
#include <string>

Countdown::Countdown() {
    seconds = 0;
    running = false;
}

void Countdown::addTime(int sec) {
    if(!running) {
        if(seconds + sec > 0){
            seconds += sec;
        } else {
            seconds = 0;
        }
        
    }
}

void Countdown::start() {
    if (seconds > 0) {
        running = true;
    }
}

bool Countdown::isRunning() {
    return running;
}

std::string Countdown::secondsToString() {
    int h = seconds / 3600;
    int m = (seconds % 3600) / 60;
    int s = seconds % 60;

    std::string hh, mm, ss;

    if (h < 10) {
        hh = '0';
    }
    if (m < 10) {
        mm = '0';
    }
    if (s < 10) {
        ss = '0';
    }

    hh += std::to_string(h);
    mm += std::to_string(m);
    ss += std::to_string(s);

    return hh + ":" + mm + ":" + ss;

}