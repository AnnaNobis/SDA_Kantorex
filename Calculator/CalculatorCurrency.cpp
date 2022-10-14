//#include "pch.h"
#include "CalculatorCurrency.h"
#include <algorithm>

CalculatorCurrency::CalculatorCurrency(std::string buyOrSell): _spread(0.00), _amount(0.00)
{
	//ITransaction* transaction=nullptr;  //sprawdz czy nullptr nie robi bledu

	std::shared_ptr<ITransaction> transaction = std::make_shared<ITransaction>(transaction);

	if (buyOrSell == "buy")
	{
		transaction = std::shared_ptr<Buy>(new Buy());
	}
	else 
	{
		transaction = std::shared_ptr<Sell>(new Sell());
	}

	transaction->setSpread(_spread);
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
