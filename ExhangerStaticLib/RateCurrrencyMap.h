#pragma once
#include <map>
#include <string>
#include <algorithm>
#include "../JSONLib/RawData.h"

class RateCurrencyMap
{
public:
	std::map<std::string, float> createMapCodeRate();
};
