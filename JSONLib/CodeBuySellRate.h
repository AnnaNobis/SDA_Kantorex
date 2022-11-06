#pragma once
#include <string>

class CodeBuySellRate
{
public:
	std::string _code;
	std::string _rateBuy;
	std::string _rateSell;
	CodeBuySellRate(std::string code, std::string rateB, std::string rateS);
};