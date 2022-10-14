#include "mapOfRateAndCurrency.h"

std::map<std::string, float> mapOfRateAndCurrency::createMapCodeRate()
{
	RawData rawData;
	auto data = rawData.getRawData();
	std::map<std::string, float>currencyAndRate;

	std::for_each(data.begin(), data.end(), [&](Currency c) {
		currencyAndRate.insert({ c.getCode(), c.getRate() }); });

	return currencyAndRate;
}
