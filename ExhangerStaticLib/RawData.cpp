#include "pch.h"
#include "RawData.h"

RawData::RawData()
{
	rawDataVector = dataFromFile.readCurrencies();
}

std::vector<Currency> RawData::getRawData()
{
	return rawDataVector;
};