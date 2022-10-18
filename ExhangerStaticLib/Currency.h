#pragma once
#include <string>

class Currency
{
public:
	Currency(std::string name, std::string code, double rate);
	std::string getName();
	std::string getCode();
	double getRate();
private:
	std::string _name;
	std::string _code;
	double _rate;
};
