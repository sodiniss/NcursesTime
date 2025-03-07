#include "UI.h"
#include "DateTime.h"
#include <ncurses.h>


UI::UI() {
    initscr();
    noecho();
    curs_set(0);


    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);
    bkgd(COLOR_PAIR(1)); 

    int mainWindowHeight = 5;
    int mainWindowWidth = 50;

    int mainWindowStartY= (getmaxy(stdscr) - mainWindowHeight)/2;
    int mainWindowStartX= (getmaxx(stdscr) - mainWindowWidth)/2;

    mainWindow = newwin(mainWindowHeight, mainWindowWidth, mainWindowStartY, mainWindowStartX);
    box(mainWindow, ACS_VLINE, ACS_HLINE);

    nodelay(mainWindow, TRUE);

    // int menuWindowHeight = 10;
    // int menuWindowWidth = 60;
    // int menuWindowStartY = 50;
    // int menuWindowStartX = 0;

    // menuWindow = newwin(menuWindowHeight, menuWindowWidth, menuWindowStartY, menuWindowStartX);
    // box(menuWindow, 0, 0);


    clockFormat = getFormatEU();  //default
    countdown.addTime(5 );  //testing
}

void UI::run() {
    while (true) {

        wclear(mainWindow);//clear();

        wattron(mainWindow, COLOR_PAIR(2)); 
        wattron(mainWindow, A_BOLD);
        mvwprintw(mainWindow, 0, 0, "Data & Ora");
        wattroff(mainWindow, COLOR_PAIR(2)); 
        wattron(mainWindow, COLOR_PAIR(3)); 
        mvwprintw(mainWindow, 1, 0, "Timer");
        wattroff(mainWindow, COLOR_PAIR(3)); 
        wattroff(mainWindow, A_BOLD);
        mvwprintw(mainWindow, 0, 15, "%s", formatDate(clockFormat).c_str());
        mvwprintw(mainWindow, 1, 15, "%s", countdown.secondsToString().c_str());

        //anche qui con enum sarebbe più comodo
        if (clockFormat == getFormatEU()) {
            wattron(mainWindow, COLOR_PAIR(2) | A_BOLD);
            mvwprintw(mainWindow, getmaxy(mainWindow)-2, 0, "(1)EU");
            wattroff(mainWindow, COLOR_PAIR(2) | A_BOLD);
            mvwprintw(mainWindow, getmaxy(mainWindow)-2, 10, "(2)ISO");
            mvwprintw(mainWindow, getmaxy(mainWindow)-2, 20, "(3)USA");
        } else if (clockFormat == getFormatISO()) {
            mvwprintw(mainWindow, getmaxy(mainWindow)-2, 0, "(1)EU");
            wattron(mainWindow, COLOR_PAIR(2) | A_BOLD);
            mvwprintw(mainWindow, getmaxy(mainWindow)-2, 10, "(2)ISO");
            wattroff(mainWindow, COLOR_PAIR(2) | A_BOLD);
            mvwprintw(mainWindow, getmaxy(mainWindow)-2, 20, "(3)USA");
        } else if (clockFormat == getFormatUSA()) {
            mvwprintw(mainWindow, getmaxy(mainWindow)-2, 0, "(1)EU");
            mvwprintw(mainWindow, getmaxy(mainWindow)-2, 10, "(2)ISO");
            wattron(mainWindow, COLOR_PAIR(2) | A_BOLD);
            mvwprintw(mainWindow, getmaxy(mainWindow)-2, 20, "(3)USA");
            wattroff(mainWindow, COLOR_PAIR(2) | A_BOLD);
        }

        //questa se usassi 3 stati mutualm esclusivi "running" "paused" "completed" funzionerebbe meglio?? avrei comunque bisogno di sapere secondi
        //devo comunque avere tre stati: running-->"stop"; !running&&seconds>0-->"start"; !running&&seconds=0-->"empty timer"
        if (countdown.isRunning()) {
            wattron(mainWindow, COLOR_PAIR(5));
            wattron(mainWindow, A_BOLD); 
            mvwprintw(mainWindow, getmaxy(mainWindow)-1, 0, "(S)top");
            wattroff(mainWindow, COLOR_PAIR(5)); 
            mvwprintw(mainWindow, getmaxy(mainWindow)-1, 10, "(R)eset");
            wattron(mainWindow, A_BOLD);
        } else {
            if (countdown.getSeconds() > 0) {
                wattron(mainWindow, COLOR_PAIR(4)); 
                wattron(mainWindow, A_BOLD);
                mvwprintw(mainWindow, getmaxy(mainWindow)-1, 0, "(S)tart");
                wattroff(mainWindow, COLOR_PAIR(4));
                mvwprintw(mainWindow, getmaxy(mainWindow)-1, 10, "(R)eset");
                wattron(mainWindow, A_BOLD);
            }
            else {
                mvwprintw(mainWindow, getmaxy(mainWindow)-1, 0, "Empty Timer");
            }
        }


        wrefresh(mainWindow); //refresh()


        handleInput();
        countdown.refreshTime();
        napms(50);
        //usleep(50000);
    }
}



void UI::handleInput() {
    int keypress = wgetch(mainWindow);
    switch (keypress) {
        case '9': countdown.addTime(1); break;
        case '6': countdown.addTime(-1); break;
        case '8': countdown.addTime(60); break;
        case '5': countdown.addTime(-60); break;
        case '7': countdown.addTime(3600); break;
        case '4': countdown.addTime(-3600); break;
        case 's': countdown.isRunning() ? countdown.pause() : countdown.start(); break;
        case 'r': countdown.reset(); break;
        case 'q': delwin(mainWindow); endwin(); break;

        case '1': clockFormat = getFormatEU(); break;
        case '2': clockFormat = getFormatISO(); break;
        case '3': clockFormat = getFormatUSA(); break;

    }
}
