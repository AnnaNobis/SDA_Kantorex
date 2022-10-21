#pragma once
#include <map>
#include <string>

class ReadBuyRates
{
static std::string filePath;
public:
	std::map<std::string, double> read();
	void changePath(std::string newPath);
};

