#pragma once
#include <iostream>
#include "json/json.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Currency.h"
class JSONReader
{
public:
	std::vector<Currency> readCurrencies(std::string file = "JSONTabelaA.json");
	void wypisz();
};