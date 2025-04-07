#ifndef DATETIME_H
#define DATETIME_H

#include <string>


const char* getFormatEU();
const char* getFormatISO();
const char* getFormatUSA();


class DateTime {
private:
    const char* format;
    std::string dateTime;

public:
    DateTime();
    DateTime(int day, int month, int year, int h, int m, int s); //solo per test

    const char* getFormat();

    void setFormatEU(); 
    void setFormatISO(); 
    void setFormatUSA(); 

    void now(); //aggiorna dateTime all'ora attuale
    std::string printCurrent(); //stampa facendo prima un now()
    std::string toString(); //stampa (solo test)
};

#endif
