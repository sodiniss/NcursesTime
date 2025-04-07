#include "DateTime.h"

#include <stdexcept>
#include <string>

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
}
void DateTime::setFormatISO() {
    format = getFormatISO();
}
void DateTime::setFormatUSA() {
    format = getFormatUSA();
}

const char* DateTime::getFormat() {
    return format;
}

DateTime::DateTime() {
    setFormatEU(); //default
    now();
}

DateTime::DateTime(int day, int month, int year, int h, int m, int s) {
    format = getFormatEU(); // default

    tm original = {0};  //init
    original.tm_year = year - 1900;
    original.tm_mon  = month - 1;
    original.tm_mday = day;
    original.tm_hour = h;
    original.tm_min  = m;
    original.tm_sec  = s;

    //copia per mktime per evitare che modifichi original
    tm temp = original;

    time_t timestamp = mktime(&temp);
    if (timestamp == -1)
        throw std::invalid_argument("Data non valida");

    tm newstruct = *localtime(&timestamp);

    bool unchanged =
        original.tm_year == newstruct.tm_year &&
        original.tm_mon  == newstruct.tm_mon  &&
        original.tm_mday == newstruct.tm_mday &&
        original.tm_hour == newstruct.tm_hour &&
        original.tm_min  == newstruct.tm_min  &&
        original.tm_sec  == newstruct.tm_sec;

    if (!unchanged)
        throw std::invalid_argument("Data non valida");

    dtstruct = newstruct;
}


void DateTime::now() {
    time_t timestamp = time(nullptr);
    dtstruct = *localtime(&timestamp);
}

std::string DateTime::printCurrent() {
    now();
    return toString();
}

std::string DateTime::toString() {
    char buffer[30];
    strftime(buffer, sizeof(buffer), format, &dtstruct);
    return std::string(buffer);
}

