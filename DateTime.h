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

#endif
