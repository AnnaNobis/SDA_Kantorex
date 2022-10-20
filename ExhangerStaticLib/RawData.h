#pragma once
#include <vector>
#include "../JSONLib/JSONReader.h"

class RawData
{
	std::vector<Currency> rawDataVector;
public:

	RawData();
	std::vector<Currency> getRawData();

};
