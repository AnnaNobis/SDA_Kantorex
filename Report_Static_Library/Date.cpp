#include "pch.h"
#include "Date.hpp"
#include <map>
#include <string>
Date::Date(RawDate inputObject)
{
    std::string str2 = inputObject.getDate();

    std::string day ="";
    for (int i = 0; i < 2; ++i)
    {
        day += str2[i + 8];
    }

    std::string month="";
    for (int i = 0; i < 3; ++i)
    {
        month += str2[i + 4];
    }

    std::string year="";

    for (int i = 0; i < 4; ++i)
    {
        year += str2[i + 20];
    }
    
    _date.append(day);
    _date.append(".");
    _date.append(get_month_index(month));
    _date.append(".");
    _date.append(year);


    
}
std::string Date::get_month_index(std::string name)
{

    std::map<std::string, std::string> months
    {
        { "Jan", "1" },
        { "Feb", "2" },
        { "Mar", "3" },
        { "Apr", "4" },
        { "May", "5" },
        { "Jun", "6" },
        { "Jul", "7" },
        { "Aug", "8" },
        { "Sep", "9" },
        { "Oct", "10" },
        { "Nov", "11" },
        { "Dec", "12" }
    };

    const auto iter = months.find(name);

    if (iter != months.cend())
        return iter->second;
    return "-1";
}

std::string Date::get_date()
{
    return _date;
}
