#pragma once
#include <map>
#include <string>
class ReadSellRates
{
	static std::string filePath;
public:
	std::map<std::string, float> read();
	void changePath(std::string newPath);

};

