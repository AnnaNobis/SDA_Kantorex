#pragma once
#include <string>
#include "RawDate.hpp"

class Time
{
	std::string _time = "";
public:
	Time(RawDate inputObject);
	Time() {};
	std::string get_time();
};