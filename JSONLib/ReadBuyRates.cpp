#include "ReadBuyRates.h"
#include <iostream>
#include <fstream>
#include "json/json.hpp"
using json = nlohmann::ordered_json;

std::string ReadBuyRates::filePath = "TabelaC.json";

std::map<std::string, double> ReadBuyRates::read()
{
	std::ifstream ifs(filePath);
	json j;

	if (!ifs.is_open())
	{
		std::cout << "Nie udalo sie wczytac z pliku" << std::endl;
	}
	ifs >> j;
	ifs.close();

	std::map<std::string, double> buyRates;
	std::string code;
	double rate;

	for (auto& element : j) {
		for (auto& elem : element["rates"]) {
			code = elem["code"];
			rate = elem["bid"];
			buyRates.insert({ code, rate });
		}
	}

	//for (auto& el : buyRates) {
	//	std::cout << "Kod: " << el.first << "  |  Cena: " << el.second << std::endl;
	//}
	return buyRates;

}

