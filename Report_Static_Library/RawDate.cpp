#include "pch.h"
#include "RawDate.hpp"

RawDate::RawDate()
{
    time_t result = time(NULL);
    //printf("%s", ctime(&result));
    char str[26];
    ctime_s(str, sizeof str, &result);
    
    _str = str;
}

std::string RawDate::getDate()
{
    return _str;
}

void RawDate::printDate()
{
    std::cout<< _str;
}
