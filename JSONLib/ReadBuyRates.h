#pragma once
#include <map>
#include <string>

class ReadBuyRates
{
static std::string filePath;
public:
	ReadBuyRates();
	std::map<std::string, double> read();
};

