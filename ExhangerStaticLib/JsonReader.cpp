#include "pch.h"
#include "JsonReader.h"

using json = nlohmann::ordered_json;

std::vector<Currency> JsonReader::readCurrencies(std::string file)
{
	std::ifstream ifs(file);
	json j;

	if (!ifs.is_open())
	{
		std::cout << "Nie udalo sie wczytac z pliku" << std::endl;
	}
	ifs >> j;
	ifs.close();

	std::vector<Currency> dataBaseCurrencies;
	std::string name;
	std::string code;
	double rate;

	for (auto& element : j) {
		for (auto& elem : element["rates"]) {
			name = elem["currency"];
			code = elem["code"];
			rate = elem["mid"];
			dataBaseCurrencies.emplace_back(name, code, rate);
		}
	}
	return dataBaseCurrencies;
}

void JsonReader::wypisz()
{
	std::vector<Currency> temp = readCurrencies("JSONTabelaA.json");
	std::for_each(temp.begin(), temp.end(), [](Currency c) { std::cout << c.getName() << " " << c.getCode() << " " << c.getRate() << std::endl; });
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << temp.at(2).getName() << " " << temp.at(2).getCode() << " " << temp.at(2).getRate() << std::endl;
}