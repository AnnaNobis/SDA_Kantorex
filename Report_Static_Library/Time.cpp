#include "pch.h"
#include "Time.hpp"

Time::Time(RawDate inputObject)
{
    std::string str2 = inputObject.getDate();

    std::string hours = "";
    for (int i = 0; i < 2; ++i)
    {
        hours += str2[i + 11];
    }
    std::string minutes = "";
    for (int i = 0; i < 2; ++i)
    {
        minutes += str2[i + 14];
    }
    std::string seconds = "";
    for (int i = 0; i < 2; ++i)
    {
        seconds += str2[i + 17];
    }
    _time.append(hours);
    _time.append(":");
    _time.append(minutes);
    _time.append(":");
    _time.append(seconds);
}

std::string Time::get_time()
{
    return _time;
}
