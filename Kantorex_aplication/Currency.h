
#pragma once
#include <string>
class Currency
{
public:
	Currency(std::string name, std::string code, double rate)
		:
		_name(name),
		_code(code),
		_rate(rate) {};
	std::string getName() {
		return _name;
	};
	std::string getCode() {
		return _code;
	};
	double getRate() {
		return _rate;
	};
private:
	std::string _name;
	std::string _code;
	double _rate;
};
