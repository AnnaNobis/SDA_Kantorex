#pragma once
#include <string>
#include "RawDate.hpp"

class Date {
	std::string _date = "";
public:
	Date(RawDate inputObject);
	std::string get_month_index(std::string name);
	std::string get_date();
	
};