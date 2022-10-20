#include "pch.h"
#include "RawData.h"

RawData::RawData()
{
	JSONReader dataFromFile;
	rawDataVector = dataFromFile.readCurrencies("JSONTabelaA.json");
}

std::vector<Currency> RawData::getRawData()
{
	return rawDataVector;
}