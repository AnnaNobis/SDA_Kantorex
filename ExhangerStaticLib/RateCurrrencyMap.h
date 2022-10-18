#pragma once
#include "RawData.h"
#include "Currency.h"
#include <map>
#include <string>

class RateCurrencyMap
{
public:
	std::map<std::string, float>createMapCodeRate();

};
