#pragma once
#include <vector>
#include "Currency.h"
#include "JSONReader.h"
class RawData
{
	JSONReader dataFromFile;
	std::vector<Currency> rawDataVector;
public:
	RawData() {
		rawDataVector = dataFromFile.readCurrencies();
	}
	std::vector<Currency> getRawData() {
		return rawDataVector;
	};
};

