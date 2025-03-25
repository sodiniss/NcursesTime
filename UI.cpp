#include "UI.h"
#include "DateTime.h"
#include <ncurses.h>


UI::UI() {
    //definizione ncurses
    initscr();
    noecho();
    curs_set(0);
    cbreak();       

    //definizione dei colori
    start_color();
    init_color(COLOR_BLACK, 100, 0, 0);


    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);
    init_pair(6, COLOR_WHITE, COLOR_BLUE);
    init_pair(7, COLOR_YELLOW, COLOR_BLACK);
    init_pair(8, COLOR_CYAN, COLOR_BLACK);

    //creazione della finestra
    int mainWindowHeight = 8;
    int mainWindowWidth = 50;
    int mainWindowStartY= (getmaxy(stdscr) - mainWindowHeight)/4;
    int mainWindowStartX= (getmaxx(stdscr) - mainWindowWidth)/2;

    mainWindow = newwin(mainWindowHeight, mainWindowWidth, mainWindowStartY, mainWindowStartX);
    
    box(mainWindow, '8', '8');
    bkgd(COLOR_PAIR(6)); 
    wbkgd(mainWindow, COLOR_PAIR(1));
    nodelay(mainWindow, TRUE);
    wrefresh(mainWindow);

    //formato data predefinito
    datetime.setFormatEU();


}

UI::~UI() {
    if (mainWindow) {
        delwin(mainWindow);
    }
    endwin();
}


void UI::run() {
    while (true) {

        wclear(mainWindow);

        // divisore
        for(int i=0; i<getmaxx(mainWindow); i++) {
            textPrint(mainWindow, 0, i, "#", 8, A_BOLD);
            textPrint(mainWindow, getmaxy(mainWindow)-1, i, "#", 8, A_BOLD);
        }
        for(int i=1; i<getmaxy(mainWindow)-1; i++) {
            textPrint(mainWindow, i, 0, "|", 8, A_BOLD);
            textPrint(mainWindow, i, getmaxx(mainWindow)-1, "|", 8, A_BOLD);
        }


        int rigaData = 1;
        int rigaTimer = 5;
        int primaColonna = 2;
        int secondaColonna = primaColonna + 15;

        //sezione Data e Ora
        textPrint(mainWindow, rigaData, primaColonna, "Data & Ora", 2, A_BOLD);
        textPrint(mainWindow, rigaData+1, primaColonna, "Formato", 2, A_ITALIC);
        textPrint(mainWindow, rigaData, secondaColonna, datetime.printCurrent().c_str());

        textPrint(mainWindow, rigaData+1, secondaColonna, "(1)EU" );
        textPrint(mainWindow, rigaData+1, secondaColonna+10, "(2)ISO" );
        textPrint(mainWindow, rigaData+1, secondaColonna+20, "(3)USA" );

        if (datetime.getFormat() == getFormatEU()) {
            textPrint(mainWindow, rigaData+1, secondaColonna, "(1)EU", 2, A_BOLD );
        }
        if (datetime.getFormat() == getFormatISO()) {
            textPrint(mainWindow, rigaData+1, secondaColonna+10, "(2)ISO", 2, A_BOLD );
        }
        if (datetime.getFormat() == getFormatUSA()) {
            textPrint(mainWindow, rigaData+1, secondaColonna+20, "(3)USA", 2, A_BOLD );
        }


        //sezione Timer
        textPrint(mainWindow, rigaTimer, primaColonna, "Timer", 3, A_BOLD);
        textPrint(mainWindow, rigaTimer+1, primaColonna, "Azioni", 3, A_ITALIC);
        textPrint(mainWindow, rigaTimer, secondaColonna, countdown.secondsToString().c_str());


        //questa se usassi 3 stati mutualm esclusivi "running" "paused" "completed" funzionerebbe meglio?? avrei comunque bisogno di sapere secondi
        //devo comunque avere tre stati: running-->"stop"; !running&&seconds>0-->"start"; !running&&seconds=0-->"empty timer"
        if (countdown.isRunning()) {
            textPrint(mainWindow, rigaTimer+1, secondaColonna, "(S)top", 5, A_BOLD);
            textPrint(mainWindow, rigaTimer+1, secondaColonna+10, "(R)eset");
        } else {
            if (countdown.getSeconds() > 0) {
                textPrint(mainWindow, rigaTimer+1, secondaColonna, "(S)tart", 4, A_BOLD);
                textPrint(mainWindow, rigaTimer+1, secondaColonna+10, "(R)eset");
            }
            else {
                if (countdown.isComplete()) {
                    textPrint(mainWindow, rigaTimer+1, secondaColonna, "Complete",7 ,A_ITALIC);
                } else {
                    textPrint(mainWindow, rigaTimer+1, secondaColonna, "Empty Timer",0 ,A_ITALIC);
                }
                
            }
        }

        wrefresh(mainWindow); //refresh()

        handleInput();

        countdown.refreshTime();

        napms(50);
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

        case '1': datetime.setFormatEU(); break;
        case '2': datetime.setFormatISO(); break;
        case '3': datetime.setFormatUSA(); break;

    }
}


void UI::textPrint(WINDOW *window, int y, int x, const char *text, int color, chtype attributes) {
    if (attributes != A_NORMAL) {
        wattron(window, attributes);
    }
    if (color > 0) {
        wattron(window, COLOR_PAIR(color));
    }
    mvwprintw(window, y, x, "%s", text);
    if (attributes != A_NORMAL) {
        wattroff(window, attributes);
    }
    if (color > 0) {
        wattroff(window, COLOR_PAIR(color));
    }

}