#pragma once
#include <map>
#include <string>
class ReadSellRates
{
	static std::string filePath;
public:
	std::map<std::string, double> read();

};

