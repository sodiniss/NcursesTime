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
    WINDOW *mainWindow;  //da riguardare
    //WINDOW *menuWindow;
public:
    UI();
    ~UI();
    void run();
    void handleInput();
    void textPrint(WINDOW *window, int y, int x, const char* text, int color=0, chtype attributes = A_NORMAL);
};

#endif
