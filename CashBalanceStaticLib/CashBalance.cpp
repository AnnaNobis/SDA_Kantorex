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
//CashBalance::CashBalance(OperationSellBuy chooseOperation, std::string inputCurrencyFrom, float inputAmount, std::string inputCurrencyTo)
//	:  _sellBuy(chooseOperation),
//	   _inputCurrencyFrom(inputCurrencyFrom),
//	   _inputAmount(inputAmount),
//       _inputCurrencyTo(inputCurrencyTo)
//{
//	balance = std::make_shared<Exchanger>();
//}
std::map<std::string, float> CashBalance::createMapp()
{
	RawData rawData2;
	auto data2 = rawData2.getRawData();
	std::map<std::string, float>currencyAndAmount;
	std::for_each(data2.begin(), data2.end(), [&](Currency c) {
		currencyAndAmount.insert({ c.getCode(), 10000 }); });
	currencyAndAmount.insert({ "PLN",100000 });
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
bool CashBalance::checkCashRegister()
{
	float value;
	auto createdMap = createMapp();
	value = createdMap.at(balance->getCurrencyForBalance());
	if (value > balance->getExchangedAmount())
	{
		return true;
	};
}
void CashBalance::updateBalance()
{
	float value;
	auto createdMap = createMapp();
	//10 000 = createdMap.at("USD");
	//auto result2 = 10 000 -
	value = createdMap.at(balance->getCurrencyForBalance());
	auto result1 = value + (balance->getAmountForBalance());
	auto result2 = value - (balance->getExchangedAmount());
	createdMap[balance->getCurrencyForBalance()] = result1;
	//USD = 10 200
	std::map<std::string, float>::iterator it = createdMap.find(balance->getCurrencyForBalance());
	if (it != createdMap.end())
	{
		it->second = result2;
	}
}

