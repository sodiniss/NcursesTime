#include "Countdown.h"
#include <string>

#include <unistd.h>


Countdown::Countdown() {
    seconds = 0;
    running = false;
    complete = false;
    lastUpdate = std::chrono::steady_clock::now();
}

void Countdown::addTime(int sec) {
    if(!running) {
        if(seconds + sec > 0){
            seconds += sec;
            complete = false;
        } else {
            reset();
        }
        
    }
}

void Countdown::start() {
    if (seconds > 0) {
        complete = false;
        running = true;
        lastUpdate = std::chrono::steady_clock::now();
    }
}

void Countdown::pause() {
    if (running) {
        running = false;
    }
}

void Countdown::reset() {
    running = false;
    seconds = 0;
    complete = false;
}

bool Countdown::isRunning() {
    return running;
}

bool Countdown::isComplete() {
    return complete;
}

int Countdown::getSeconds() {
    return seconds;
}

void Countdown::refreshTime() {
    if (running && seconds > 0) {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - lastUpdate).count();
    
        if (elapsed >= 1) {

            lastUpdate = now;  //nuovo tempo di riferimento
            //sleep(1);
            seconds--;
            if (seconds == 0) {
                running = false;
                complete = true;
            }
        }
    }
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