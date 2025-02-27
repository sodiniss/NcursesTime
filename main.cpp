#include <ncurses.h>
#include <cstring>
#include "UI.h"

#include <iostream>
#include "DateTime.h"

//using namespace std;

#define STRINGA_TEST "Ciao dal terminale ncurses!"

int main() {
    UI ui;
    ui.run();
    return 0;
    //std::cout << "Ora " << getDateISO() << std::endl;

}
