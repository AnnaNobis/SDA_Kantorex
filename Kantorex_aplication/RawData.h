#pragma once
#include <vector>
#include "Currency.h"
#include "../JasonReader/JsonReader.h"

class RawData
{
	JsonReader dataFromFile;
	std::vector<Currency> rawDataVector;
public:
	RawData() {
		rawDataVector = dataFromFile.readCurrencies();
	}
	std::vector<Currency> getRawData() {
		return rawDataVector;
	};
};
