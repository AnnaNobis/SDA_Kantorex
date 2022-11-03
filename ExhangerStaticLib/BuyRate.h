#pragma once
#include "../JSONLib/ReadBuyRates.h"
class BuyRate
{
	std::map<std::string, float> buyRates;
public:
	BuyRate();
	std::map<std::string, float> getBuyRates() {
		return buyRates;
	}
};