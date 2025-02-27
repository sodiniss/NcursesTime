#include "Countdown.h"
#include <unistd.h>

Countdown::Countdown() {
    seconds = 0;
    running = false;
}

void Countdown::addTime(int sec) {

}

void Countdown::start() {
    running = true;
}

bool Countdown::isRunning() {
    return running;
}

