#ifndef DATETIME_H
#define DATETIME_H

#include <string>

std::string formatDate(const char* format);

const char* getFormatEU();
const char* getFormatISO();
const char* getFormatUSA();

//questi ora non li uso ma li lascio
std::string getDateEU();
std::string getDateISO();
std::string getDateUSA();


class DateTime {
private:
    const char* format;
    std::string dateTime;

public:
    DateTime();
    DateTime(int day, int month, int year, int h, int m, int s);

    const char* getFormat();

    void setFormatEU(); 
    void setFormatISO(); 
    void setFormatUSA(); 

    void now();
    std::string printCurrent();
    std::string toString();
};

#endif
