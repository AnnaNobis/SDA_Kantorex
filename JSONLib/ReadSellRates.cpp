#include "ReadSellRates.h"
#include "json/json.hpp"
#include <fstream>
#include <iostream>
using json = nlohmann::ordered_json;

//std::string ReadSellRates::filePath = "TabelaC.json";

std::map<std::string, double> ReadSellRates::read(std::string path)
{
	std::ifstream ifs(path);
	json j;

	if (!ifs.is_open())
	{
		std::cout << "Nie udalo sie wczytac z pliku" << std::endl;
	}
	ifs >> j;
	ifs.close();

	std::map<std::string, double> sellRates;
	std::string code;
	double rate;

	for (auto& element : j) {
		for (auto& elem : element["rates"]) {
			code = elem["code"];
			rate = elem["ask"];
			sellRates.insert({ code, rate });
		}
	}

	for (auto& el : sellRates) {
		std::cout << "Kod: " << el.first << "  |  Cena: " << el.second << std::endl;
	}
	return sellRates;

}

ReadSellRates::ReadSellRates() {
}


