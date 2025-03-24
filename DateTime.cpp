#include "DateTime.h"
#include <ctime>
#include <stdexcept>
#include <string>

std::string formatDate(const char* format) {
    time_t timestamp = time(nullptr);
    struct tm datetime = *localtime(&timestamp);
    char buffer[30];
    strftime(buffer, sizeof(buffer), format, &datetime); //da cambiare se vuoi usare WINDOW??
    return std::string(buffer);
}

const char* getFormatEU() {
    return "%d/%m/%Y, %H:%M:%S";
}
const char* getFormatISO() {
    return "%Y/%m/%d, %H:%M:%S";
}
const char* getFormatUSA() {
    return "%m/%d/%Y, %I:%M:%S %p";
}

void DateTime::setFormatEU() {
    format = getFormatEU();
    //format = "%d/%m/%Y, %H:%M:%S";
}
void DateTime::setFormatISO() {
    format = getFormatISO();
    //format = "%Y/%m/%d, %H:%M:%S";
}
void DateTime::setFormatUSA() {
    format = getFormatUSA();
    //format = "%m/%d/%Y, %I:%M:%S %p";
}


std::string getDateEU() {
    return formatDate(getFormatEU());
}

std::string getDateISO() {
    return formatDate(getFormatISO());
}

std::string getDateUSA() {
    return formatDate(getFormatUSA());
}

const char* DateTime::getFormat() {
    return format;
}

DateTime::DateTime() {
    format = getFormatEU(); //default

    time_t timestamp = time(nullptr);
    struct tm dtstruct = *localtime(&timestamp);
    char buffer[30];
    strftime(buffer, sizeof(buffer), format, &dtstruct);

    dateTime = std::string(buffer);
}

DateTime::DateTime(int day, int month, int year, int h, int m, int s) {
    format = getFormatEU(); //default

    struct tm dtstruct = {0}; // init
    dtstruct.tm_year = year - 1900;
    dtstruct.tm_mon = month - 1;    //gennaio= 0 
    dtstruct.tm_mday = day;
    dtstruct.tm_hour = h;
    dtstruct.tm_min = m;
    dtstruct.tm_sec = s;
    
    time_t timestamp = mktime(&dtstruct);  //corregge date non valide
    if (timestamp == -1) //se data non valida da -1
        throw std::invalid_argument("Data non valida");

    dtstruct = *localtime(&timestamp);
    char buffer[30];
    strftime(buffer, sizeof(buffer), format, &dtstruct);

    dateTime = std::string(buffer);
}


void DateTime::update() {

}

std::string DateTime::print() {
    return dateTime;
}

std::string DateTime::toString() {

}

