#pragma once
#include "../JSONLib/ReadSellRates.h"
class SellRate
{
	std::map<std::string, float> sellRates;
public:
	SellRate();
	std::map<std::string, float> getSellRates() {
		return sellRates;
	}
};