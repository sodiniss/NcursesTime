#ifndef UI_H
#define UI_H

#include "DateTime.h"
#include "Countdown.h"
#include <ncurses.h>
#include <string>

class UI {
private:
    const char* clockFormat; // da riguardare
    Countdown countdown;
    // WINDOW *window;  //da riguardare
public:
    UI();
    void run();
    void handleInput();
};

#endif
