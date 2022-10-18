#include "pch.h"
#include "RateCurrrencyMap.h"
#include "Currency.h"

std::map<std::string, float> RateCurrencyMap::createMapCodeRate()
{
	RawData rawData;
	auto data = rawData.getRawData();
	std::map<std::string, float>currencyAndRate;

	std::for_each(data.begin(), data.end(), [&](Currency c) {
		currencyAndRate.insert({ c.getCode(), c.getRate() }); });

	return currencyAndRate;
}
