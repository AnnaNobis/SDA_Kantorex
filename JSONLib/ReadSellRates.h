#pragma once
#include <map>
#include <string>
class ReadSellRates
{
	//static std::string filePath;
public:
	ReadSellRates();
	std::map<std::string, double> read(std::string path);

};

