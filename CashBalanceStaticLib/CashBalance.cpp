#include "pch.h"
#include "CashBalance.h"


//float CashBalance::setBalance(int howMuch, std::string input)
//{
//	bool end = false;
//	std::string waluta;
//
//	while (!end)
//	{
//		std::cout << "Dodaj walutę do kasy [napisz end, zeby zakonczyc]:";
//		std::getline(std::cin, input);
//		if (input == "end")
//		{
//			end = true;
//			break;
//		}
//		waluta = input;
//		std::cout << "Podaj wartość waluty: ";
//		std::getline(std::cin, input);
//		howMuch = std::stoi(input);
//
//		auto it = _cashRegister.find(waluta);
//		if (it == _cashRegister.end())
//		{
//			_cashRegister.emplace(waluta, howMuch);
//		}
//		else
//		{
//			std::cout << "Ta waluta już znajduje się w CashBalance" << std::endl;
//			std::cout << "Podaj + jesli chcesz zsumowac" << std::endl;
//			std::cout << "Podaj * jesli chcesz zachowac stara wartosc" << std::endl;
//			std::cout << "Podaj = jesli chcesz zachowac nowa wartosc" << std::endl;
//			std::cout << "Podaj wybrana opcje:";
//			std::getline(std::cin, input);
//			if (input == "+")
//			{
//				it->second += howMuch;
//			}
//			else if (input == "*")
//			{
//
//			}
//			else if (input == "=")
//			{
//				it->second = howMuch;
//			}
//			else
//			{
//				std::cout << "Nieprawidlowa opcja" << std::endl;
//			}
//		}
//	}
//	std::cout << "CashBalance:" << std::endl;
//	std::for_each(_cashRegister.begin(), _cashRegister.end(), [](std::pair<std::string, int>& listItem) {
//		std::cout << "- " << listItem.first << " : " << listItem.second << std::endl;
//		});
//}

std::map<std::string, float> CashBalance::createMapp()
{
	RawData rawData2;
	auto data2 = rawData2.getRawData();
	std::map<std::string, float>currencyAndAmount;

	std::for_each(data2.begin(), data2.end(), [&](Currency c) {
		currencyAndAmount.insert({ c.getCode(), 10000 }); });

	return currencyAndAmount;
}

void CashBalance::showOpeningBalance()
{
	auto createdMapa = createMapp();
	
	for (auto& elem : createdMapa)
	{
		std::cout << elem.first << " " << elem.second << " " << std::endl;
	};
}
