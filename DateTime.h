#ifndef DATETIME_H
#define DATETIME_H
#include <ctime>
#include <string>


const char* getFormatEU();
const char* getFormatISO();
const char* getFormatUSA();


class DateTime {
private:
    const char* format;
    struct tm dtstruct;

public:
    DateTime();
    DateTime(int day, int month, int year, int h, int m, int s); //solo per test

    const char* getFormat();

    void setFormatEU(); 
    void setFormatISO(); 
    void setFormatUSA(); 

    void now(); //aggiorna struct all'ora attuale
    std::string printCurrent(); //stampa facendo prima un now()
    std::string toString(); //stampa (solo usato nei test)
};

#endif
