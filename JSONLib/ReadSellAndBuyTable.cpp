#include "ReadSellAndBuyTable.h"
#include "json/json.hpp"
#include <fstream>
#include <iostream>
using json = nlohmann::ordered_json;
//TODO podac ostateczna sciezke pliku
std::string ReadSellAndBuyTable::filePath = "TabelaC.json";

std::vector<CodeBuySellRate> ReadSellAndBuyTable::read()
{
	std::ifstream ifs(filePath);
	json j;

	if (!ifs.is_open())
	{
		std::cout << "Nie udalo sie wczytac z pliku" << std::endl;
	}
	ifs >> j;
	ifs.close();

	std::vector<CodeBuySellRate> sellBuyRates;
	std::string code;
	float rateBuy;
	float rateSell;

	for (auto& element : j) {
		for (auto& elem : element["rates"]) {
			code = elem["code"];

			rateBuy = elem["bid"];
			auto sRateBuy = std::to_string(rateBuy);

			rateSell = elem["ask"];
			auto sRateSell = std::to_string(rateSell);

			sellBuyRates.emplace_back(code, sRateBuy, sRateSell);

			//sellBuyRates.emplace_back(code);
			//sellBuyRates.emplace_back(sRateBuy);
			//sellBuyRates.emplace_back(sRateSell);

		}

	}


	return sellBuyRates;

}





