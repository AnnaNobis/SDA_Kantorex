#pragma once
#include <vector>
#include "Currency.h"
#include "JsonReader.h"

class RawData
{
	JsonReader dataFromFile;
	std::vector<Currency> rawDataVector;
public:
	RawData();
	std::vector<Currency> getRawData();
};
