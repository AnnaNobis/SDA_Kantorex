//#include "pch.h"
#include "CalculatorCurrency.h"
#include <algorithm>

CalculatorCurrency::CalculatorCurrency(std::string transaction)
{
	if (transaction == "buy")
	{
		Buy buy;

	}
	else
	{
		Sell sell;

	}

	//std::cin >> _currency; 

	//std::cout << "Podaj kwote któr¹ chcesz wymieniæ";
	//std::cin >> _amount;
	
	//std::cout << "Podaj walute na któr¹ chcesz wymieniæ";
	//std::cin >>  _currencyFrom;

}
//
//std::map<std::string, float> CalculatorCurrency::createMapCodeRate() // z vectora robie mape <Key USD, Value 0,15>; 
//{
//	RawData rawData; 
//	auto data = rawData.getRawData();
//	std::map<std::string, float>currencyAndRate;
//
//	std::for_each(data.begin(), data.end(), [&](Currency c) {
//		currencyAndRate.insert({ c.getCode(), c.getRate() }); });
//
//	return currencyAndRate;
//}




float CalculatorCurrency::getSpread()
{
	return _spread;
}

void CalculatorCurrency::setSpread(float spread)
{
	spread = _spread;
}


float CalculatorCurrency::Exchange()
{
	float amountAfterExchange = getSpread() * _amount * getRate();
	return amountAfterExchange;
}



//float CalculatorCurrency::Exchange()
//{
//	float multiplier = ChoosenCurrency();
//	return _amount * multiplier*(1 + _spread);
//}
//
//
//float CalculatorCurrency::ChoosenCurrency()
//{
//	float result = 0; 
//  _currencyFrom == "pln")
//	{
//		result = 0,21 ;
//	}
//
//	return result;
//}
//
//float& CalculatorCurrency::UpdateBalace()
//{
//	float amountFromChashBalance = 
//	-Exchange()
//	return 
//	// TODO: tu wstawiæ instrukcjê return
//}
//
//std::string CalculatorCurrency::txtCalculatorBase()
//{
//	return std::string();
//}
