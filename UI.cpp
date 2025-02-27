#include "UI.h"
#include "DateTime.h"
#include <ncurses.h>
#include <unistd.h>

UI::UI() {
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    clockFormat = getFormatEU();  //default
    countdown.addTime(5 );
}

void UI::run() {
    while (true) {

        clear();
        mvprintw(1, 1, "Orologio %s", formatDate(clockFormat).c_str());
        mvprintw(2, 1, "Timer  %s", countdown.secondsToString().c_str());
        refresh();

        countdown.secondsToString();
        handleInput();
        //countdown.AGGGIORNA TIMER QUALCOSA();
        //napms(50);
        usleep(100000);
    }
}



void UI::handleInput() {
    int keypress = getch();
    switch (keypress) {
        case '9': countdown.addTime(1); break;
        case '6': countdown.addTime(-1); break;
        case '8': countdown.addTime(60); break;
        case '5': countdown.addTime(-60); break;
        case '7': countdown.addTime(3600); break;
        case '4': countdown.addTime(-3600); break;
        case 's': countdown.start(); break;
        case '1': clockFormat = getFormatEU(); break;
        case '2': clockFormat = getFormatISO(); break;
        case '3': clockFormat = getFormatUSA(); break;

    }
}
