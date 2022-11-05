#include "pch.h"
#include "CashBalance.h"
#include "../JSONLib/RawData.h"
#include "../JSONLib/Currency.h"

CashBalance::CashBalance() {
	createMapp();
}
void CashBalance::createMapp()
{
	RawData rawData2;
	auto data2 = rawData2.getRawData();
	std::for_each(data2.begin(), data2.end(), [&](Currency c) {
		balanceMap.insert({ c.getCode(), 10000 }); });
	balanceMap.insert({ "PLN",100000 });
}
void CashBalance::showBalance()
{
	for (auto& elem : balanceMap)
	{
		std::cout << elem.first << " " << elem.second << " " << std::endl;
	};
}
bool CashBalance::checkCashRegister(float exchangedCash, std::string finalCurrency)
{
	float value;
	value = balanceMap.at(finalCurrency);
	if (value > exchangedCash)
	{
		return true;
	};
}

float CashBalance::getAmountOfCurrency(std::string currency)
{
	return balanceMap.at(currency);
	
}

void CashBalance::updateBalance(std::string currency, float inputCash, float exchangedCash, std::string finalCurrency)
{
	float value1;
	float value2;
	float result1;
	float result2;
	//10 000 = createdMap.at("USD");
	//auto result2 = 10 000 -
	value1 = balanceMap.at(currency);
	value2 = balanceMap.at(finalCurrency);
	result1 = value1 + inputCash;
	result2 = value2 - exchangedCash;
	balanceMap.at(currency) = result1;
	balanceMap.at(finalCurrency) = result2;

}


std::map<std::string, float>CashBalance::getBalanceMap()
{
	return balanceMap;
}

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
//CashBalance::CashBalance(OperationSellBuy chooseOperation, std::string inputCurrencyFrom, float inputAmount, std::string inputCurrencyTo)
//	:  _sellBuy(chooseOperation),
//	   _inputCurrencyFrom(inputCurrencyFrom),
//	   _inputAmount(inputAmount),
//       _inputCurrencyTo(inputCurrencyTo)
//{
//	balance = std::make_shared<Exchanger>();
//}
