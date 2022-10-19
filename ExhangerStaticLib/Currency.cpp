#include "pch.h"
#include "Currency.h"

Currency::Currency(std::string name, std::string code, double rate)
	:
	_name(name),
	_code(code),
	_rate(rate) {};

std::string Currency::getName() {
	return _name;
};
std::string Currency::getCode() {
	return _code;
};
double Currency::getRate() {
	return _rate;
};