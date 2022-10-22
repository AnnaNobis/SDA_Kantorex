#include "ReadBuyRates.h"
#include <iostream>
#include <fstream>
#include "json/json.hpp"
using json = nlohmann::ordered_json;
//TODO podac ostateczna sciezke pliku
std::string ReadBuyRates::filePath = "TabelaC.json";

std::map<std::string, float> ReadBuyRates::read()
{
	std::ifstream ifs(filePath);
	json j;

	if (!ifs.is_open())
	{
		std::cout << "Nie udalo sie wczytac z pliku" << std::endl;
	}
	ifs >> j;
	ifs.close();

	std::map<std::string, float> buyRates;
	std::string code;
	double rate;

	for (auto& element : j) {
		for (auto& elem : element["rates"]) {
			code = elem["code"];
			rate = elem["bid"];
			std::cout << code << "  |  " << rate << std::endl;
			buyRates.insert({ code, rate });
		}
	}
	

	return buyRates;

}

void ReadBuyRates::changePath(std::string newPath)
{
	filePath = newPath;
}
