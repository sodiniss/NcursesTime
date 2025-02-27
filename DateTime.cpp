#include "DateTime.h"
#include <ctime>

std::string formatDate(const char* format) {
    time_t timestamp = time(nullptr);
    struct tm datetime = *localtime(&timestamp);
    char buffer[30];
    strftime(buffer, sizeof(buffer), format, &datetime); //da cambiare se vuoi usare WINDOW
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


std::string getDateEU() {
    return formatDate(getFormatEU());
}

std::string getDateISO() {
    return formatDate(getFormatISO());
}

std::string getDateUSA() {
    return formatDate(getFormatUSA());
}