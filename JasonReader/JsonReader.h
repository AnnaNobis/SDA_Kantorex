#pragma once
#include <iostream>
#include "json.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "../Kantorex_aplication/Currency.h"

class JsonReader
{
public:
	std::vector<Currency> readCurrencies(std::string file = "JSONTabelaA.json");
	void wypisz();
};
