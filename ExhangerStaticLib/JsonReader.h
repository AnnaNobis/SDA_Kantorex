#pragma once
#include <iostream>
#include "../JSONLib/json/json.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Currency.h"

class JsonReader
{
public:
	std::vector<Currency> readCurrencies (std::string file = "JSONTabelaA");
	void wypisz();
};
